//
// Created by Tobias Kerst on 09.04.17.
//

#include <cstdlib>
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

char *StringOp::toUpper(const char *source) {
    int i = 0;
    char *str = strdup(source);

    while (str[i]) {
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        i++;
    }
    return (str);
}

char *StringOp::strdup(const char *source) {
    char *dup = (char *) malloc(length(source) + 1);
    return StringOp::strcpy(dup, source);
}

char *StringOp::strcpy(char *destination, const char *source) {

    char *s = destination;
    while ((*s++ = *source++) != 0)
        ;
    return (destination);
}
