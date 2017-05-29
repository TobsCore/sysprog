//
// Created by Patrick König on 11.05.17.
//

#include "IfToken.h"

IfToken::IfToken() {
    this->type = IFTOKEN;
}

const char *IfToken::toString() {
    char *buffer = (char *) calloc(60, sizeof(char));

    snprintf(buffer, 60, "Token %-20s Line: %5d  Column: %3d", getTypeString(), getRow(), getCol());
    return buffer;
}
