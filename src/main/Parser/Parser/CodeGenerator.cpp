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
    file << " LA " << "$" << identifier->getLexem();

    if(index != 0L){
        makeCode(index);
    }
    file << " STR ";
}

void CodeGenerator::makeCodeStatement_2(Node* node) {
    Node* exp = node->getChild(0);

	if (exp != 0L) {
        makeCode(exp);
	}
    file << " PRI ";
}

void CodeGenerator::makeCodeStatement_3(Node* node) {
    Node* identifier = node->getChild(0);
    Node* index = node->getChild(1);

    file << " REA ";
    file << " LA " << "$" << identifier->getLexem();
	if (index != 0L) {
        makeCode(index);
	}
    file << " STR ";
}

void CodeGenerator::makeCodeStatement_4(Node* node) {
    Node* statements = node->getChild(0);
	if (statements != 0L) {
        makeCode(statements);
	}
}

void CodeGenerator::makeCodeStatement_5(Node* node) {
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

void CodeGenerator::makeCodeStatement_6(Node* node) {
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
        } else if (op_exp->getChild(0)->getType() == GREATER) {
            makeCode(op_exp);
            makeCode(exp2);
            file << " LES ";
        } else if (op_exp->getChild(0)->getType() == SPECIAL) { //UNEQUAL = SPECIAL???
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

void CodeGenerator::makeCodeExp2_2(Node* node) {
    Node* identifier = node->getChild(0);
    Node* index = node->getChild(1);

    file << " LA " << "$" << identifier->getLexem() ;

    if (index != 0L) {
        makeCode(index);
    }
    file << " LV ";
}

void CodeGenerator::makeCodeExp2_3(Node* node) {
    file << " LC " << node->getChild(0)->getLexem();
}

void CodeGenerator::makeCodeExp2_4(Node* node) {
    Node* exp2 = node->getChild(0);

    file << "LC " << 0;

    if(exp2 != 0L){
        makeCode(exp2);
    }
    file << " SUB ";
}

void CodeGenerator::makeCodeExp2_5(Node* node) {
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


void CodeGenerator::makeCodeOp(Node* node) {
    file << " ADD ";
}

void CodeGenerator::makeCodeOp_2(Node* node) {
    file << " SUB ";
}

void CodeGenerator::makeCodeOp_3(Node* node) {
    file << " MUL ";
}

void CodeGenerator::makeCodeOp_4(Node* node) {
    file << " DIV ";
}

void CodeGenerator::makeCodeOp_5(Node* node) {
    file << " LES ";
}

void CodeGenerator::makeCodeOp_6(Node* node) {
    file << " ";
}

void CodeGenerator::makeCodeOp_7(Node* node) {
    file << " EQU ";
}

void CodeGenerator::makeCodeOp_8(Node* node) {
    file << " EQU ";
}

void CodeGenerator::makeCodeOp_9(Node* node) {
    file << " AND ";
}