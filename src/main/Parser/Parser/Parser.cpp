#include "Parser.h"
#include "../../colors.h"
#include "../../Scanner/Token/IntegerToken.h"
#include "../../Scanner/Token/IdentifierToken.h"
#include <limits.h>

using namespace std;

/**
 * A recursive decent parser for a given LL(1) (lookahead of 1) grammar
 * @param filePath
 * @param logFilePath
 */
Parser::Parser(Scanner *scanner) {
    currentToken = 0L;
    before = NOT_SET;
    this->scanner = scanner;
}

void Parser::nextToken() {
    currentToken = scanner->nextToken();
    if (currentToken->getType() == ERROR) {
        cerr << RED << "Error in Scanner" << COLOR_RESET << endl;
        exit(1);
    }
}

void Parser::match(SymbolType tokenType) {
    if (currentToken->getType() != tokenType) {
        printError();
    }
    nextToken();
}

/**
 build the parse tree recursively -
 a function for every non-terminal is necessary (script p. 34)
 **/
ParseTree *Parser::parse() {
    //cout << GREEN << "start parsing.." << COLOR_RESET << endl;
    parseTree = this->prog();
    return parseTree;
}

ParseTree *Parser::prog() {
    //cout << "parsing [prog].." << endl;
    nextToken();
    Node *node = createNode();
    node->addChildren(decls());
    node->addChildren(statements());
    node->setRuleType(PROG);
    return new ParseTree(node);
};


Node *Parser::decls() {
    //cout << "parsing [decls].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == INTTOKEN) {
        node->addChildren(decl());
        node->setRuleType(DECLS);
        match(SEMICOLON);
        node->addChildren(decls());
        return node;
    } else if (checkFollowSet(DECLS, currentToken->getType())) {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(DECLS_EMPTY);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node *Parser::decl() {
    //cout << "parsing [decl].." << endl;
    Node *node = createNode();
    match(INTTOKEN);
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

Node *Parser::array() {
    //cout << "parsing [array].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == BRACKET_LEFT) {
        match(BRACKET_LEFT);
        if (currentToken->getType() == INTEGER) {
            if (static_cast<IntegerToken *>(currentToken)->getValue() > INT_MAX) {
                cerr << RED << "Parser: Integer in Array out of range: value too high!" << COLOR_RESET << endl;
                printError();
            }

            node->addChildren(createLeaf());
            node->setRuleType(ARRAY);
            nextToken();
        } else {
            printError();
        }

        match(BRACKET_RIGHT);
        return node;
    } else if (checkFollowSet(ARRAY, currentToken->getType())) {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(ARRAY_Empty);
        return epsilon;
    } else {
        printError();
        return node;
    }
}


Node *Parser::statements() {
    //cout << "parsing [statements].." << endl;
    Node *node = createNode();
    SymbolType currentType = currentToken->getType();

    if (currentType == IDENTIFIER
        || currentType == WRITETOKEN
        || currentType == READTOKEN
        || currentType == IFTOKEN
        || currentType == WHILETOKEN
        || currentType == BRACES_LEFT) {

        node->addChildren(statement());
        node->setRuleType(STATEMENTS);
        match(SEMICOLON);

        if (currentToken->getType() == FILE_END) {
            return node;
        }

        node->addChildren(statements());
        return node;
    } else if (checkFollowSet(STATEMENTS, currentToken->getType())) {
        Node *epsilon = createEpsilonNode();
        epsilon->setRuleType(STATEMENTS_EMPTY);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node *Parser::statement() {
    //cout << "parsing [statement].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == IDENTIFIER) {
        if (currentToken->getType() == IDENTIFIER) {
            node->addChildren(createLeaf());
            nextToken();
        } else {
            printError();
        }

        node->addChildren(index());
        match(ASSIGN);
        node->addChildren(exp());
        node->setRuleType(STATEMENT_IDENTIFIER);
    } else if (currentToken->getType() == WRITETOKEN) {
        match(WRITETOKEN);
        match(PARANTHESES_LEFT);
        node->addChildren(exp());
        match(PARANTHESES_RIGHT);
        node->setRuleType(STATEMENT_WRITE);
    } else if (currentToken->getType() == READTOKEN) {
        match(READTOKEN);
        match(PARANTHESES_LEFT);

        if (currentToken->getType() == IDENTIFIER) {
            node->addChildren(createLeaf());
            nextToken();
        } else {
            printError();
        }

        node->addChildren(index());
        match(PARANTHESES_RIGHT);
        node->setRuleType(STATEMENT_READ);
    } else if (currentToken->getType() == BRACES_LEFT) {
        match(BRACES_LEFT);
        node->addChildren(statements());
        node->setRuleType(STATEMENT_BRACES);
        match(BRACES_RIGHT);
    } else if (currentToken->getType() == IFTOKEN) {
        match(IFTOKEN);
        match(PARANTHESES_LEFT);
        node->addChildren(exp());
        match(PARANTHESES_RIGHT);
        node->addChildren(statement());
        match(ELSETOKEN);
        node->addChildren(statement());
        node->setRuleType(STATEMENT_IF);
    } else if (currentToken->getType() == WHILETOKEN) {
        match(WHILETOKEN);
        match(PARANTHESES_LEFT);
        node->addChildren(exp());
        match(PARANTHESES_RIGHT);
        node->addChildren(statement());
        node->setRuleType(STATEMENT_WHILE);
    } else {
        printError();
    }
    return node;
}

Node *Parser::exp() {
    //cout << "parsing [exp].." << endl;
    Node *node = createNode();
    node->addChildren(exp2());
    node->addChildren(op_exp());
    node->setRuleType(EXP);
    return node;
}

Node *Parser::exp2() {
    //cout << "parsing [exp2].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == PARANTHESES_LEFT) {
        match(PARANTHESES_LEFT);
        node->addChildren(exp());
        match(PARANTHESES_RIGHT);
        node->setRuleType(EXP2_PARENS);
    } else if (currentToken->getType() == IDENTIFIER) {
        node->addChildren(createLeaf());
        nextToken();
        node->addChildren(index());
        node->setRuleType(EXP2_IDENTIFIER);
    } else if (currentToken->getType() == INTEGER) {
        if (before == MINUS && static_cast<IntegerToken *>(currentToken)->getValue() > 2147483648) {
            cerr << RED << "Parser: Integer out of range: value too low!" << COLOR_RESET << endl;
            printError();
        } else if (before != MINUS && static_cast<IntegerToken *>(currentToken)->getValue() > INT_MAX) {
            cerr << RED << "Parser: Integer out of range: value too high!" << COLOR_RESET << endl;
            printError();
        }
        node->addChildren(createLeaf());
        nextToken();
        node->setRuleType(EXP2_INTEGER);
    } else if (currentToken->getType() == MINUS) {
        match(MINUS);
        before = MINUS;
        node->addChildren(exp2());
        node->setRuleType(EXP2_NEGATIVE);
    } else if (currentToken->getType() == EXCLAMATION) {
        match(EXCLAMATION);
        node->addChildren(exp2());
        node->setRuleType(EXP2_NEGATION);
    } else {
        printError();
    }

    before = NOT_SET;
    return node;
}

Node *Parser::index() {
    //cout << "parsing [index].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == BRACKET_LEFT) {
        match(BRACKET_LEFT);
        node->addChildren(exp());
        match(BRACKET_RIGHT);
        node->setRuleType(INDEX);
        return node;
    } else if (checkFollowSet(INDEX, currentToken->getType())) {
        Node *epsilon = this->createEpsilonNode();
        epsilon->setRuleType(INDEX_EMPTY);
        return epsilon;
    } else {
        printError();
        return node;
    }
}

Node *Parser::op_exp() {
    SymbolType currentType = currentToken->getType();
    Node *node = createNode();

    if (currentType == PLUS
        || currentType == MINUS
        || currentType == STAR
        || currentType == COLON
        || currentType == LESS
        || currentType == GREATER
        || currentType == EQUALS
        || currentType == SPECIAL
        || currentType == AND) {

        node->addChildren(op());
        node->addChildren(exp());
        node->setRuleType(OP_EXP);
        return node;
    } else if (checkFollowSet(OP_EXP, currentToken->getType())) {
        Node *empty = this->createEpsilonNode();
        empty->setRuleType(OP_EXP_EMPTY);
        return empty;
    } else {
        printError();
        return node;
    }
}

Node *Parser::op() {
    //cout << "parsing [op].." << endl;
    Node *node = createNode();

    if (currentToken->getType() == PLUS) {
        node->setRuleType(OP_PLUS);
    } else if (currentToken->getType() == MINUS) {
        node->setRuleType(OP_MINUS);
    } else if (currentToken->getType() == STAR) {
        node->setRuleType(OP_MULTIPLICATION);
    } else if (currentToken->getType() == COLON) {
        node->setRuleType(OP_DIVISION);
    } else if (currentToken->getType() == LESS) {
        node->setRuleType(OP_LESS);
    } else if (currentToken->getType() == GREATER) {
        node->setRuleType(OP_GREATER);
    } else if (currentToken->getType() == EQUALS) {
        node->setRuleType(OP_EQUALS);
    } else if (currentToken->getType() == SPECIAL) {
        node->setRuleType(OP_SPECIAL);
    } else if (currentToken->getType() == AND) {
        node->setRuleType(OP_AND);
    } else {
        printError();
    }

    nextToken();
    return node;
}

Node *Parser::createNode() {
    Node *node = new Node();
    node->setSymbolType(currentToken->getType());
    return node;
}

Node *Parser::createEpsilonNode() {
    //cout << "create epsilon node" << endl;
    Node *node = new Node();
    node->setNodeType(NO_TYPE);
    return node;
}

void Parser::printError() {
    cerr << RED << "Unexpected token in line: " << currentToken->getRow()
         << " \tcolumn:" << currentToken->getCol() << "\t"
         << ToString(currentToken->getType());

    if (currentToken->getType() == IDENTIFIER) {
        cerr << " lexem: " << static_cast<IdentifierToken *>(currentToken)->getLexem();
    } else if (currentToken->getType() == INTEGER) {
        cerr << " value: " << static_cast<IntegerToken *>(currentToken)->getValue();
    }

    cerr << COLOR_RESET << endl;
    exit(1);
}

Node *Parser::createLeaf() {
    Node *leaf;

    if (currentToken->getType() == INTEGER) {
        leaf = new Node(static_cast<IntegerToken *>(currentToken)->getValue(), currentToken);
    } else if (currentToken->getType() == IDENTIFIER) {
        leaf = new Node(currentToken);
    } else {
        leaf = new Node(currentToken);
    }

    leaf->flagAsLeaf();
    return leaf;
}

/**
 * set of terminals which can appear immediately to the right of a ß-derivation
 */
bool Parser::checkFollowSet(RuleType rule, SymbolType type) {
    switch (rule) {
        case DECLS:
            return (type == IDENTIFIER
                    || type == WRITETOKEN
                    || type == READTOKEN
                    || type == BRACES_LEFT
                    || type == IFTOKEN
                    || type == WHILETOKEN
                    || type == FILE_END);
        case ARRAY:
            return (type == IDENTIFIER);
        case STATEMENTS:
            return (type == BRACES_RIGHT || type == FILE_END);
        case INDEX:
            return type == PLUS
                   || type == MINUS || type == STAR || type == COLON
                   || type == LESS || type == GREATER || type == EQUALS
                   || type == SPECIAL || type == AND || type == PARANTHESES_RIGHT
                   || type == BRACKET_RIGHT || type == ASSIGN
                   || type == SEMICOLON || type == ELSETOKEN;
        case OP_EXP:
            return type == BRACKET_RIGHT
                   || type == PARANTHESES_RIGHT
                   || type == ELSETOKEN
                   || type == SEMICOLON;
        default:
            return false;
    };
}
