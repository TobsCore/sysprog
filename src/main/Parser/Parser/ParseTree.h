#ifndef SYSPROG_PARSETREE_H
#define SYSPROG_PARSETREE_H

#include "Node.h"

class ParseTree {
public:
    ParseTree(Node* node);
    virtual ~ParseTree();

    Node* getTree();

private:
    Node* root;
};

#endif //SYSPROG_PARSETREE_H
