#include "TypeChecker.h"
#include "../../colors.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

SemanticAnalyser::SemanticAnalyser() {
    //NOP
}

SemanticAnalyser::~SemanticAnalyser() {
    //NOP
}

ParseTree * SemanticAnalyser::typeCheck(ParseTree *tree) {
    return new ParseTree(typeCheckProg(tree->getTree()));
}

//PROG ::= DECLS STATEMENTS
Node* SemanticAnalyser::typeCheckProg(Node *root) {
    Node* decls = root->getChildren(0);
    Node* statements = root->getChildren(1);

    analyze(decls);
    analyze(statements);

    root->setNodeType(NO_TYPE);

    return root;
}

//DECLS ::= DECL ; DECLS
void SemanticAnalyser::typeCheckDecls(Node* node) {
    Node* decl = node->getChildren(0);
    Node* decls = node->getChildren(1);

    analyze(decl);
    analyze(decls);

    node->setNodeType(NO_TYPE);
}

//DECLS ::= e
void SemanticAnalyser::typeCheckDecls_EMPTY(Node *node) {
    node->setNodeType(NO_TYPE);
}

//DECL::= int ARRAY identifier
void SemanticAnalyser::typeCheckDecl(Node *node) {
    Node* array = node->getChildren(0);
    Node* identifier = node->getChildren(1);

    analyze(array);

    if(identifier->getNodeType() != NO_TYPE) {
        printError("identifier already defined!", identifier);
        node->setNodeType(ERROR_TYPE);

    } else if(array->getNodeType() == ERROR_TYPE) {
        node->setNodeType(ERROR_TYPE);

    } else {
        node->setNodeType(NO_TYPE);

        if (array->getNodeType() == ARRAY_TYPE) {
            identifier->setNodeType(INT_ARRAY_TYPE);
        } else {
            identifier->setNodeType(INT_TYPE);
        }
    }
}

//ARRAY::=[integer]
void SemanticAnalyser::typeCheckArray(Node* node) {
    Node* integer = node->getChildren(0);

    if(integer->getSymbolType() == INTEGER && integer->getIntegerValue() > 0) {
        node->setNodeType(ARRAY_TYPE);
    } else {
        printError("no valid integer", 0L);
        node->setNodeType(ERROR_TYPE);
    }
}

//ARRAY ::= e
void SemanticAnalyser::typeCheckArray_EMPTY(Node *node) {
    node->setNodeType(NO_TYPE);
}

//STATEMENTS ::= STATEMENT_IDENTIFIER ; STATEMENTS)
void SemanticAnalyser::typeCheckStatements(Node *node) {
    Node* statement = node->getChildren(0);
    Node* statements = node->getChildren(1);

    analyze(statement);

    if(statements != 0L) {
        analyze(statements);
    }

    node->setNodeType(NO_TYPE);
}

//STATEMENTS ::= e
void SemanticAnalyser::typeCheckStatements_EMPTY(Node *node) {
    node->setNodeType(NO_TYPE);
}

//STATEMENT_IDENTIFIER ::= identifier INDEX := EXP
void SemanticAnalyser::typeCheckStatement_IDENTIFIER(Node *node) {

    Node* exp = node->getChildren(2);
    Node* index = node->getChildren(1);
    Node* identifier = node->getChildren(0);

    analyze(exp);
    analyze(index);

    if (identifier->getNodeType() == NO_TYPE) {
        printError("identifier not defined", identifier);
        node->setNodeType(ERROR_TYPE);

    } else if (exp->getNodeType() == INT_TYPE && (
            (identifier->getNodeType() == INT_TYPE && index->getNodeType() == NO_TYPE)
            ||(identifier->getNodeType() == INT_ARRAY_TYPE && index->getNodeType() == ARRAY_TYPE))) {
        node->setNodeType(NO_TYPE);

    } else {
        printError("incompatible types", identifier);
        node->setNodeType(ERROR_TYPE);
    }
}

//STATEMENT_IDENTIFIER ::= write( EXP )
void SemanticAnalyser::typeCheckStatement_WRITE(Node *node) {
    Node* exp = node->getChildren(0);
    analyze(exp);
    node->setNodeType(NO_TYPE);
}

//STATEMENT_IDENTIFIER ::= read( identifier INDEX)
void SemanticAnalyser::typeCheckStatement_READ(Node *node) {
    Node* identifier = node->getChildren(0);
    Node* index = node->getChildren(1);

    analyze(index);

    if (identifier->getNodeType() == NO_TYPE) {
        printError("identifier not defined", identifier);
        node->setNodeType(ERROR_TYPE);

    } else if (((identifier->getNodeType() == INT_TYPE) && (index->getNodeType() == NO_TYPE))
               || ((identifier->getNodeType() == INT_ARRAY_TYPE) && (index->getNodeType() == ARRAY_TYPE)) ) {
        node->setNodeType(NO_TYPE);

    } else {
        printError("incompatible types in statement_3", identifier);
        node->setNodeType(ERROR_TYPE);
    }
}

//STATEMENT_IDENTIFIER ::= { STATEMENTS }
void SemanticAnalyser::typeCheckStatement_BRACES(Node *node) {
    Node* statements = node->getChildren(0);
    analyze(statements);
    node->setNodeType(NO_TYPE);
}

//STATEMENT_IDENTIFIER ::= if ( EXP ) STATEMENT_IDENTIFIER else STATEMENT_IDENTIFIER
void SemanticAnalyser::typeCheckStatement_IF(Node *node) {
    Node* exp = node->getChildren(0);
    Node* statement1 = node->getChildren(1);
    Node* statement2 = node->getChildren(2);

    analyze(exp);
    analyze(statement1);
    analyze(statement2);

    if(exp->getNodeType() == ERROR_TYPE) {
        node->setNodeType(ERROR_TYPE);
    } else {
        node->setNodeType(NO_TYPE);
    }
}

//STATEMENT_IDENTIFIER ::= while ( EXP ) STATEMENT_IDENTIFIER)
void SemanticAnalyser::typeCheckStatement_WHILE(Node *node) {
    Node* exp = node->getChildren(0);
    Node* statement = node->getChildren(1);

    analyze(exp);
    analyze(statement);

    if(exp->getNodeType() == ERROR_TYPE) {
        node->setNodeType(ERROR_TYPE);
    } else {
        node->setNodeType(NO_TYPE);
    }
}

//EXP ::= EXP2_PARENS OP_EXP
void SemanticAnalyser::typeCheckExp(Node* node) {
    Node* exp2 = node->getChildren(0);
    Node* op_exp = node->getChildren(1);

    analyze(exp2);
    analyze(op_exp);

    if (op_exp->getNodeType() == NO_TYPE) {
        node->setNodeType(exp2->getNodeType());

    } else if (exp2->getNodeType() != op_exp->getNodeType()) {
        node->setNodeType(ERROR_TYPE);

    } else {
        node->setNodeType(exp2->getNodeType());
    }
}

//INDEX ::= [ EXP ]
void SemanticAnalyser::typeCheckExp2_PARENS(Node *node) {
    Node* exp = node->getChildren(0);
    analyze(exp);
    node->setNodeType(exp->getNodeType());
}

//EXP2_PARENS ::= identifier INDEX
void SemanticAnalyser::typeCheckExp2_IDENTIFIER(Node *node) {
    Node* identifier = node->getChildren(0);
    Node* index = node->getChildren(1);

    analyze(index);

    if (identifier->getNodeType() == NO_TYPE) {
        printError("identifier not defined", identifier);
        node->setNodeType(ERROR_TYPE);
    } else if (identifier->getNodeType() == INT_TYPE
               && index->getNodeType() == NO_TYPE) {
        node->setNodeType(identifier->getNodeType());
    } else if (identifier->getNodeType() == INT_ARRAY_TYPE
               && index->getNodeType() == ARRAY_TYPE) {
        node->setNodeType(INT_TYPE);
    } else {
        printError("no primitive Type", 0L);
        node->setNodeType(ERROR_TYPE);
    }
}

//EXP2_PARENS ::= integer
void SemanticAnalyser::typeCheckExp2_INTEGER(Node *node) {
    node->setNodeType(INT_TYPE);
}

//EXP2_PARENS ::= - EXP2_PARENS
void SemanticAnalyser::typeCheckExp2_NEGATIVE(Node *node) {
    Node* exp2 = node->getChildren(0);
    analyze(exp2);
    node->setNodeType(exp2->getNodeType());
}

//EXP2_PARENS ::= ! EXP2_PARENS
void SemanticAnalyser::typeCheckExp2_NEGATION(Node *node) {
    Node* exp2 = node->getChildren(0);

    analyze(exp2);

    if (exp2->getNodeType() != INT_TYPE) {
        node->setNodeType(ERROR_TYPE);
    } else {
        node->setNodeType(INT_TYPE);
    }
}

//INDEX ::= [ EXP ]
void SemanticAnalyser::typeCheckIndex(Node* node) {
    Node* exp = node->getChildren(0);

    analyze(exp);

    if(exp->getNodeType() == ERROR_TYPE) {
        node->setNodeType(ERROR_TYPE);
    } else {
        node->setNodeType(ARRAY_TYPE);
    }
}

//INDEX ::= e
void SemanticAnalyser::typeCheckIndex_EMPTY(Node *node) {
    node->setNodeType(NO_TYPE);
}

//OP_EXP ::= OP_PLUS EXP
void SemanticAnalyser::typeCheckOp_Exp(Node* node) {
    Node* op = node->getChildren(0);
    Node* exp = node->getChildren(1);

    analyze(op);
    analyze(exp);

    node->setNodeType(exp->getNodeType());
}

//OP_EXP ::= e
void SemanticAnalyser::typeCheckOp_Exp_EMPTY(Node *node) {
    node->setNodeType(NO_TYPE);
}

void SemanticAnalyser::typeCheckOp_PLUS(Node *node) {
    node->setNodeType(OP_PLUS_TYPE);
}


void SemanticAnalyser::typeCheckOp_MINUS(Node *node) {
    node->setNodeType(OP_MINUS_TYPE);
}

void SemanticAnalyser::typeCheckOp_MULTIPLICATION(Node *node) {
    node->setNodeType(OP_MULT_TYPE);
}

void SemanticAnalyser::typeCheckOp_DIVISION(Node *node) {
    node->setNodeType(OP_DIV_TYPE);
}

void SemanticAnalyser::typeCheckOp_LESS(Node *node) {
    node->setNodeType(OP_LESS_TYPE);
}

void SemanticAnalyser::typeCheckOp_GREATER(Node *node) {
    node->setNodeType(OP_GREATER_TYPE);
}

void SemanticAnalyser::typeCheckOp_EQUALS(Node *node) {
    node->setNodeType(OP_EQUAL_TYPE);
}

void SemanticAnalyser::typeCheckOp_SPECIAL(Node *node) {
    node->setNodeType(OP_UN_EQUAL_TYPE);
}

void SemanticAnalyser::typeCheckOp_AND(Node *node) {
    node->setNodeType(OP_AND_TYPE);
}

void SemanticAnalyser::printError(string msg, Node* node = 0L) {
    if(node != 0L) {
        Token* token = node->getToken();
        cerr << RED << "Semantic ERROR: "<< msg << " in line: "
             << token->getRow() << " column: " << token->getCol() << COLOR_RESET << endl;
    } else {
        cerr << RED << "Semantic ERROR: "<< msg << COLOR_RESET << endl;
    }
    exit(1);
}

void SemanticAnalyser::analyze(Node* node) {

    if(node == 0L) {
        //cout << "node is null" << endl;
        return;
    }

    //cout << "analyze: " << ToString(node->getRuleType()) << endl;
    switch(node->getRuleType()) {
        case PROG:
            typeCheckProg(node);
            break;
        case DECLS:
            typeCheckDecls(node);
            break;
        case DECLS_EMPTY:
            typeCheckDecls_EMPTY(node);
            break;
        case DECL:
            typeCheckDecl(node);
            break;
        case ARRAY:
            typeCheckArray(node);
            break;
        case ARRAY_Empty:
            typeCheckArray_EMPTY(node);
            break;
        case STATEMENTS:
            typeCheckStatements(node);
            break;
        case STATEMENTS_EMPTY:
            typeCheckStatements_EMPTY(node);
            break;
        case STATEMENT_IDENTIFIER:
            typeCheckStatement_IDENTIFIER(node);
            break;
        case STATEMENT_WRITE:
            typeCheckStatement_WRITE(node);
            break;
        case STATEMENT_READ:
            typeCheckStatement_READ(node);
            break;
        case STATEMENT_BRACES:
            typeCheckStatement_BRACES(node);
            break;
        case STATEMENT_IF:
            typeCheckStatement_IF(node);
            break;
        case STATEMENT_WHILE:
            typeCheckStatement_WHILE(node);
            break;
        case EXP:
            typeCheckExp(node);
            break;
        case EXP2_PARENS:
            typeCheckExp2_PARENS(node);
            break;
        case EXP2_IDENTIFIER:
            typeCheckExp2_IDENTIFIER(node);
            break;
        case EXP2_INTEGER:
            typeCheckExp2_INTEGER(node);
            break;
        case EXP2_NEGATIVE:
            typeCheckExp2_NEGATIVE(node);
            break;
        case EXP2_NEGATION:
            typeCheckExp2_NEGATION(node);
            break;
        case INDEX:
            typeCheckIndex(node);
            break;
        case INDEX_EMPTY:
            typeCheckIndex_EMPTY(node);
            break;
        case OP_EXP:
            typeCheckOp_Exp(node);
            break;
        case OP_EXP_EMPTY:
            typeCheckOp_Exp_EMPTY(node);
            break;
        case OP_PLUS:
            typeCheckOp_PLUS(node);
            break;
        case OP_MINUS:
            typeCheckOp_MINUS(node);
            break;
        case OP_MULTIPLICATION:
            typeCheckOp_MULTIPLICATION(node);
            break;
        case OP_DIVISION:
            typeCheckOp_DIVISION(node);
            break;
        case OP_LESS:
            typeCheckOp_LESS(node);
            break;
        case OP_GREATER:
            typeCheckOp_GREATER(node);
            break;
        case OP_EQUALS:
            typeCheckOp_EQUALS(node);
            break;
        case OP_SPECIAL:
            typeCheckOp_SPECIAL(node);
            break;
        case OP_AND:
            typeCheckOp_AND(node);
            break;
        default:
            cerr << "node is empty" << endl;
    }
}
