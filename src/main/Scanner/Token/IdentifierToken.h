//
// Created by Tobias Kerst on 08.04.17.
//
#ifndef SYMBOLITEM
#define SYMBOLITEM

#include "../SymbolTable/SymbolItem.h"

#endif

#ifndef TOKEN
#define TOKEN

#include "Token.h"

#endif

class IdentifierToken : public Token {
public:
    IdentifierToken();

    const char *toString();

    const char *getLexem();

    void setKey(SymbolItem *key);

    SymbolItem *getKey();

private:
    SymbolItem *key;
};

