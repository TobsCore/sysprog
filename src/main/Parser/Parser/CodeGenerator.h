#ifndef SYSPROG_CODEGENERATOR_H
#define SYSPROG_CODEGENERATOR_H

#include <fstream>
#include "Node.h"
#include "ParseTree.h"

class CodeGenerator {
public:
    CodeGenerator(const char* outfile);
    virtual ~CodeGenerator();
    void runCodeGenerator(Node* tree);

private:

    std::ofstream* codeFile;
    std::stringstream* outText;

    int labelCounter;

    void generateCode(Node* root);

    void generateCodeProg(Node* root);
    void generateCodeDecls(Node* root);
    void generateCodeDecls_2();
    void generateCodeDecl(Node* root);
    void generateCodeArray(Node* root);
    void generateCodeArray_2();
    void generateCodeStatements(Node* root);
    void generateCodeStatements_2();
    void generateCodeStatement(Node* root);
    void generateCodeStatement_2(Node* root);
    void generateCodeStatement_3(Node* root);
    void generateCodeStatement_4(Node* root);
    void generateCodeStatement_5(Node* root);
    void generateCodeStatement_6(Node* root);
    void generateCodeExp(Node* root);
    void generateCodeExp2(Node* root);
    void generateCodeExp2_2(Node* root);
    void generateCodeExp2_3(Node* root);
    void generateCodeExp2_4(Node* root);
    void generateCodeExp2_5(Node* root);
    void generateCodeIndex(Node* root);
    void generateCodeIndex_2();
    void generateCodeOp_Exp(Node* root);
    void generateCodeOp_Exp_2();
    void generateCodeOp();
    void generateCodeOp_2();
    void generateCodeOp_3();
    void generateCodeOp_4();
    void generateCodeOp_5();
    void generateCodeOp_6();
    void generateCodeOp_7();
    void generateCodeOp_8();
    void generateCodeOp_9();
};

#endif //SYSPROG_CODEGENERATOR_H
