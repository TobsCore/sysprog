#ifndef PARSETREE
#define PARSETREE

#include "Node.h"

class ParseTree {
public:
    ParseTree(Node* node);

    virtual ~ParseTree();

    Node* getTree();

private:
    Node* root;
};

#endif //PARSETREE
