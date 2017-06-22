#include "SemanticAnalyser.h"
#include "../constants.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

SemanticAnalyser::SemanticAnalyser() {
    //NOP
}

SemanticAnalyser::~SemanticAnalyser() {
    //NOP
}

Node* SemanticAnalyser::typeCheck(ParseTree* tree) {
    return typeCheckProg(tree->getTree());
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
void SemanticAnalyser::typeCheckDecls_2(Node* node) {
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

    if(integer->getTokenType() == INTEGER && integer->getIntegerValue() > 0) {
        node->setNodeType(ARRAY_TYPE);
    } else {
        printError("no valid integer", 0L);
        node->setNodeType(ERROR_TYPE);
    }
}

//ARRAY ::= e
void SemanticAnalyser::typeCheckArray_2(Node* node) {
    node->setNodeType(NO_TYPE);
}

//STATEMENTS ::= STATEMENT ; STATEMENTS)
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
void SemanticAnalyser::typeCheckStatements_2(Node* node) {
    node->setNodeType(NO_TYPE);
}

//STATEMENT ::= identifier INDEX := EXP
void SemanticAnalyser::typeCheckStatement(Node *node) {

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

//STATEMENT ::= write( EXP )
void SemanticAnalyser::typeCheckStatement_2(Node* node) {
    Node* exp = node->getChildren(0);
    analyze(exp);
    node->setNodeType(NO_TYPE);
}

//STATEMENT ::= read( identifier INDEX)
void SemanticAnalyser::typeCheckStatement_3(Node* node) {
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

//STATEMENT ::= { STATEMENTS }
void SemanticAnalyser::typeCheckStatement_4(Node* node) {
    Node* statements = node->getChildren(0);
    analyze(statements);
    node->setNodeType(NO_TYPE);
}

//STATEMENT ::= if ( EXP ) STATEMENT else STATEMENT
void SemanticAnalyser::typeCheckStatement_5(Node* node) {
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

//STATEMENT ::= while ( EXP ) STATEMENT)
void SemanticAnalyser::typeCheckStatement_6(Node* node) {
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

//EXP ::= EXP2 OP_EXP
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
void SemanticAnalyser::typeCheckExp2(Node* node) {
    Node* exp = node->getChildren(0);
    analyze(exp);
    node->setNodeType(exp->getNodeType());
}

//EXP2 ::= identifier INDEX
void SemanticAnalyser::typeCheckExp2_2(Node* node) {
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

//EXP2 ::= integer
void SemanticAnalyser::typeCheckExp2_3(Node* node) {
    node->setNodeType(INT_TYPE);
}

//EXP2 ::= - EXP2
void SemanticAnalyser::typeCheckExp2_4(Node* node) {
    Node* exp2 = node->getChildren(0);
    analyze(exp2);
    node->setNodeType(exp2->getNodeType());
}

//EXP2 ::= ! EXP2
void SemanticAnalyser::typeCheckExp2_5(Node* node) {
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
void SemanticAnalyser::typeCheckIndex_2(Node* node) {
    node->setNodeType(NO_TYPE);
}

//OP_EXP ::= OP EXP
void SemanticAnalyser::typeCheckOp_Exp(Node* node) {
    Node* op = node->getChildren(0);
    Node* exp = node->getChildren(1);

    analyze(op);
    analyze(exp);

    node->setNodeType(exp->getNodeType());
}

//OP_EXP ::= e
void SemanticAnalyser::typeCheckOp_Exp_2(Node* node) {
    node->setNodeType(NO_TYPE);
}

void SemanticAnalyser::typeCheckOp(Node* node) {
    node->setNodeType(OP_PLUS_TYPE);
}


void SemanticAnalyser::typeCheckOp_2(Node* node) {
    node->setNodeType(OP_MINUS_TYPE);
}

void SemanticAnalyser::typeCheckOp_3(Node* node) {
    node->setNodeType(OP_MULT_TYPE);
}

void SemanticAnalyser::typeCheckOp_4(Node* node) {
    node->setNodeType(OP_DIV_TYPE);
}

void SemanticAnalyser::typeCheckOp_5(Node* node) {
    node->setNodeType(OP_LESS_TYPE);
}

void SemanticAnalyser::typeCheckOp_6(Node* node) {
    node->setNodeType(OP_GREATER_TYPE);
}

void SemanticAnalyser::typeCheckOp_7(Node* node) {
    node->setNodeType(OP_EQUAL_TYPE);
}

void SemanticAnalyser::typeCheckOp_8(Node* node) {
    node->setNodeType(OP_UN_EQUAL_TYPE);
}

void SemanticAnalyser::typeCheckOp_9(Node* node) {
    node->setNodeType(OP_AND_TYPE);
}

void SemanticAnalyser::printError(string msg, Node* node = 0L) {
    if(node != 0L) {
        Token* token = node->getToken();
        cerr << COL_RED << "Semantic ERROR: "<< msg << " in line: "
             << token->getLine() << " column: " << token->getColumn() << COL_RST << endl;
    } else {
        cerr << COL_RED << "Semantic ERROR: "<< msg << COL_RST << endl;
    }
    exit(EXIT_PARSER_SEMANTIC_ERR);
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
        case DECLS_2:
            typeCheckDecls_2(node);
            break;
        case DECL:
            typeCheckDecl(node);
            break;
        case ARRAY:
            typeCheckArray(node);
            break;
        case ARRAY_2:
            typeCheckArray_2(node);
            break;
        case STATEMENTS:
            typeCheckStatements(node);
            break;
        case STATEMENTS_2:
            typeCheckStatements_2(node);
            break;
        case STATEMENT:
            typeCheckStatement(node);
            break;
        case STATEMENT_2:
            typeCheckStatement_2(node);
            break;
        case STATEMENT_3:
            typeCheckStatement_3(node);
            break;
        case STATEMENT_4:
            typeCheckStatement_4(node);
            break;
        case STATEMENT_5:
            typeCheckStatement_5(node);
            break;
        case STATEMENT_6:
            typeCheckStatement_6(node);
            break;
        case EXP:
            typeCheckExp(node);
            break;
        case EXP2:
            typeCheckExp2(node);
            break;
        case EXP2_2:
            typeCheckExp2_2(node);
            break;
        case EXP2_3:
            typeCheckExp2_3(node);
            break;
        case EXP2_4:
            typeCheckExp2_4(node);
            break;
        case EXP2_5:
            typeCheckExp2_5(node);
            break;
        case INDEX:
            typeCheckIndex(node);
            break;
        case INDEX_2:
            typeCheckIndex_2(node);
            break;
        case OP_EXP:
            typeCheckOp_Exp(node);
            break;
        case OP_EXP_2:
            typeCheckOp_Exp_2(node);
            break;
        case OP:
            typeCheckOp(node);
            break;
        case OP_2:
            typeCheckOp_2(node);
            break;
        case OP_3:
            typeCheckOp_3(node);
            break;
        case OP_4:
            typeCheckOp_4(node);
            break;
        case OP_5:
            typeCheckOp_5(node);
            break;
        case OP_6:
            typeCheckOp_6(node);
            break;
        case OP_7:
            typeCheckOp_7(node);
            break;
        case OP_8:
            typeCheckOp_8(node);
            break;
        case OP_9:
            typeCheckOp_9(node);
            break;
        default:
            cerr << "node is empty" << endl;
    }
}
