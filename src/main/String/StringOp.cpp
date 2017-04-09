//
// Created by Tobias Kerst on 09.04.17.
//

#include "StringOp.h"


bool StringOp::compare(const char *lexem1, const char *lexem2) {
    int i = 0;
    while (lexem1[i] != '\0') {
        if (lexem1[i] != lexem2[i]) {
            return false;
        }
        i++;
    }

    return lexem2[i] == '\0';
}

int StringOp::length(const char *lexem) {
    int i = 0;
    while (lexem[i] != '\0') {
        i++;
    }
    return i;
}