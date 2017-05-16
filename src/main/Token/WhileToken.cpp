//
// Created by Patrick König on 11.05.17.
//

#include "WhileToken.h"


WhileToken::WhileToken() {
    this->type = WHILETOKEN;
    this->key = NULL;
}

const char *WhileToken::toString() {
    char *buffer = (char *) calloc(150, sizeof(char));

    snprintf(buffer, 100, "Token %-20s Line: %3d  Column: %3d  Lexem: %s", getTypeString(), getRow(), getCol(),
             getLexem());
    return buffer;
}

const char* WhileToken::getLexem() {
    return key->lexem;
}

SymbolItem* WhileToken::getKey() {
    return key;
}

void WhileToken::setKey(SymbolItem* key) {
    this->key = key;
}