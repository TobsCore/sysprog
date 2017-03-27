#ifndef TOKEN
#define TOKEN
#include "token.h"
#endif


// TODO: Pass type as constructor parameter
Token::Token() {
    this->type = NEXTCHAR;
    this->value = 0;
    this->position = new Position(1,1);
}

void Token::setValue(char* value) {
    this->value = value;
}

char* Token::getValue() {
    return this->value != 0 ? this->value : (char*) "";
}

void Token::setType(Signtype type) {
    this->type = type;
}

Signtype Token::getType() {
    return this->type;
}

bool Token::isEOF() {
	return this->type == FILE_END;
}


const char* Token::getTypeString()
{
  return EnumStrings[this->type + 2];
}

void Token::setPosition(Position *pos) {
    this->position->setCol(pos->getCol());
    this->position->setRow(pos->getRow());
}

void Token::setPosition(int row, int col) {
    this->position->setCol(col);
    this->position->setRow(row);
}

Position* Token::getPosition() {
    return this->position;
}

int Token::getRow() {
    return this->position->getRow();
}

int Token::getCol() {
    return this->position->getCol();
}
