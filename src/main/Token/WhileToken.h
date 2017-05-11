//
// Created by Patrick König on 11.05.17.
//

#ifndef SYSPROG_WHILETOKEN_H
#define SYSPROG_WHILETOKEN_H
#endif
#ifndef TOKEN
#define TOKEN
#endif
#include "Token.h"
#include "../SymbolTable/SymbolItem.h"

class WhileToken : public Token {


public:
    WhileToken();

    const char *toString();

    const char *getLexem();

    void setKey(SymbolItem *key);

    SymbolItem *getKey();

private:
    SymbolItem *key;
};



