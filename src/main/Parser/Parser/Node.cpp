//
// Created by Kevin Wolf on 08.06.17.
//

#include "Node.h"
#include <stdexcept>

Node::Node() {
    this->currentChild = 0;
    this->nodeType = NO_TYPE;
}


Node::~Node() {
}

bool Node::isLeaf() {
    return currentChild == 0;
}

void Node::addChild(Node *newChild) {
    if (currentChild != MAX_CHILDREN) {
        this->children[this->currentChild++] = newChild;
    } else {
        throw std::out_of_range("Too many children in node");
    }
}

Node *Node::getChild(unsigned char pos) {
    if (pos >= currentChild) {
        throw std::out_of_range ("Position is out of range");
    }
    return this->children[pos];
}

void Node::setType(NodeType type) {
    this->nodeType = type;
}

NodeType Node::getType() {
    return this->nodeType;
}

SymbolType Node::getTokenType() const {
    return tokenType;
}

void Node::setTokenType(SymbolType tokenType) {
    Node::tokenType = tokenType;
}

RuleType Node::getRuleType() const {
    return ruleType;
}

void Node::setRuleType(RuleType ruleType) {
    Node::ruleType = ruleType;
}

//ToDo: Regeln getter/setter; TokenInfo in node speichern



