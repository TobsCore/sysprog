//
// Created by Tobias Kerst on 06.06.17.
//

#include "Parser.h"


Parser::Parser(const char *inputFilePath, const char *outputFilePath) {
    currentToken = 0L;
    lastToken = 0L;
    scanner = new Scanner(inputFilePath);
    semanticAnalyser = new TypeChecker();
    codeGenerator = new CodeGenerator(outputFilePath);
}

Node *Parser::createNode() {
    Node *node = new Node();
    node->setToken(currentToken);
    return node;
}

Node *Parser::createEpsilonNode() {
    Node *node = new Node();
    node->setType(NO_TYPE);
    return node;
}

void Parser::match(SymbolType tokenType) {
    if (currentToken->getType() != tokenType) {
        throw std::exception();
    }
    nextToken();
}

void Parser::nextToken() {
    currentToken = scanner->nextToken();
}

ParseTree *Parser::prog() {
    nextToken();
    Node *node = createNode();
    node->addChild(decls());
    node->addChild(statements());
    node->setRuleType(PROG);

    return new ParseTree(node);
};

Node *Parser::decls() {
    Node *node = createNode();

    if (currentToken->getType() == INTTOKEN) {
        node->addChild(decl());
        node->setRuleType(DECLS);

        match(SEMICOLON);

        node->addChild(decls());
        return node;
    } else {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(DECLS_EMPTY);
        return epsilon;
    }
}

Node *Parser::decl() {
    Node *node = createNode();
    match(INTTOKEN);
    node->addChild(this->array());

    if (currentToken->getType() == IDENTIFIER) {
        node->setRuleType(DECL);
        node->addChild(createLeaf());
        nextToken();
    } else {
        throw std::exception();
    }
    return node;
}

Node *Parser::array() {
    if (currentToken->getType() == BRACKET_LEFT) {
        Node *node = createNode();

        match(BRACKET_LEFT);
        if (currentToken->getType() == INTEGER) {
            node->addChild(createLeaf()); //ToDo: create leaf
            node->setRuleType(ARRAY);
            nextToken();
        } else {
            throw std::exception();
        }
        match(BRACKET_RIGHT);
        return node;
    } else {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(ARRAY_EMPTY);
        return epsilon;
    }
}

Node *Parser::statements() {
    Node *node = createNode();
    SymbolType currentType = currentToken->getType();

    if (currentType == IDENTIFIER
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
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(STATEMENTS_EMPTY);
        return epsilon;
    }
}

Node *Parser::statement() {
    Node *node = createNode();
    if (currentToken->getType() == IDENTIFIER) {
        if (currentToken->getType() == IDENTIFIER) {
            node->addChild(createLeaf());
            nextToken();
        } else {
            throw std::exception();
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

        if (currentToken->getType() == IDENTIFIER) {
            node->addChild(createLeaf());
            nextToken();
        } else {
            throw std::exception();
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
    } else {
        throw std::exception();
    }
    return node;
}


Node *Parser::exp() {
    Node *node = createNode();
    node->addChild(exp2());
    node->addChild(op_exp());
    node->setRuleType(EXP);

    return node;
}

Node *Parser::exp2() {
    Node *node = createNode();

    if (currentToken->getType() == PARANTHESES_LEFT) {
        match(PARANTHESES_LEFT);
        node->addChild(exp());
        match(PARANTHESES_RIGHT);
        node->setRuleType(EXP2);

    } else if (currentToken->getType() == IDENTIFIER) {
        node->addChild(createLeaf());
        nextToken();
        node->addChild(index());
        node->setRuleType(EXP2_IDENTIFIER);

    } else if (currentToken->getType() == INTEGER) {
        node->addChild(createLeaf());
        nextToken();
        node->setRuleType(EXP2_INTEGER);

    } else if (currentToken->getType() == MINUS) {
        match(MINUS);
        node->addChild(exp2());
        node->setRuleType(EXP2_MINUS);

    } else if (currentToken->getType() == EXCLAMATION) {
        match(EXCLAMATION);
        node->addChild(exp2());
        node->setRuleType(EXP2_NEGATION);

    } else {
        throw std::exception();
    }
    return node;
}

Node *Parser::index() {
    if (currentToken->getType() == BRACKET_LEFT) {
        Node *root = createNode();
        match(BRACKET_LEFT);
        root->addChild(exp());
        match(BRACKET_RIGHT);
        root->setRuleType(INDEX);
        return root;
    } else {
        Node *epsilon = this->createEpsilonNode();
        epsilon->setRuleType(INDEX_EMPTY);
        return epsilon;
    }
}

Node *Parser::op_exp() {
    SymbolType currentType = currentToken->getType();

    if (currentType == PLUS
        || currentType == MINUS
        || currentType == STAR
        || currentType == COLON
        || currentType == LESS
        || currentType == GREATER
        || currentType == EQUALS
        || currentType == SPECIAL
        || currentType == AND) {

        Node *root = createNode();
        root->addChild(op());
        root->addChild(exp());
        root->setRuleType(OP_EXP);
        return root;
    } else {
        Node *epsilon = this->createEpsilonNode();
        epsilon->setRuleType(OP_EXP_EMPTY);
        return epsilon;
    }
}

Node *Parser::op() {
    Node *node = createNode();
    if (currentToken->getType() == PLUS) {
        node->setRuleType(OP_PLUS);
    } else if (currentToken->getType() == MINUS) {
        node->setRuleType(OP_MINUS);
    } else if (currentToken->getType() == STAR) {
        node->setRuleType(OP_MUL);
    } else if (currentToken->getType() == COLON) {
        node->setRuleType(OP_DIV);
    } else if (currentToken->getType() == LESS) {
        node->setRuleType(OP_LESS);
    } else if (currentToken->getType() == GREATER) {
        node->setRuleType(OP_GREATER);
    } else if (currentToken->getType() == EQUALS) {
        node->setRuleType(OP_EQUAL);
    } else if (currentToken->getType() == SPECIAL) {
        node->setRuleType(OP_SPECIAL);
    } else if (currentToken->getType() == AND) {
        node->setRuleType(OP_AND);
    } else {
        throw std::exception();
    }

    nextToken();
    return node;
}

Node *Parser::createLeaf() {
    Node *leaf = new Node();
    leaf->setToken(currentToken);

    return leaf;
}

ParseTree *Parser::parse() {
    parseTree = this->prog();

    return parseTree;
}

void Parser::typeCheck() {
    semanticAnalyser->run(parseTree);
}

void Parser::makeCode() {
    codeGenerator->run(parseTree);
}
