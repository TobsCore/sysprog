#include "Node.h"
#include "../constants.h"
#include <iostream>

using namespace std;

Node::Node() {
    tokenType = NOT_SET;
    information = 0L;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = 0L;
    token = 0L;
}

Node::Node(Information* info, Token* currentToken) {
    tokenType = NOT_SET;
    information = info;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = 0L;
    token = currentToken;
}

Node::Node(Information* info, long value, Token* currentToken) {
    tokenType = NOT_SET;
    information = info;
    ruleType = RULE_NOT_SET;
    currentChildren = 0;
    leaf = 0L;
    integerValue = value;
    token = currentToken;
}

Node::~Node() { }

void Node::addChildren(Node* child) {
    if(child != 0L) {
        //cout << "add Children " << currentChildren << endl;
        this->children[currentChildren++] = child;
    }
}

Node* Node::getChildren(int position) {
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
    if(leaf) {
        this->information->setNodeType(type);
    } else {
        this->nodeType = type;
    }
}

NodeType Node::getNodeType() {
    if(leaf) {
        return this->information->getNodeType();
    } else {
        return this->nodeType;
    }
}

void Node::setTokenType(TokenType type) {
    tokenType = type;
}

TokenType Node::getTokenType() {
    if(isLeaf()){
        return this->information->getTokenType();
    }
    return tokenType;
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

Token* Node::getToken() {
    return token;
}

Information* Node::getInformation() {
    return information;
}
