#include "scanner.h"

Scanner::Scanner(char const *filePath) {

    this->automat = new Automat();
    this->buffer = new Buffer(filePath);
    nextTokenPosition = new Position(1, 1);
    currentTokenPosition = new Position(1, 1);
    currentPosition = new Position(1, 1);
    symboltable = new Symboltable();
    firstToken = true;


    countSpace = 0;
    countChars = 0;
}

Token Scanner::nextToken() {
    Token *nextToken = new Token();

    // If no other characters can be read, return and EOF-Token. This can be used to stop the calling loop.
    if (!buffer->hasNext()) {
        nextToken->setType(FILE_END);
        return *nextToken;
    }

    Signtype symbol;
    do {
        char nextChar = buffer->getChar();
        symbol = automat->checkExpression(nextChar);
        setCurrentPosition(nextChar, symbol);

    } while (symbol == NEXTCHAR && buffer->hasNext());

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

    nextToken->setType(symbol);
    setTokenPosition(nextToken);

    return *nextToken;
}

void Scanner::setCurrentPosition(char c, Signtype type) {
    if (c == ' ' || c == '\t') {
        currentPosition->incCol();
        countSpace += 1;
    } else if (c == '\n') {
        currentPosition->incRow();
        currentPosition->resetCol();
        countSpace += 1;
    } else {
        currentPosition->incCol();
        countChars += 1;
    }
}

void Scanner::setTokenPosition(Token *token) {
    int row = currentPosition->getRow();
    int col = currentPosition->getCol();

    int offset = countSpace < 2 ? 0 : countSpace - 1;
    currentTokenPosition->setCol(nextTokenPosition->getCol() + offset);
    currentTokenPosition->setRow(nextTokenPosition->getRow());

    nextTokenPosition->setCol(col + countSpace - 1);
    nextTokenPosition->setRow(row);

    countSpace = 0;

    token->setPosition(currentTokenPosition);
}


/*

void Scanner::setTokenPosition(Token *token) {
    if (firstToken) {
        lineDistance -= 1;
    }
    int tokenRow = currentPosition->getRow();
    int tokenCol = currentPosition->getCol() - lineDistance - lineSpaces - 1;

    token->setPosition(tokenRow, tokenCol);

    lineDistance = 1;
    lineSpaces = 0;
}*/
