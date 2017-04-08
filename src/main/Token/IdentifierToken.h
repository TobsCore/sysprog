//
// Created by Tobias Kerst on 08.04.17.
//
#ifndef TOKEN
#define TOKEN

#include "Token.h"

#endif

class IdentifierToken : public Token {
public:
    IdentifierToken();

    const char *toString();

    void setLexem(const char *lexem);

    const char *getLexem();

private:
    const char *lexem;
};

