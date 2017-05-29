//
// Created by Tobias Kerst on 11.05.17.
//

#include "ErrorToken.h"

ErrorToken::ErrorToken() {
    this->type = ERROR;
}

const char *ErrorToken::toString() {
    char *buffer = (char *) calloc(150, sizeof(char));

    snprintf(buffer, 100, "Error Found! Line: %3d Column: %3d  Info: %s", getRow(), getCol(),
             getInfo());
    return buffer;
}

const char *ErrorToken::getInfo() {
    return info;
}

void ErrorToken::setInfo(const char *info) {
    this->info = info;
}
