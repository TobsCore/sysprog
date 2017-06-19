//
// Created by Tobias Kerst on 08.04.17.
//
#include "../SymbolTable/SymbolItem.h"
#include "Token.h"

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

