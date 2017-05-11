//
// Created by Tobias Kerst on 11.05.17.
//
#ifndef SYMBOLITEM
#define SYMBOLITEM

#include "../SymbolTable/SymbolItem.h"

#endif

#ifndef TOKEN
#define TOKEN

#include "Token.h"

#endif

class ErrorToken : public Token {

public:
    ErrorToken();

    const char *toString();

    const char *getLexem();

    void setKey(SymbolItem *key);

    SymbolItem *getKey();

private:
    SymbolItem *key;
};