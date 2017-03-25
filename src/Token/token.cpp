#ifndef TOKEN
#define TOKEN
#include "token.h"
#endif



Token::Token() {
    this->column = 0;
    this->type = NEXTCHAR;
    this->value = 0;
    this->row = 0;
}

void Token::setValue(char* value) {
    this->value = value;
}

char* Token::getValue() {
    return this->value;
}

void Token::setType(Signtype type) {
    this->type = type;
}

Signtype Token::getType() {
    return this->type;
}

void Token::setColumn(int column) {
    // Don't accept negative values
    if(column <= 0) {
        this->column = 0;
    } else {
        this->column = column;
    }
}

int Token::getColumn() {
    return this->column;
}

void Token::setRow(int row) {
    // Don't accept negative values
    if(row <= 0) {
        this->row = 0;
    } else {
        this->row = row;
    }
}

int Token::getRow() {
    return this->row;
}
