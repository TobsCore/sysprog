#include "Scanner.h"
#include "../../Token/IdentifierToken.h"
#include "../../Token/IntegerToken.h"

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
}

Scanner::~Scanner() {
	delete buffer;
	delete automat;
	delete symboltable;
	delete nextTokenPosition;
	delete currentTokenPosition;
	delete currentPosition;
}

Token* Scanner::nextToken() {
    Token *nextToken;

    char *lexem = new char[255];
    int i = 0;

    // If no other characters can be read, return and EOF-Token. This can be used to stop the calling loop.
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
        setCurrentPosition(nextChar, symbol);
        lexem[i] = nextChar;
        i++;
	} while ((symbol == NEXTCHAR || symbol == IN_COMMENT) && buffer->hasNext());
    i--;
    lexem[i] = '\0';

    // If a symbol has a NEXTCHAR, this means that the loop has quit because there's no other character in the buffer.
    // This equals to an EOF, which should be returned.a
    if (symbol == NEXTCHAR) {
        symbol = FILE_END;
    }

    // TODO: Document this.
    if (symbol == ERROR_SPECIAL) {
        symbol = EQUALS;
        buffer->ungetChar(1);
        currentPosition->incCol(-1);
    }
    Position* nextTokenPosition = tokenPosition();
    // Über die Länge das Lexem bestimmen.
    int length = currentPosition->getCol() - nextTokenPosition->getCol();
    switch (symbol) {
        case IDENTIFIER:
            nextToken = new IdentifierToken();
            ((IdentifierToken*) nextToken)->setKey(symboltable->insert(lexem));
            break;
        case INTEGER:
            //TODO: Den Identifier an das Integer Token übergeben und darin speichern.
            nextToken = new IntegerToken();
            ((IntegerToken*) nextToken)->setValue(atoll(lexem));
            break;
        default:
            nextToken = new Token();
            nextToken->setType(symbol);
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

void Scanner::setCurrentPosition(char c, SymbolType type) {
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

Position* Scanner::tokenPosition() {
    int row = currentPosition->getRow();
    int col = currentPosition->getCol();

    int offset = countSpace < 2 ? 0 : countSpace - 1;
    currentTokenPosition->setCol(nextTokenPosition->getCol() + offset);
    currentTokenPosition->setRow(nextTokenPosition->getRow());

    nextTokenPosition->setCol(col + countSpace - 1);
    nextTokenPosition->setRow(row);

    countSpace = 0;

    return currentTokenPosition;
}


/*

void Scanner::tokenPosition(Token *token) {
    if (firstToken) {
        lineDistance -= 1;
    }
    int tokenRow = currentPosition->getRow();
    int tokenCol = currentPosition->getCol() - lineDistance - lineSpaces - 1;

    token->setPosition(tokenRow, tokenCol);

    lineDistance = 1;
    lineSpaces = 0;
}*/
