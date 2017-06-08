//
// Created by Kevin Wolf on 08.06.17.
//

#include "Nodes.h"
#include "NodeType.h"
#include "../../Scanner/SymbolType/Symboltype.h"

Node::Node() {
    this->currentBranch = 0;
    this->nodeTypeInfo = NO_TYPE;
    this->rule = 0L;
    this->type = NOT_SET;
    this->isTreeLeaf = false;
    this->tokenInfo = 0L;
}


Node::~Node() {
    // TODO Auto-generated destructor stub
}

bool Node::isLeaf() {
    return this->isALeaf;
}

void Node::setTreeLeaf() {
    this->isALeaf = true;
    this->setNodeTypeInfo(NO_TYPE);
}

void Node::newBranch(Node* branch) {
    if (branch != 0L)
        this->branches[this->currentBranch++] = branch;
}

Node* Node::getBranch(int pos) {
    return this->branches[pos];
}

void Node::setNodeTypeInfo(NodeInfo info) {
    if(this->isALeaf) {
        this->tokenInfo->setNodeTypeInfo(info);
    } else {
        this->nodeTypeInfo = info;
    }
}

NodeInfo Node::getNodeTypeInfo() {
    if(this->isALeaf) {
        return this->tokenInfo->getNodeTypeInfo();
    } else {
        return this->nodeTypeInfo;
    }
}

//ToDo: Regeln getter/setter; TokenInfo in node speichern



