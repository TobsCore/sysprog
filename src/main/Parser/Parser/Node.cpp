#include "Node.h"
#include <iostream>

using namespace std;

Node::Node() {
    symbolType = NOT_SET;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = 0L;
    token = 0L;
}

Node::Node(Token *currentToken) {
    symbolType = NOT_SET;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = 0L;
    token = currentToken;
}

Node::Node(long value, Token *currentToken) {
    symbolType = NOT_SET;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = value;
    token = currentToken;
}

Node::~Node() {}

void Node::addChildren(Node *child) {
    if (child != 0L) {
        //cout << "add Children " << currentChildren << endl;
        this->children[currentChildren++] = child;
    }
}

Node *Node::getChildren(int position) {
    return children[position];
}

void Node::setRuleType(RuleType ruleType) {
    //cout << COL_CYAN << "create Node: " << ToString(ruleType)<< COL_RST << endl;
    this->ruleType = ruleType;
}

RuleType Node::getRuleType() {
    return this->ruleType;
}

void Node::setNodeType(NodeType type) {
    this->nodeType = type;
}

NodeType Node::getNodeType() {
    return this->nodeType;
}


SymbolType Node::getSymbolType() {
    if (isLeaf()) {
        return this->token->getType();
    }
    return symbolType;
}

void Node::flagAsLeaf() {
    leaf = true;
}

long Node::getIntegerValue() {
    return integerValue;
}

bool Node::isLeaf() {
    return leaf;
}

Token *Node::getToken() {
    return token;
}
