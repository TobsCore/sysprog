//
// Created by Tobias Kerst on 08.04.17.
//
#include <iostream>
#include "IdentifierToken.h"
#include "../../String/StringOp.h"

IdentifierToken::IdentifierToken() {
    this->type = IDENTIFIER;
    this->key = NULL;
}

const char *IdentifierToken::toString() {

    int lexemLength = StringOp::length(getLexem());
    char *buffer = (char *) calloc(65 + lexemLength, sizeof(char));

    snprintf(buffer, 100, "Token %-20s Line: %5d  Column: %3d  Lexem: %s", getTypeString(), getRow(), getCol(),
             getLexem());
    return buffer;
}

const char *IdentifierToken::getLexem() {
    return key->lexem;
}

SymbolItem *IdentifierToken::getKey() {
    return key;
}

void IdentifierToken::setKey(SymbolItem *key) {
    this->key = key;
}
