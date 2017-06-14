//
// Created by Tobias Kerst on 06.06.17.
//

#ifndef SYSPROG_PARSER_H
#define SYSPROG_PARSER_H


#include "ParseTree.h"
#include "Node.h"
#include "CodeGenerator.h"
#include "../../Scanner/Scanner/Scanner.h"

class Parser {
public:
    Parser(const char* inputFilePath, const char* outputFilePath);
    ~Parser();

    ParseTree* parse();

private:
    Token * currentToken;
    Token* lastToken;

    Scanner* scanner;
    ParseTree* parseTree;
    //SemanticAnalyser* semanticAnalyser;
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
