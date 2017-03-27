#include "scanner.h"

Scanner::Scanner(char const *filePath) {

    this->automat = new Automat();
    this->buffer = new Buffer(filePath);
    nextTokenPosition = new Position(1, 1);
    currentTokenPosition = new Position(1, 1);
    currentPosition = new Position(1, 1);
    firstToken = true;

    countSpace = 0;
    countChars = 0;
    tokenSize = 0;
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

    nextToken->setType(symbol);
    setTokenPosition(nextToken);

    return *nextToken;
}

void Scanner::setCurrentPosition(char c, Signtype type) {
    if (c == ' ' || c == '\t') {
        currentPosition->incCol();
        countSpace += 1;
    } else if (c == '\0' && type == IDENTIFIER) {
        countSpace += 1;
    } else if (c == '\n') {
        currentPosition->incRow();
        currentPosition->resetCol();
    } else {
        currentPosition->incCol();
        countChars += 1;
    }
}

void Scanner::setTokenPosition(Token *token) {
    int row = currentPosition->getRow();
    int col = currentPosition->getCol();

    if (firstToken) {
        firstToken = false;
    } else {
        currentTokenPosition->setCol(nextTokenPosition->getCol() + countSpace);
        currentTokenPosition->setRow(nextTokenPosition->getRow());
    }

    nextTokenPosition->setCol(col - 1);
    nextTokenPosition->setRow(row);
    if (countSpace <= 1) {
     countSpace = 0;
    } else {
        countSpace -= 1;
    }

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
