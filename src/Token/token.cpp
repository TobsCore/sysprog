#ifndef token
#define token
#include "token.h"
#endif

Token::Token() {
    this->column = 0;
    this->type = 0;
    this->value = 0;
    this->row = 0;
}

void Token::setValue(char* value) {
    this->value = value;
}

char* Token::getValue() {
    return this->value;
}

void Token::setType(int type) {
    this->type = type;
}

int Token::getType() {
    return this->type;
}

void Token::setColumn(int column) {
    this->column = column;
}

int Token::getColumn() {
    return this->column;
}

void Token::setRow(int row) {
    this->row = row;
}

int Token::getRow() {
    return this->row;
}
