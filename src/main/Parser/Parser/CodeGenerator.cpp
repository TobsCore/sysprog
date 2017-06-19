//
// Created by Kevin Wolf on 13.06.17.
//

#include "CodeGenerator.h"
#include "../../Scanner/Token/IdentifierToken.h"
#include "../../Scanner/Token/IntegerToken.h"


CodeGenerator::CodeGenerator(const char* out) {
    this->labelCounter = 0;
    file.open(out);
}

CodeGenerator::~CodeGenerator(){
    // TODO Auto-generated destructor stub
}

void CodeGenerator::error(const char* string) {
    throw std::exception();
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
        case STATEMENT_IDENTIFIER:
            makeCodeStatement(node);
            break;
        case STATEMENT_WRITE:
            makeCodeStatementWrite(node);
            break;
        case STATEMENT_READ:
            makeCodeStatementRead(node);
            break;
        case STATEMENT_BLOCK:
            makeCodeStatementBlock(node);
            break;
        case STATEMENT_IF:
            makeCodeStatementIf(node);
            break;
        case STATEMENT_WHILE:
            makeCodeStatementWhile(node);
            break;
        case EXP:
            makeCodeExp(node);
            break;
        case EXP2:
            makeCodeExp2(node);
            break;
        case EXP2_INBRACKETS:
            //makeCodeExp2InBrackets(node);
            // TODO(Toby): Methode noch implementieren.
            break;
        case EXP2_IDENTIFIER:
            makeCodeExp2Identifier(node);
            break;
        case EXP2_INTEGER:
            makeCodeExp2Integer(node);
            break;
        case EXP2_MINUS:
            makeCodeExp2Minus(node);
            break;
        case EXP2_NEGATION:
            makeCodeExp2Negation(node);
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
        case OP_PLUS:
            makeCodeOpPlus(node);
            break;
        case OP_MINUS:
            makeCodeOpMinus(node);
            break;
        case OP_MUL:
            makeCodeOpMultiplication(node);
            break;
        case OP_DIV:
            makeCodeOpDivision(node);
            break;
        case OP_LESS:
            makeCodeOpLess(node);
            break;
        case OP_GREATER:
            makeCodeOpGreater(node);
            break;
        case OP_EQUAL:
            makeCodeOpEqual(node);
            break;
        case OP_SPECIAL:
            makeCodeOpSpecial(node);
            break;
        case OP_AND:
            makeCodeOpAnd(node);
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

    file << " DS " << "$" << static_cast<IdentifierToken *>(identifier->getTokenType())->getLexem();

  	if(array != 0L) {
        makeCode(array);
	}
}

void CodeGenerator::makeCodeArray(Node* node) {
    Node* integer = node->getChild(0);

    file << " " << static_cast<IntegerToken *>(integer->getTokenType())->getValue();
}

void CodeGenerator::makeCodeArray_Empty(Node* node) {
    file << " " << 1;
}

void CodeGenerator::makeCodeStatements(Node* node) {
    Node* statement = node->getChild(0);
    Node* statements = node->getChild(1);

    if(statement != 0L){
        makeCode(statement);
    }
    if(statements != 0L){
        makeCode(statements);
    }
}

void CodeGenerator::makeCodeStatements_Empty(Node* node) {
    file << " NOP ";
}

void CodeGenerator::makeCodeStatement(Node* node) {
    Node* exp = node->getChild(2);
    Node* index = node->getChild(1);
    Node* identifier = node->getChild(0);

	if(exp != 0L){
        makeCode(exp);
    }
    file << " LA " << "$" << static_cast<IdentifierToken *>(identifier->getTokenType())->getLexem();

    if(index != 0L){
        makeCode(index);
    }
    file << " STR ";
}

void CodeGenerator::makeCodeStatementWrite(Node *node) {
    Node* exp = node->getChild(0);

	if (exp != 0L) {
        makeCode(exp);
	}
    file << " PRI ";
}

void CodeGenerator::makeCodeStatementRead(Node *node) {
    Node* identifier = node->getChild(0);
    Node* index = node->getChild(1);

    file << " REA ";
    file << " LA " << "$" << static_cast<IdentifierToken *>(identifier->getTokenType())->getLexem();
	if (index != 0L) {
        makeCode(index);
	}
    file << " STR ";
}

void CodeGenerator::makeCodeStatementBlock(Node *node) {
    Node* statements = node->getChild(0);
	if (statements != 0L) {
        makeCode(statements);
	}
}

void CodeGenerator::makeCodeStatementIf(Node *node) {
    Node* exp = node->getChild(0);
    Node* statement1 = node->getChild(1);
    Node* statement2 = node->getChild(2);

    int label1 = ++labelCounter;
    int label2 = ++labelCounter;

	if (exp != 0L) {
        makeCode(exp);
	}
    file << " JIN " << "#label" << label1 <<" ";

    if (statement1 != 0L) {
        makeCode(statement1);
	}
    file << " JMP " << "#label" << label2 <<" "; // label2 ist neu
    file << "#label" << label1 << " NOP ";

    if (statement2 != 0L) {
        makeCode(statement2);
	}
    file << "#label" << label2 << " NOP ";
}

void CodeGenerator::makeCodeStatementWhile(Node *node) {
    Node* exp = node->getChild(0);
    Node* statement = node->getChild(1);

    int label1 = ++labelCounter;
    int label2 = ++labelCounter;

    file << "#label" << label1 << " NOP "; // label1 ist neu

    if (exp != 0L) {
        makeCode(exp);
	}
    file << " JIN " << "#label" << label2 <<" ";

    if (statement != 0l) {
        makeCode(statement);
	}
    file << " JMP " << "#label" << label1 <<" ";
    file << "#label" << label2 << " NOP ";
}


void CodeGenerator::makeCodeExp(Node* node) {
    Node* exp2 = node->getChild(0);
    Node* op_exp = node->getChild(1);

	if(op_exp != 0L) {
        if (op_exp->getType() == NO_TYPE) {
            makeCode(exp2);
        } else if (op_exp->getChild(0)->getTokenType()->getType() == GREATER) {
            makeCode(op_exp);
            makeCode(exp2);
            file << " LES ";
        } else if (op_exp->getChild(0)->getTokenType()->getType() == SPECIAL) { //UNEQUAL = SPECIAL???
            makeCode(exp2);
            makeCode(op_exp);
            file << " NOT ";
        } else {
            makeCode(exp2);
            makeCode(op_exp);
        }
    }
}

void CodeGenerator::makeCodeExp2(Node* node) {
    Node* exp = node->getChild(0);

    if (exp != 0l) {
        makeCode(exp);
	}
}

void CodeGenerator::makeCodeExp2Identifier(Node *node) {
    Node* identifier = node->getChild(0);
    Node* index = node->getChild(1);

    file << " LA " << "$" << static_cast<IdentifierToken *>(identifier->getTokenType())->getLexem();

    if (index != 0L) {
        makeCode(index);
    }
    file << " LV ";
}

void CodeGenerator::makeCodeExp2Integer(Node *node) {
    file << " LC " << static_cast<IdentifierToken *>(node->getChild(0)->getTokenType())->getLexem();
}

void CodeGenerator::makeCodeExp2Minus(Node *node) {
    Node* exp2 = node->getChild(0);

    file << "LC " << 0;

    if(exp2 != 0L){
        makeCode(exp2);
    }
    file << " SUB ";
}

void CodeGenerator::makeCodeExp2Negation(Node *node) {
    Node* exp2 = node->getChild(0);

    if(exp2 != 0L){
        makeCode(exp2);
    }
    file << " NOT ";
}

void CodeGenerator::makeCodeIndex(Node* node) {
    Node* exp = node->getChild(0);

    if (exp != 0L) {
        makeCode(exp);
	}
    file << " ADD ";
}
void CodeGenerator::makeCodeIndex_Empty(Node* node) {}

void CodeGenerator::makeCodeOp_Exp(Node* node) {
    Node* op = node->getChild(0);
    Node* exp = node->getChild(1);

    if (op != 0L) {
        makeCode(exp);
	}

    if (exp != 0L) {
        makeCode(op);
	}
}
void CodeGenerator::makeCodeOp_Exp_Empty(Node *root){}


void CodeGenerator::makeCodeOpPlus(Node *node) {
    file << " ADD ";
}

void CodeGenerator::makeCodeOpMinus(Node *node) {
    file << " SUB ";
}

void CodeGenerator::makeCodeOpMultiplication(Node *node) {
    file << " MUL ";
}

void CodeGenerator::makeCodeOpDivision(Node *node) {
    file << " DIV ";
}

void CodeGenerator::makeCodeOpLess(Node *node) {
    file << " LES ";
}

void CodeGenerator::makeCodeOpGreater(Node *node) {
    file << " ";
}

void CodeGenerator::makeCodeOpEqual(Node *node) {
    file << " EQU ";
}

void CodeGenerator::makeCodeOpSpecial(Node *node) {
    file << " EQU ";
}

void CodeGenerator::makeCodeOpAnd(Node *node) {
    file << " AND ";
}