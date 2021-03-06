#include "Node.h"
#include "../../Scanner/Token/IdentifierToken.h"
#include "../../Scanner/Token/IntegerToken.h"
#include <iostream>

using namespace std;

Node::Node() {
    symbolType = NOT_SET;
    ruleType = RULE_NOT_SET;
    nodeType = NO_TYPE;
    currentChildren = 0;
    leaf = 0L;
    token = 0L;
}

Node::Node(Token *currentToken) {
    symbolType = NOT_SET;
    ruleType = RULE_NOT_SET;
    nodeType = NO_TYPE;
    currentChildren = 0;
    leaf = 0L;
    token = currentToken;
}

Node::~Node() {}

void Node::addChild(Node *child) {
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
    if (isLeaf()) {
        static_cast<IdentifierToken *>(this->getToken())->setNodeType(type);
    }
    this->nodeType = type;
}

NodeType Node::getNodeType() {
    if (isLeaf()) {
        return static_cast<IdentifierToken*>(this->getToken())->getNodeType();
    }
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
    return static_cast<IntegerToken*>(token)->getValue();
}

bool Node::isLeaf() {
    return leaf;
}

Token *Node::getToken() {
    return token;
}

void Node::setSymbolType(SymbolType type) {
    this->symbolType = type;

}
