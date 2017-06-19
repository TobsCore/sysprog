//
// Created by Tobias Kerst on 08.04.17.
//
#include "Token.h"

class IntegerToken : public Token {
public:
    IntegerToken();

    const char *toString();

    void setValue(long value);

    long long getValue();

private:
    long value;
};
