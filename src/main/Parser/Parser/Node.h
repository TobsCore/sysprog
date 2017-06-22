#ifndef SYSPROG_NODE_H
#define SYSPROG_NODE_H

#include "../automat/TokenType.h"
#include "RuleType.h"
#include "NodeType.h"
#include "../scanner/Token.h"

class Information;

class Node {
public:
    Node();
    Node(Information* information,Token* currentToken);
    Node(Information* info, long value, Token* currentToken);

    virtual ~Node();

    int currentChildren;

    void setNodeType(NodeType type);
    NodeType getNodeType();

    void setTokenType(TokenType type);
    TokenType getTokenType();

    void setRuleType(RuleType ruleType);
    RuleType getRuleType();

    void addChildren(Node* child);
    Node* getChildren(int position);

    long getIntegerValue();

    Information* getInformation();

    Token* getToken();

    void flagAsLeaf();
    bool isLeaf();

private:
    Information* information;
    RuleType ruleType;
    TokenType tokenType;
    NodeType nodeType;
    Node* children[30];
    bool leaf;
    long integerValue;

    Token* token;
};

#endif //SYSPROG_NODE_H
