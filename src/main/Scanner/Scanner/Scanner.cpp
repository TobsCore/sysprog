#include "Scanner.h"
#include "../Token/IdentifierToken.h"
#include "../Token/IntegerToken.h"
#include "../Token/ErrorToken.h"
#include "../Token/WhileToken.h"
#include "../Token/IfToken.h"
#include "../../String/StringOp.h"
#include "../Token/IntToken.h"
#include "../Token/WriteToken.h"
#include "../Token/ReadToken.h"
#include "../Token/ElseToken.h"
#include <climits>

Scanner::Scanner(char const *filePath) {

    this->automat = new Automat();
    this->buffer = new Buffer(filePath);
    nextTokenPosition = new Position(1, 1);
    currentTokenPosition = new Position(1, 1);
    currentPosition = new Position(1, 1);
    symboltable = new SymbolTable();
    firstToken = true;
    isInComment = false;
    commentCounter = 0;

    countSpace = 0;
    countChars = 0;

    lexem = new char[bufferSize];
    i = 0;
}

Scanner::~Scanner() {
    delete buffer;
    delete automat;
    delete symboltable;
    delete nextTokenPosition;
    delete currentTokenPosition;
    delete currentPosition;
    delete[] lexem;
}

Token *Scanner::nextToken() {
    Token *nextToken;

    if (!buffer->hasNext()) {
        nextToken = new Token();
        nextToken->setType(FILE_END);
        return nextToken;
    }


    SymbolType symbol;
    do {
        char nextChar = buffer->getChar();
        symbol = automat->checkExpression(nextChar);
        checkInComment(symbol);
        setCurrentPosition(nextChar);
        if ((nextChar >= '0' && nextChar <= '9')
            || (nextChar >= 'a' && nextChar <= 'z')
            || (nextChar >= 'A' && nextChar <= 'Z')) {
            lexem[i] = nextChar;
            i++;
        }
        if (symbol == COMMENT) {
            // Für die korreket Positionierung, muss diese Methode aufgerufen werden, weil wir jetzt ja kein Comment
            // Token mehr zurück geben.
            i = 0;
            tokenPosition();
        }
    } while ((symbol == NEXTCHAR || symbol == IN_COMMENT || symbol == COMMENT) && buffer->hasNext() && i < bufferSize - 1);

    // Identifier too long
    if (i >= bufferSize - 1) {
        symbol = ERROR;
    }

    // If a symbol has a NEXTCHAR, this means that the loop has quit because there's no other character in the buffer.
    // This equals to an EOF, which should be returned.a
    if (symbol == NEXTCHAR) {
        symbol = FILE_END;
    }

    // If the scanner suspeced the token to be a special token, but it turned out it wasn't, the scanner will move
    // back in the buffer and set the current symbol to an equals sign, which is the first symbol of the special sign.
    if (symbol == ERROR_SPECIAL) {
        symbol = EQUALS;
        buffer->ungetChar(1);
        currentPosition->incCol(-1);
    }
    Position *nextTokenPosition = tokenPosition();

    switch (symbol) {
        case IDENTIFIER: {
            lexem[i] = '\0';
            nextToken = new IdentifierToken(symboltable->insert(lexem));
            i = 0;
            break;
        }
        case INTTOKEN: {
            nextToken = new IntToken();
            i = 0;
            break;
            }
        case INTEGER: {
            lexem[i] = '\0';
            char *conversionResult;
            long integerValue = strtol(lexem, &conversionResult, 10);

            if ((integerValue == LONG_MIN || integerValue == LONG_MAX) && errno == ERANGE) {
                //Value out of range
                nextToken = new ErrorToken();
                static_cast<ErrorToken *>(nextToken)->setInfo("Integer out of range");
            } else {
                // Conversion was successful
                nextToken = new IntegerToken();
                static_cast<IntegerToken *>(nextToken)->setValue(integerValue);
            }
            i = 0;
            break;
        }
        case ERROR: {
            nextToken = new ErrorToken();
            if (i >= bufferSize - 1) {
                lexem = const_cast<char *>("Identifier too long");
                static_cast<ErrorToken *>(nextToken)->setInfo(lexem);
            }
            lexem = new char[bufferSize];
            i = 0;
            break;
        }
        case WHILETOKEN: {
            nextToken = new WhileToken();
            i = 0;
            break;
        }
        case IFTOKEN: {
            nextToken = new IfToken();
            i = 0;
            break;
        }
        case WRITETOKEN: {
            nextToken = new WriteToken();
            i = 0;
            break;
        }
        case READTOKEN: {
            nextToken = new ReadToken();
            i = 0;
            break;
        }
        case ELSETOKEN: {
            nextToken = new ElseToken();
            i = 0;
            break;
        }
        case COMMENT: {
            i = 0;
        }
        default: {
            nextToken = new Token();
            nextToken->setType(symbol);
        }
    }

    nextToken->setPosition(nextTokenPosition);
    return nextToken;
}

void Scanner::checkInComment(const SymbolType &symbol) {
    if (symbol == IN_COMMENT) {
        isInComment = true;
    } else if (symbol == COMMENT) {
        isInComment = false;
    }
}

void Scanner::setCurrentPosition(char c) {
    if (c == ' ' || c == '\t') {
        currentPosition->incCol();
        if (!isInComment) {
            countSpace += 1;
        }
    } else if (c == '\n') {
        currentPosition->incRow();
        currentPosition->resetCol();
        countSpace += 1;
    } else {
        currentPosition->incCol();
        countChars += 1;
    }
}

Position *Scanner::tokenPosition() {
    int row = currentPosition->getRow();
    int col = currentPosition->getCol();

    int offset = countSpace < 2 ? 0 : countSpace - 1;
    int rowOffset = 0;
    if (row >= nextTokenPosition->getRow() && col > 1) {
        rowOffset = row - nextTokenPosition->getRow();
    }
    currentTokenPosition->setCol(nextTokenPosition->getCol() + offset);
    currentTokenPosition->setRow(nextTokenPosition->getRow() + rowOffset);

    nextTokenPosition->setCol(col + countSpace - 1);
    nextTokenPosition->setRow(row);

    countSpace = 0;

    return currentTokenPosition;
}
