//
// Created by Tobias Kerst on 19.06.17.
//
#ifndef SYSPROG_SEMANTICANALYSER_H
#define SYSPROG_SEMANTICANALYSER_H

#include "Node.h"
#include "ParseTree.h"
#include <string>
#ifndef TOKEN
#define TOKEN
#include "../../Scanner/Token/Token.h"
#endif

using namespace std;


class TypeChecker {
private:

public:
    TypeChecker();
    virtual ~TypeChecker();

    Node* run(ParseTree *tree);
    void analyze(Node *root);
    Node* typeCheckProg(Node* root);
    void typeCheckDecls(Node* root);
    void typeCheckDecls_Empty(Node *root);
    void typeCheckDecl(Node* root);
    void typeCheckArray(Node* root);
    void typeCheckArray_Empty(Node *root);
    void typeCheckStatements(Node* root);
    void typeCheckStatements_Empty(Node *root);
    void typeCheckStatement_Identifier(Node *root);
    void typeCheckStatement_Write(Node *root);
    void typeCheckStatement_Read(Node *root);
    void typeCheckStatement_Block(Node *root);
    void typeCheckStatement_If(Node *root);
    void typeCheckStatement_While(Node *root);
    void typeCheckExp(Node* root);
    void typeCheckExp2(Node* root);
    void typeCheckExp2_2(Node* root);
    void typeCheckExp2_3(Node* root);
    void typeCheckExp2_4(Node* root);
    void typeCheckExp2_5(Node* root);
    void typeCheckIndex(Node* root);
    void typeCheckIndex_Empty(Node *root);
    void typeCheckOp_Exp(Node* root);
    void typeCheckOp_Exp_Empty(Node *root);
    void typeCheckOp_Plus(Node *root);
    void typeCheckOp_Minus(Node *root);
    void typeCheckOp_Mul(Node *root);
    void typeCheckOp_Div(Node *root);
    void typeCheckOp_Less(Node *root);
    void typeCheckOp_Greater(Node *root);
    void typeCheckOp_Equal(Node *root);
    void typeCheckOp_Special(Node *root);
    void typeCheckOp_And(Node *root);

    void printError(string message, Node* node);

};


#endif //SYSPROG_SEMANTICANALYSER_H

