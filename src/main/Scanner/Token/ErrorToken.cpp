//
// Created by Tobias Kerst on 11.05.17.
//

#include <cstdlib>
#include <iostream>
#include "ErrorToken.h"


ErrorToken::ErrorToken() {
    this->type = ERROR;
}

const char *ErrorToken::toString() {
    char *buffer = (char *) calloc(150, sizeof(char));
    if (this->info == 0) {
        snprintf(buffer, 100, "Error Found! Line: %3d Column: %3d", getRow(), getCol());
    } else {
        snprintf(buffer, 100, "Error Found! Line: %3d Column: %3d  Info: %s", getRow(), getCol(),
                 getInfo());
    }
    return buffer;
}

const char *ErrorToken::getInfo() {
    return info;
}

void ErrorToken::setInfo(const char *info) {
    this->info = info;
}
