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


class SemanticAnalyzer {
private:

public:
    SemanticAnalyzer();
    virtual ~SemanticAnalyzer();

    Node* typeCheck(ParseTree* tree);
    void analyze(Node *root);
    Node* typeCheckProg(Node* root);
    void typeCheckDecls(Node* root);
    void typeCheckDecls_2(Node* root);
    void typeCheckDecl(Node* root);
    void typeCheckArray(Node* root);
    void typeCheckArray_2(Node* root);
    void typeCheckStatements(Node* root);
    void typeCheckStatements_2(Node* root);
    void typeCheckStatement(Node* root);
    void typeCheckStatement_2(Node* root);
    void typeCheckStatement_3(Node* root);
    void typeCheckStatement_4(Node* root);
    void typeCheckStatement_5(Node* root);
    void typeCheckStatement_6(Node* root);
    void typeCheckExp(Node* root);
    void typeCheckExp2(Node* root);
    void typeCheckExp2_2(Node* root);
    void typeCheckExp2_3(Node* root);
    void typeCheckExp2_4(Node* root);
    void typeCheckExp2_5(Node* root);
    void typeCheckIndex(Node* root);
    void typeCheckIndex_2(Node* root);
    void typeCheckOp_Exp(Node* root);
    void typeCheckOp_Exp_2(Node* root);
    void typeCheckOp(Node* root);
    void typeCheckOp_2(Node* root);
    void typeCheckOp_3(Node* root);
    void typeCheckOp_4(Node* root);
    void typeCheckOp_5(Node* root);
    void typeCheckOp_6(Node* root);
    void typeCheckOp_7(Node* root);
    void typeCheckOp_8(Node* root);
    void typeCheckOp_9(Node* root);

    void printError(string message, Node* node);

};


#endif //SYSPROG_SEMANTICANALYSER_H

