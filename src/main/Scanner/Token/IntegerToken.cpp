//
// Created by Tobias Kerst on 08.04.17.
//

#include <stdio.h>
#include <stdlib.h>
#include "IntegerToken.h"

IntegerToken::IntegerToken() {
    this->type = INTEGER;
    this->value = 0;
}

const char *IntegerToken::toString() {
    char *buffer = (char *) calloc(70, sizeof(char));

    snprintf(buffer, 70, "Token %-20s Line: %5d  Column: %3d  Value: %lld", getTypeString(), getRow(), getCol(),
             getValue());
    return buffer;
}

long long IntegerToken::getValue() {
    return value;
}

void IntegerToken::setValue(long value) {
    this->value = value;
}
