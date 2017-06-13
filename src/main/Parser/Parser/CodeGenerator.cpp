//
// Created by Kevin Wolf on 13.06.17.
//

#include "CodeGenerator.h"


CodeGenerator::CodeGenerator(char* out) {
    this->labelCounter = 0;
    file.open(out);
}

CodeGenerator::~CodeGenerator(){
    // TODO Auto-generated destructor stub
}

void CodeGenerator::error(char* string) {
    std::cerr << string << std::endl;
    exit(1);
}

void CodeGenerator::makeCode(Node* node) {
    switch(node->getRuleType()) {
        case PROG:
            makeCodeProg(node);
            break;
        case DECLS:
            makeCodeDecls(node);
            break;
        case DECLS_EMPTY:
            makeCodeDecls_Empty(node);
            break;
        case DECL:
            makeCodeDecl(node);
            break;
        case ARRAY:
            makeCodeArray(node);
            break;
        case ARRAY_EMPTY:
            makeCodeArray_Empty(node);
            break;
        case STATEMENTS:
            makeCodeStatements(node);
            break;
        case STATEMENTS_EMPTY:
            makeCodeStatements_Empty(node);
            break;
        case STATEMENT:
            makeCodeStatement(node);
            break;
        case STATEMENT_2:
            makeCodeStatement_2(node);
            break;
        case STATEMENT_3:
            makeCodeStatement_3(node);
            break;
        case STATEMENT_4:
            makeCodeStatement_4(node);
            break;
        case STATEMENT_5:
            makeCodeStatement_5(node);
            break;
        case STATEMENT_6:
            makeCodeStatement_6(node);
            break;
        case EXP:
            makeCodeExp(node);
            break;
        case EXP2:
            makeCodeExp2(node);
            break;
        case EXP2_2:
            makeCodeExp2_2(node);
            break;
        case EXP2_3:
            makeCodeExp2_3(node);
            break;
        case EXP2_4:
            makeCodeExp2_4(node);
            break;
        case EXP2_5:
            makeCodeExp2_5(node);
            break;
        case INDEX:
            makeCodeIndex(node);
            break;
        case INDEX_EMPTY:
            makeCodeIndex_Empty(node);
            break;
        case OP_EXP:
            makeCodeOp_Exp(node);
            break;
        case OP_EXP_EMPTY:
            makeCodeOp_Exp_Empty(node);
            break;
        case OP:
            makeCodeOp(node);
            break;
        case OP_2:
            makeCodeOp_2(node);
            break;
        case OP_3:
            makeCodeOp_3(node);
            break;
        case OP_4:
            makeCodeOp_4(node);
            break;
        case OP_5:
            makeCodeOp_5(node);
            break;
        case OP_6:
            makeCodeOp_6(node);
            break;
        case OP_7:
            makeCodeOp_7(node);
            break;
        case OP_8:
            makeCodeOp_8(node);
            break;
        case OP_9:
            makeCodeOp_9(node);
            break;
        default:
            error("empty Node!");
    }
}

void CodeGenerator::makeCodeProg(Node* node) {
    Node* decls = node->getChild(0);
    Node* statements = node->getChild(1);

    if(decls != 0L) {
        makeCode(decls);
    }
    if(statements != 0L) {
        makeCode(statements);
    }

    file << " STP ";
    file.close();
}

void CodeGenerator::makeCodeDecls(Node* node) {
    Node* decl = node->getChild(0);
    Node* decls = node->getChild(1);
    if (decls != 0l) {
        makeCode(decl);
    }
    if (decls != 0L) {
        makeCode(decls);
    }
}

void CodeGenerator::makeCodeDecls_Empty(Node* node) {}

void CodeGenerator::makeCodeDecl(Node* node) {
    Node* array = node->getChild(0);
    Node* identifier = node->getChild(1);

    file << " DS " << "$" << identifier->getLexem();

  	if(array != 0L) {
    makeCode(array);
	}
}

void CodeGenerator::makeCodeArray(Node* node) {
    Node* integer = node->getChild(0);

    file << " " << integer->getIntegerValue();
}

void CodeGenerator::makeCodeArray_Empty(Node* node) {
    file << " " << 1;
}

void CodeGenerator::makeCodeStatements(Node* node) {
    Node* statement = node->getChild(0);
    Node* statements = node->getChild(1);

    if(statement != 0L)
        makeCode(statement);
    if(statements != 0L)
        makeCode(statements);
}

void CodeGenerator::makeCodeStatements_Empty(Node* node) {
    file << " NOP ";
}


















