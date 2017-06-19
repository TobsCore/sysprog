//
// Created by Tobias Kerst on 06.06.17.
//

#ifndef SYSPROG_PARSER_H
#define SYSPROG_PARSER_H


#include "ParseTree.h"
#ifndef NODE
#define NODE
#include "Node.h"
#endif
#ifndef CODEGENERATOR
#define CODEGENERATOR
#include "CodeGenerator.h"
#endif
#include "../../Scanner/Scanner/Scanner.h"
#include "SemanticAnalyzer.h"

class Parser {
public:
    Parser(const char* inputFilePath, const char* outputFilePath);
    ~Parser();

    ParseTree* parse();
    void typeCheck();
    void makeCode();

private:
    Token * currentToken;
    Token* lastToken;

    Scanner* scanner;
    ParseTree* parseTree;
    SemanticAnalyzer* semanticAnalyser;
    CodeGenerator* codeGenerator;

    //Function for every non-terminal
    ParseTree* prog();

  Node* decls();
    Node* decl();
    Node* array();
    Node* statements();
    Node* statement();
    Node* exp();
    Node* exp2();
    Node* op_exp();
    Node* op();
    Node* createLeaf();
    Node* index();

    Node* createNode();
    Node* createEpsilonNode();

    void match(SymbolType tokenType);
    void nextToken();
    //void printError();

};


#endif //SYSPROG_PARSER_H
