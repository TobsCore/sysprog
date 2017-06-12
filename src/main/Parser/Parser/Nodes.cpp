//
// Created by Kevin Wolf on 08.06.17.
//

#include "Nodes.h"

Nodes::Nodes() {
    this->currentBranch = 0;
    this->nodeTypeInfo = NO_TYPE;
    // TODO(Toby): this->type = ?; //tokenType Filler
    this->isLeaf = false;
    //add rule
    //add tokeninfo
    // TODO(Toby): this->tokenInfo = 0L;  //Filler, muss noch besorgt werden! tokenInfo gleich Info zum Inhalt
}


Nodes::~Nodes() {
    // TODO Auto-generated destructor stub
}

bool Nodes::isTreeLeaf() {
    return this->isLeaf;
}

void Nodes::setTreeLeaf() {
    this->isLeaf = true;
    this->setNodeTypeInfo(NO_TYPE);
}

void Nodes::newBranch(Nodes* branch) {
    if (branch != 0L)
        this->branches[this->currentBranch++] = branch;
}

Nodes* Nodes::getBranch(int pos) {
    return this->branches[pos];
}

void Nodes::setNodeTypeInfo(NodeType info) {
    if(this->isTreeLeaf()) {
        //TODO(Toby): this->tokenInfo->setNodeTypeInfo(info);
    } else {
        this->nodeTypeInfo = info; //macht eventuell sinn eine Fassade zu bauen bezüglich relevanter informationen fürs parsen. (tokeninfo)
    }
}

NodeType Nodes::getNodeTypeInfo() {
    if(this->isTreeLeaf()) {
        //TODO(Toby): return this->tokenInfo->getNodeTypeInfo();
    } else {
        return this->nodeTypeInfo;
    }
}

//ToDo: Regeln getter/setter; TokenInfo in node speichern



