//
// Created by Kevin Wolf on 08.06.17.
//

#include "Nodes.h"

Nodes::Nodes() {
    this->currentBranch = 0;
    this->nodeTypeInfo = NO_TYPE;
    this->type = ?; //tokenType Filler
    this->isTreeLeaf = false;
    //add rule
    //add tokeninfo
    this->tokenInfo = 0L;  //Filler, muss noch besorgt werden! tokenInfo gleich Info zum Inhalt
}


Nodes::~Nodes() {
    // TODO Auto-generated destructor stub
}

bool Nodes::isTreeLeaf() {
    return this->isTreeLeaf;
}

void Nodes::setTreeLeaf() {
    this->isTreeLeaf = true;
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
    if(this->isTreeLeaf) {
        this->tokenInfo->setNodeTypeInfo(info);
    } else {
        this->nodeTypeInfo = info; //macht eventuell sinn eine Fassade zu bauen bezüglich relevanter informationen fürs parsen. (tokeninfo)
    }
}

NodeType Nodes::getNodeTypeInfo() {
    if(this->isTreeLeaf) {
        return this->tokenInfo->getNodeTypeInfo();
    } else {
        return this->nodeTypeInfo;
    }
}

//ToDo: Regeln getter/setter; TokenInfo in node speichern



