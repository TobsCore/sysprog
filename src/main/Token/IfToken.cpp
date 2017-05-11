//
// Created by Patrick König on 11.05.17.
//

#include "IfToken.h"

IfToken::IfToken() {
    this->type = IF;
    this->key = NULL;
}

const char *IfToken::toString() {
    char *buffer = (char *) calloc(150, sizeof(char));

    snprintf(buffer, 100, "Token %-20s Line: %3d  Column: %3d  Lexem: %s", getTypeString(), getRow(), getCol(),
             getLexem());
    return buffer;
}

const char* IfToken::getLexem() {
    return key->lexem;
}

SymbolItem* IfToken::getKey() {
    return key;
}

void IfToken::setKey(SymbolItem* key) {
    this->key = key;
}