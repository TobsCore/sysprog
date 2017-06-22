#include "ParseTree.h"

ParseTree::ParseTree(Node* node) {
    this->root = node;
}

ParseTree::~ParseTree() {}

Node* ParseTree::getTree() {
    return this->root;
}
