#include "ParseTree.h"

ParseTree::ParseTree(Node* node) {
    this->root = node;
}

ParseTree::~ParseTree() {
    delete root;
}

Node* ParseTree::getTree() {
    return this->root;
}
