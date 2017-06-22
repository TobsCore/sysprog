#ifndef SYSPROG_PARSER_H
#define SYSPROG_PARSER_H

#include "ParseTree.h"
#include "Node.h"
#include "../../Scanner/Scanner/Scanner.h"

class Parser {
public:
    Parser(Scanner* scanner);
    ParseTree* parse();

private:
    Token* currentToken;
    SymbolType before;

    ParseTree* parseTree;
    Scanner* scanner;

    //Function for every non-terminal
    ParseTree* prog();
    Node* decls();
    Node* decl();
    Node* array();
    Node* statements();
    Node* statement();
    Node* exp();
    Node* exp2();
    Node* index();
    Node* op_exp();
    Node* op();

    Node* createNode();
    Node* createLeaf();
    Node* createEpsilonNode();

    void match(SymbolType tokenType);
    void nextToken();
    void printError();

    bool checkFollowSet(RuleType rule, SymbolType type);
};

#endif //SYSPROG_PARSER_H
