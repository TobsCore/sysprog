//
// Created by Tobias Kerst on 06.06.17.
//

#include "Parser.h"
#include "../../Scanner/SymbolType/Symboltype.h"




Node* Parser::createNode() {
    Node* node = new Node();
    node->setTokenType(currentToken->getType());
    return node;
}

Node* Parser::createEpsilonNode() {
    Node* node = new Node();
    node->setType(NO_TYPE);
    return node;
}

void Parser::match(SymbolType tokenType) {

    if (currentToken->getType() != tokenType) {
        //printError ToDo: print error
    }
    nextToken();
}

void Parser::nextToken(){
    currentToken = scanner->nextToken();

}

ParseTree* Parser::prog(){

    nextToken();
    Node* node = createNode();
    node->addChild(decls());
    node->addChild(statements());
    node->setRuleType(PROG);

    return new ParseTree(node);
};

Node* Parser::decls() {

    Node* node = createNode();

    if (currentToken->getType() == INTTOKEN) {
        node->addChild(decl());
        node->setRuleType(DECLS);

        match(SEMICOLON);

        node->addChild(decls());
        return node;
    } else {
        Node* epsilon = createEpsilonNode();
        epsilon->setRuleType(DECLS_EMPTY);
        return epsilon;
    }
}

Node* Parser::decl() {

    Node* node = createNode();
    match(INTTOKEN);
    node->addChild(this->array());

    if (currentToken->getType() == IDENTIFIER) {
        node->setRuleType(DECL);
        node->addChild(createLeaf());
        nextToken();
    } else {
        //printError
    }
    return node;
}

Node* Parser::array() {

    if (currentToken->getType() == BRACKET_LEFT) {
        Node* node = createNode();

        match(BRACKET_LEFT);
        if (currentToken->getType() == INTEGER) {
            node->addChild(createLeaf()); //ToDo: create leaf
            node->setRuleType(ARRAY);
            nextToken();
        } else {
            //printError
        }
        match(BRACKET_RIGHT);
        return node;
    } else {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(ARRAY_EMPTY);
        return epsilon;
    }
}

Node* Parser::statements() {

    Node* node = createNode();
    SymbolType currentType = currentToken->getType();


    if(currentType == IDENTIFIER
       || currentType == WRITETOKEN
       || currentType == READTOKEN
       || currentType == IFTOKEN
       || currentType == WHILETOKEN
       || currentType == BRACKET_LEFT) {

        node->addChild(statement());
        node->setRuleType(STATEMENTS);
        match(SEMICOLON);
        node->addChild(statements());
        return node;
    } else {
        Node* epsilon = createEpsilonNode();
        epsilon->setRuleType(STATEMENTS_EMPTY);
        return epsilon;
    }
}

Node* Parser::statement() {

    Node* node = createNode();
    if (currentToken->getType() == IDENTIFIER) {
        if (currentToken->getType() == IDENTIFIER) {
            node->addChild(createLeaf());
            nextToken();
        } else {
            //printError
        }
        node->addChild(index());
        match(ASSIGN);
        node->addChild(exp());
        node->setRuleType(STATEMENT_IDENTIFIER);

    } else if (currentToken->getType() == WRITETOKEN) {
        match(WRITETOKEN);
        match(PARANTHESES_LEFT);
        node->addChild(exp());
        match(PARANTHESES_RIGHT);
        node->setRuleType(STATEMENT_WRITE);

    } else if (currentToken->getType() == READTOKEN) {
        match(READTOKEN);
        match(PARANTHESES_LEFT);

        if(currentToken->getType() == IDENTIFIER) {
            node->addChild(createLeaf());
            nextToken();
        } else {
            //printError
        }
        node->addChild(index());
        match(PARANTHESES_RIGHT);
        node->setRuleType(STATEMENT_READ);

    } else if (currentToken->getType() == BRACES_LEFT) {
        match(BRACES_LEFT);
        node->addChild(statements());
        node->setRuleType(STATEMENT_BLOCK);
        match(BRACES_RIGHT);

    } else if (currentToken->getType() == IFTOKEN) {
        match(IFTOKEN);
        match(PARANTHESES_LEFT);
        node->addChild(exp());
        match(PARANTHESES_RIGHT);
        node->addChild(statement());
        match(ELSETOKEN);
        node->addChild(statement());
        node->setRuleType(STATEMENT_IF);

    } else if (currentToken->getType() == WHILETOKEN) {
        match(WHILETOKEN);
        match(PARANTHESES_LEFT);
        node->addChild(exp());
        match(PARANTHESES_RIGHT);
        node->addChild(statement());
        node->setRuleType(STATEMENT_WHILE);
    }
    else {
        //printError
    }
    return node;
}

Node *Parser::createLeaf() {
    return nullptr;
    // TODO: Do dis shit!
}

Node *Parser::exp() {
    return nullptr;
    // TODO: Do dis shit two
}

Node *Parser::index() {
    return nullptr;
    // TODO: And dis
}
