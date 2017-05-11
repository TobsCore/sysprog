//
// Created by Patrick König on 11.05.17.
//

#ifndef SYSPROG_IFTOKEN_H
#define SYSPROG_IFTOKEN_H
#endif

#ifndef TOKEN
#define TOKEN
#endif

#include "Token.h"
#include "../SymbolTable/SymbolItem.h"

class IfToken : public Token {


public:
    IfToken();

    const char *toString();

    const char *getLexem();

    void setKey(SymbolItem *key);

    SymbolItem *getKey();

private:
    SymbolItem *key;
};





