//
// Created by Tobias Kerst on 11.05.17.
//

#include "ErrorToken.h"

ErrorToken::ErrorToken() {
    this->type = ERROR;
    this->key = NULL;
}

const char *ErrorToken::toString() {
    char *buffer = (char *) calloc(150, sizeof(char));

    snprintf(buffer, 100, "Token %-20s Line: %3d  Column: %3d  Lexem: %s", getTypeString(), getRow(), getCol(),
             getLexem());
    return buffer;
}

const char *ErrorToken::getLexem() {
    return key->lexem;
}

SymbolItem *ErrorToken::getKey() {
    return key;
}

void ErrorToken::setKey(SymbolItem *key) {
    this->key = key;
}
