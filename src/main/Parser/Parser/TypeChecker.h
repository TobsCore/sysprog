#ifndef SYSPROG_SEMANTICANALYSER_H
#define SYSPROG_SEMANTICANALYSER_H

#include "Node.h"
#include "ParseTree.h"
#include <string>

using namespace std;

class SemanticAnalyser {
private:

public:
    SemanticAnalyser();
    virtual ~SemanticAnalyser();

    ParseTree * typeCheck(ParseTree *tree);
    void analyze(Node *root);
    Node* typeCheckProg(Node* root);
    void typeCheckDecls(Node* root);
    void typeCheckDecls_EMPTY(Node *root);
    void typeCheckDecl(Node* root);
    void typeCheckArray(Node* root);
    void typeCheckArray_EMPTY(Node *root);
    void typeCheckStatements(Node* root);
    void typeCheckStatements_EMPTY(Node *root);
    void typeCheckStatement_IDENTIFIER(Node *root);
    void typeCheckStatement_WRITE(Node *root);
    void typeCheckStatement_READ(Node *root);
    void typeCheckStatement_BRACES(Node *root);
    void typeCheckStatement_IF(Node *root);
    void typeCheckStatement_WHILE(Node *root);
    void typeCheckExp(Node* root);
    void typeCheckExp2_PARENS(Node *root);
    void typeCheckExp2_IDENTIFIER(Node *root);
    void typeCheckExp2_INTEGER(Node *root);
    void typeCheckExp2_NEGATIVE(Node *root);
    void typeCheckExp2_NEGATION(Node *root);
    void typeCheckIndex(Node* root);
    void typeCheckIndex_EMPTY(Node *root);
    void typeCheckOp_Exp(Node* root);
    void typeCheckOp_Exp_EMPTY(Node *root);
    void typeCheckOp_PLUS(Node *root);
    void typeCheckOp_MINUS(Node *root);
    void typeCheckOp_MULTIPLICATION(Node *root);
    void typeCheckOp_DIVISION(Node *root);
    void typeCheckOp_LESS(Node *root);
    void typeCheckOp_GREATER(Node *root);
    void typeCheckOp_EQUALS(Node *root);
    void typeCheckOp_SPECIAL(Node *root);
    void typeCheckOp_AND(Node *root);

    void printError(string message, Node* node);

};


#endif //SYSPROG_SEMANTICANALYSER_H
