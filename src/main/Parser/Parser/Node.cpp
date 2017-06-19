//
// Created by Kevin Wolf on 08.06.17.
//

#include "Node.h"
#include <stdexcept>

Node::Node() {
    this->currentChild = 0;
    this->nodeType = NO_TYPE;
    this->ruleType = RULE_NOT_SET;
}

Node::Node(RuleType ruleType) {
    this->ruleType = ruleType;
    this->currentChild = 0;
    this->nodeType = NO_TYPE;
}

Node::~Node() {
    for (int i = 0; i < currentChild; i++) {
        delete children[i];
    }
    // Possibly clean up the properties of the object

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

        throw std::out_of_range("Position is out of range");

    }
    return this->children[pos];
}

void Node::setType(NodeType type) {
    this->nodeType = type;
}

NodeType Node::getType() {
    return this->nodeType;
}

RuleType Node::getRuleType() const {
    return ruleType;
}

void Node::setRuleType(RuleType ruleType) {
    Node::ruleType = ruleType;
}


const char *Node::getLexem() const {
    return lexem;
}

void Node::setLexem(const char *lexem) {
    Node::lexem = lexem;
}

long Node::getIntegerValue() const {
    return integerValue;
}

Token *Node::getTokenType() const {
    return tokenType;
}

void Node::setTokenType(Token *tokenType) {
    Node::tokenType = tokenType;
}

unsigned char Node::getAmountOfChildren() {
    return currentChild;
}
