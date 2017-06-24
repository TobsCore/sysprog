#ifndef SYSPROG_CODEGENERATOR_H
#define SYSPROG_CODEGENERATOR_H

#include <fstream>
#include "Node.h"
#include "ParseTree.h"

class CodeGenerator {
public:
    CodeGenerator(const char* outfile);
    virtual ~CodeGenerator();
    void runCodeGenerator(ParseTree *tree);

private:

    std::ofstream* codeFile;
    std::stringstream* outText;

    int labelCounter;

    void generateCode(Node* root);

    void generateCodeProg(Node* root);
    void generateCodeDecls(Node* root);
    void generateCodeDecls_EMPTY();
    void generateCodeDecl(Node* root);
    void generateCodeArray(Node* root);
    void generateCodeArray_EMPTY();
    void generateCodeStatements(Node* root);
    void generateCodeStatements_EMPTY();
    void generateCodeStatement_IDENTIFIER(Node *root);
    void generateCodeStatement_WRITE(Node *root);
    void generateCodeStatement_READ(Node *root);
    void generateCodeStatement_BRACES(Node *root);
    void generateCodeStatement_IF(Node *root);
    void generateCodeStatement_WHILE(Node *root);
    void generateCodeExp(Node* root);
    void generateCodeExp2_PARENS(Node *root);
    void generateCodeExp2_IDENTIFIER(Node *root);
    void generateCodeExp2_INTEGER(Node *root);
    void generateCodeExp2_NEGATIVE(Node *root);
    void generateCodeExp2_NEGATION(Node *root);
    void generateCodeIndex(Node* root);
    void generateCodeIndex_EMPTY();
    void generateCodeOp_Exp(Node* root);
    void generateCodeOp_Exp_EMPTY();
    void generateCodeOp_PLUS();
    void generateCodeOp_MINUS();
    void generateCodeOp_MULTIPLICATION();
    void generateCodeOp_DIVISION();
    void generateCodeOp_LESS();
    void generateCodeOp_GREATER();
    void generateCodeOp_EQUALS();
    void generateCodeOp_SPECIAL();
    void generateCodeOp_AND();
};

#endif //SYSPROG_CODEGENERATOR_H
