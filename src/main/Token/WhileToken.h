//
// Created by Patrick König on 11.05.17.
//

#ifndef SYSPROG_WHILETOKEN_H
#define SYSPROG_WHILETOKEN_H
#endif
#ifndef TOKEN
#define TOKEN
#include "Token.h"
#endif
#include "../SymbolTable/SymbolItem.h"

class WhileToken : public Token {


public:
    WhileToken();

    const char *toString();
};



