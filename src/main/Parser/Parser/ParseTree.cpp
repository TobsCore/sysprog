#include <stdexcept>
#include "ParseTree.h"

ParseTree::ParseTree(Node* node) {
    if (node->getRuleType() != PROG) {
        throw std::invalid_argument("The root node must be of type PROG");
    }
    this->root = node;
}

ParseTree::~ParseTree() {
    delete root;
}

Node* ParseTree::getTree() {
    return this->root;
}
