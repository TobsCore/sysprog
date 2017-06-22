#include "Parser.h"
#include "../constants.h"
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

/**
 * A recursive decent parser for a given LL(1) (lookahead of 1) grammar
 * @param filePath
 * @param logFilePath
 */
Parser::Parser(Scanner* scanner) {
    currentToken = 0L;
    before = NOT_SET;
    this->scanner = scanner;
}

void Parser::nextToken(){
    currentToken = scanner->nextToken();
    scanner->printOutput(currentToken);
    //cout << "next token: " << ToString(currentToken->getType()) << endl;

    if(currentToken->getType() == ERROR) {
        cerr << COL_RED << "Error in Scanner" << COL_RST << endl;
        exit(EXIT_SCANNER_ERR);
    } else if(currentToken->getType() == UNKNOWN) {
        cerr << COL_RED << "Error in Scanner - invalid char: " << currentToken->getInformation()->getLexem() << COL_RST << endl;
        exit(EXIT_SCANNER_INVALID_CHAR);
    }
}

void Parser::match(TokenType tokenType) {
    //cout << "match: " << ToString(tokenType);
    //cout << " with: " << ToString(currentToken->getType()) << endl;

    if (currentToken->getType() != tokenType) {
        printError();
    }
    nextToken();
}

/**
 build the parse tree recursively -
 a function for every non-terminal is necessary (script p. 34)
 **/
ParseTree* Parser::parse() {
    cerr << COL_GREEN << "start parsing.." << COL_RST << endl;
    parseTree = this->prog();
    return parseTree;
}

ParseTree* Parser::prog(){
    //cout << "parsing [prog].." << endl;
    nextToken();
    Node* node = createNode();
    node->addChildren(decls());
    node->addChildren(statements());
    node->setRuleType(PROG);
    return new ParseTree(node);
};


Node* Parser::decls() {
    //cout << "parsing [decls].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == INT) {
        node->addChildren(decl());
        node->setRuleType(DECLS);
        match(SIGN_SEMICOLON);
        node->addChildren(decls());
        return node;
    } else if (checkFollowSet(DECLS, currentToken->getType())) {
        Node* epsilon = createEpsilonNode();
        epsilon->setRuleType(DECLS_2);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node* Parser::decl() {
    //cout << "parsing [decl].." << endl;
    Node* node = createNode();
    match(INT);
    node->addChildren(this->array());

    if (currentToken->getType() == IDENTIFIER) {
        node->setRuleType(DECL);
        node->addChildren(createLeaf());
        nextToken();
    } else {
        printError();
    }

    return node;
}

Node* Parser::array() {
    //cout << "parsing [array].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == SIGN_OPENING_SQUARE_BRACKET) {
        match(SIGN_OPENING_SQUARE_BRACKET);
        if (currentToken->getType() == INTEGER) {
            if(currentToken->getValue() > INT_MAX) {
                cerr << COL_RED << "Parser: Integer in Array out of range: value too high!" << endl;
                printError();
            }

            node->addChildren(createLeaf());
            node->setRuleType(ARRAY);
            nextToken();
        } else {
            printError();
        }

        match(SIGN_CLOSING_SQUARE_BRACKET);
        return node;
    } else if (checkFollowSet(ARRAY, currentToken->getType())) {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(ARRAY_2);
        return epsilon;
    } else {
        printError();
        return node;
    }
}


Node* Parser::statements() {
    //cout << "parsing [statements].." << endl;
    Node* node = createNode();
    TokenType currentType = currentToken->getType();

    if(currentType == IDENTIFIER
       || currentType == WRITE
       || currentType == READ
       || currentType == IF
       || currentType == WHILE
       || currentType == SIGN_OPENING_CURLY_BRACKET) {

        node->addChildren(statement());
        node->setRuleType(STATEMENTS);
        match(SIGN_SEMICOLON);

        if(currentToken->getType() == END_OF_FILE) {
            return node;
        }

        node->addChildren(statements());
        return node;
    } else if (checkFollowSet(STATEMENTS, currentToken->getType())) {
        Node* epsilon = createEpsilonNode();
        epsilon->setRuleType(STATEMENTS_2);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node* Parser::statement() {
    //cout << "parsing [statement].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == IDENTIFIER) {
        if (currentToken->getType() == IDENTIFIER) {
            node->addChildren(createLeaf());
            nextToken();
        } else {
            printError();
        }

        node->addChildren(index());
        match(SIGN_COLON_EQUAL);
        node->addChildren(exp());
        node->setRuleType(STATEMENT);
    } else if (currentToken->getType() == WRITE) {
        match(WRITE);
        match(SIGN_OPENING_BRACKET);
        node->addChildren(exp());
        match(SIGN_CLOSING_BRACKET);
        node->setRuleType(STATEMENT_2);
    } else if (currentToken->getType() == READ) {
        match(READ);
        match(SIGN_OPENING_BRACKET);

        if(currentToken->getType() == IDENTIFIER) {
            node->addChildren(createLeaf());
            nextToken();
        } else {
            printError();
        }

        node->addChildren(index());
        match(SIGN_CLOSING_BRACKET);
        node->setRuleType(STATEMENT_3);
    } else if (currentToken->getType() == SIGN_OPENING_CURLY_BRACKET) {
        match(SIGN_OPENING_CURLY_BRACKET);
        node->addChildren(statements());
        node->setRuleType(STATEMENT_4);
        match(SIGN_CLOSING_CURLY_BRACKET);
    } else if (currentToken->getType() == IF) {
        match(IF);
        match(SIGN_OPENING_BRACKET);
        node->addChildren(exp());
        match(SIGN_CLOSING_BRACKET);
        node->addChildren(statement());
        match(ELSE);
        node->addChildren(statement());
        node->setRuleType(STATEMENT_5);
    } else if (currentToken->getType() == WHILE) {
        match(WHILE);
        match(SIGN_OPENING_BRACKET);
        node->addChildren(exp());
        match(SIGN_CLOSING_BRACKET);
        node->addChildren(statement());
        node->setRuleType(STATEMENT_6);
    } else {
        printError();
    }
    return node;
}

Node* Parser::exp() {
    //cout << "parsing [exp].." << endl;
    Node* node = createNode();
    node->addChildren(exp2());
    node->addChildren(op_exp());
    node->setRuleType(EXP);
    return node;
}

Node* Parser::exp2() {
    //cout << "parsing [exp2].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == SIGN_OPENING_BRACKET) {
        match(SIGN_OPENING_BRACKET);
        node->addChildren(exp());
        match(SIGN_CLOSING_BRACKET);
        node->setRuleType(EXP2);
    } else if (currentToken->getType() == IDENTIFIER) {
        node->addChildren(createLeaf());
        nextToken();
        node->addChildren(index());
        node->setRuleType(EXP2_2);
    } else if (currentToken->getType() == INTEGER) {
        if(before == SIGN_MINUS && currentToken->getValue() > INT_MIN_POSITIV) {
            cerr << COL_RED << "Parser: Integer out of range: value too low!" << endl;
            printError();
        } else if(before != SIGN_MINUS && currentToken->getValue() > INT_MAX) {
            cerr << COL_RED << "Parser: Integer out of range: value too high!" << endl;
            printError();
        }
        node->addChildren(createLeaf());
        nextToken();
        node->setRuleType(EXP2_3);
    } else if (currentToken->getType() == SIGN_MINUS) {
        match(SIGN_MINUS);
        before = SIGN_MINUS;
        node->addChildren(exp2());
        node->setRuleType(EXP2_4);
    } else if (currentToken->getType() == SIGN_EXCLAMATION) {
        match(SIGN_EXCLAMATION);
        node->addChildren(exp2());
        node->setRuleType(EXP2_5);
    } else {
        printError();
    }

    before = NOT_SET;
    return node;
}

Node* Parser::index() {
    //cout << "parsing [index].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == SIGN_OPENING_SQUARE_BRACKET) {
        match(SIGN_OPENING_SQUARE_BRACKET);
        node->addChildren(exp());
        match(SIGN_CLOSING_SQUARE_BRACKET);
        node->setRuleType(INDEX);
        return node;
    } else if(checkFollowSet(INDEX, currentToken->getType())) {
        Node* epsilon =  this->createEpsilonNode();
        epsilon->setRuleType(INDEX_2);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node* Parser::op_exp() {
    TokenType currentType = currentToken->getType();
    Node* node = createNode();

    if(currentType == SIGN_PLUS
       || currentType == SIGN_MINUS
       || currentType == SIGN_STAR
       || currentType == SIGN_COLON
       || currentType == SIGN_SMALLER_THAN
       || currentType == SIGN_GREATER
       || currentType == SIGN_EQUALS
       || currentType == SIGN_EQUALS_COLON_EQUALS
       || currentType == SIGN_AND_AND) {

        node->addChildren(op());
        node->addChildren(exp());
        node->setRuleType(OP_EXP);
        return node;
    } else if(checkFollowSet(OP_EXP, currentToken->getType())) {
        Node* empty = this->createEpsilonNode();
        empty->setRuleType(OP_EXP_2);
        return empty;
    } else {
        printError();
        return node;
    }
}

Node* Parser::op() {
    //cout << "parsing [op].." << endl;
    Node* node = createNode();

    if (currentToken->getType() == SIGN_PLUS) {
        node->setRuleType(OP);
    } else if (currentToken->getType() == SIGN_MINUS) {
        node->setRuleType(OP_2);
    } else if (currentToken->getType() == SIGN_STAR) {
        node->setRuleType(OP_3);
    } else if (currentToken->getType() == SIGN_COLON) {
        node->setRuleType(OP_4);
    } else if (currentToken->getType() == SIGN_SMALLER_THAN) {
        node->setRuleType(OP_5);
    } else if (currentToken->getType() == SIGN_GREATER) {
        node->setRuleType(OP_6);
    } else if (currentToken->getType() == SIGN_EQUALS) {
        node->setRuleType(OP_7);
    } else if (currentToken->getType() == SIGN_EQUALS_COLON_EQUALS) {
        node->setRuleType(OP_8);
    } else if (currentToken->getType() == SIGN_AND_AND) {
        node->setRuleType(OP_9);
    } else {
        printError();
    }

    nextToken();
    return node;
}

Node* Parser::createNode() {
    Node* node = new Node();
    node->setTokenType(currentToken->getType());
    return node;
}

Node* Parser::createEpsilonNode() {
    //cout << "create epsilon node" << endl;
    Node* node = new Node();
    node->setNodeType(NO_TYPE);
    return node;
}

void Parser::printError() {
    cerr << COL_RED <<"Unexpected token in line: " << currentToken->getLine()
         << " \tcolumn:"<< currentToken->getColumn() << "\t"
         << ToString(currentToken->getType());

    if (currentToken->getType() == IDENTIFIER) {
        cerr << " lexem: " << currentToken->getInformation()->getLexem();
    } else if (currentToken->getType() == INTEGER) {
        cerr << " value: " << currentToken->getValue();
    }

    cerr << COL_RST << endl;
    exit(EXIT_PARSER_ERR);
}

Node* Parser::createLeaf() {
    Node* leaf;

    if (currentToken->getType() == INTEGER) {
        //cout << COL_BLUE << "create Integer Leaf: " << ToString(currentToken->getType())
        //	 << " " << currentToken->getValue()<< COL_RST << endl;

        leaf = new Node(new Information(INTEGER), currentToken->getValue(), currentToken);
    } else if (currentToken->getType() == IDENTIFIER) {
        //cout << COL_BLUE << "create Identifier Leaf: " << ToString(currentToken->getType())
        //	 << " : " << currentToken->getInformation()->getLexem()<< COL_RST << endl;

        leaf = new Node(scanner->getSymboltable()->get(currentToken->getKey()), currentToken);
    } else {
        //cout << COL_BLUE << "create Leaf: " << ToString(currentToken->getType())
        //	 << " : " << currentToken->getInformation()->getLexem()<< COL_RST << endl;

        leaf = new Node(currentToken->getInformation(), currentToken);
    }

    leaf->flagAsLeaf();
    return leaf;
}

/**
 * set of terminals which can appear immediately to the right of a ß-derivation
 */
bool Parser::checkFollowSet(RuleType rule, TokenType type) {
    //cout << "check rule (follow set): " << ToString(rule) << " with tokenType: " << ToString(type) << endl;
    switch (rule) {
        case DECLS:
            return (type == IDENTIFIER
                    || type == WRITE
                    || type == READ
                    || type == SIGN_OPENING_CURLY_BRACKET
                    || type == IF
                    || type == WHILE
                    || type == END_OF_FILE);
        case ARRAY:
            return (type == IDENTIFIER);
        case STATEMENTS:
            return (type == SIGN_CLOSING_CURLY_BRACKET || type == END_OF_FILE);
        case INDEX:
            return type == SIGN_PLUS
                   || type == SIGN_MINUS || type == SIGN_STAR || type == SIGN_COLON
                   || type == SIGN_SMALLER_THAN || type == SIGN_GREATER || type == SIGN_EQUALS
                   || type == SIGN_EQUALS_COLON_EQUALS || type == SIGN_AND_AND || type == SIGN_CLOSING_BRACKET
                   || type == SIGN_CLOSING_SQUARE_BRACKET || type == SIGN_COLON_EQUAL
                   || type == SIGN_SEMICOLON || type == ELSE;
        case OP_EXP:
            return type == SIGN_CLOSING_SQUARE_BRACKET
                   || type == SIGN_CLOSING_BRACKET
                   || type == ELSE
                   || type == SIGN_SEMICOLON;
        default:
            return false;
    };
}
