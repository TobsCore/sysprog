#include "Token.h"
#include <iostream>

Token::Token() {
    this->type = NEXTCHAR;
    this->position = new Position(1, 1);
}

Token::~Token() {
    delete position;
}

void Token::setType(SymbolType type) {
    this->type = type;
}

SymbolType Token::getType() {
    return this->type;
}

bool Token::isEOF() {
    return this->type == FILE_END;
}


const char *Token::getTypeString() {
    return ToString(this->type);
}

void Token::setPosition(Position *pos) {
    this->position->setCol(pos->getCol());
    this->position->setRow(pos->getRow());
}

void Token::setPosition(int row, int col) {
    this->position->setCol(col);
    this->position->setRow(row);
}

Position *Token::getPosition() {
    return this->position;
}

int Token::getRow() {
    return this->position->getRow();
}

int Token::getCol() {
    return this->position->getCol();
}

const char *Token::toString() {
    char *buffer = (char *) calloc(52, sizeof(char));
    snprintf(buffer, 60, "Token %-20s Line: %5d  Column: %3d", getTypeString(), getRow(), getCol());
    return buffer;
}
