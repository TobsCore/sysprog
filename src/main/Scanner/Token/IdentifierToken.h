//
// Created by Tobias Kerst on 08.04.17.
//
#include "../SymbolTable/SymbolItem.h"
#include "Token.h"
#include "../../Parser/Parser/NodeType.h"

class IdentifierToken : public Token {
public:
    IdentifierToken(SymbolItem *key);

    const char *toString();

    const char *getLexem();

    SymbolItem *getKey();

    void setNodeType(NodeType type);

    NodeType getNodeType();

private:
    SymbolItem *key;
};

