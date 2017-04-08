//
// Created by Tobias Kerst on 08.04.17.
//
#ifndef TOKEN
#define TOKEN
#include "Token.h"
#endif

class IntegerToken : public Token {
public:
    IntegerToken();
    const char *toString();

    void setValue(long long value);

    long long getValue();

private:
    long long value;
};
