//
// Created by Tobias Kerst on 08.04.17.
//
#include <iostream>
#include "IdentifierToken.h"

IdentifierToken::IdentifierToken() {
    this->type = IDENTIFIER;
    this->lexem = NULL;
}

const char *IdentifierToken::toString() {
    char *buffer = (char *) malloc(150 * sizeof(char));

    snprintf(buffer, 100, "Token %-20s Line: %3d  Column: %3d  Lexem: %s", getTypeString(), getRow(), getCol(),
             getLexem());
    return buffer;
}

const char* IdentifierToken::getLexem() {
    return lexem;
}

void IdentifierToken::setLexem(const char* lexem) {
    this->lexem = lexem;
}