#include "CodeGenerator.h"
#include "../../Scanner/Token/IdentifierToken.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

CodeGenerator::CodeGenerator(const char* outfile) {
	codeFile = new ofstream(outfile);
	outText = new stringstream();
	labelCounter = 0;
}

CodeGenerator::~CodeGenerator() {
	codeFile->close();
	delete codeFile;
	delete outText;
}

void CodeGenerator::runCodeGenerator(ParseTree *parseTree) {
    Node *root = parseTree->getTree();
	generateCodeProg(root);
	*codeFile << outText->rdbuf();
	codeFile->flush();
	outText->str(string());
}

//PROG ::= DECLS STATEMENTS
void CodeGenerator::generateCodeProg(Node *root) {
	Node* decls = root->getChildren(0);
	Node* statements = root->getChildren(1);

	generateCode(decls);
	generateCode(statements);

	*outText << "STP";
}

//DECLS ::= DECL ; DECLS
void CodeGenerator::generateCodeDecls(Node* node) {
	Node* decl = node->getChildren(0);
	Node* decls = node->getChildren(1);

	generateCode(decl);
	generateCode(decls);
}

//DECLS ::= e
void CodeGenerator::generateCodeDecls_2() {
	//NOP
}

//DECL::= int ARRAY identifier
void CodeGenerator::generateCodeDecl(Node *node) {
	Node* array = node->getChildren(0);
	Node* identifier = node->getChildren(1);

	*outText << " DS " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem();

	generateCode(array);
}

//ARRAY::=[integer]
void CodeGenerator::generateCodeArray(Node* node) {
	Node* array = node->getChildren(0);
	*outText << " " <<array->getIntegerValue();
}

//ARRAY ::= e
void CodeGenerator::generateCodeArray_2() {
	*outText << " " << 1;
}

//STATEMENTS ::= STATEMENT ; STATEMENTS)
void CodeGenerator::generateCodeStatements(Node *node) {
	Node* statement = node->getChildren(0);
	Node* statements = node->getChildren(1);

	generateCode(statement);

	if(statement != 0L) {
		generateCode(statements);
	}
}

//STATEMENTS ::= e
void CodeGenerator::generateCodeStatements_2() {
	*outText << " NOP ";
}

//STATEMENT ::= identifier INDEX := EXP
void CodeGenerator::generateCodeStatement(Node *node) {
	Node* exp = node->getChildren(2);
	Node* index = node->getChildren(1);
	Node* identifier = node->getChildren(0);

	generateCode(exp);
	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem();
	generateCode(index);
	*outText << " STR ";
}

//STATEMENT ::= write( EXP )
void CodeGenerator::generateCodeStatement_2(Node* node) {
	Node* exp = node->getChildren(0);
	generateCode(exp);

	*outText << " PRI ";
}

//STATEMENT ::= read( identifier INDEX)
void CodeGenerator::generateCodeStatement_3(Node* node) {
	Node* identifier = node->getChildren(0);
	Node* index = node->getChildren(1);


	*outText << " REA ";
	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem();

	generateCode(index);

	*outText << " STR ";
}

//STATEMENT ::= { STATEMENTS }
void CodeGenerator::generateCodeStatement_4(Node* node) {
	Node* statements = node->getChildren(0);
	generateCode(statements);
}

//STATEMENT ::= if ( EXP ) STATEMENT else STATEMENT
void CodeGenerator::generateCodeStatement_5(Node* node) {
	Node* exp = node->getChildren(0);
	Node* statement1 = node->getChildren(1);
	Node* statement2 = node->getChildren(2);
	int label1 = ++labelCounter;
	int label2 = ++labelCounter;


	generateCode(exp);

	*outText << " JIN " << "#label" << label1 <<" ";

	generateCode(statement1);

	*outText << " JMP " << "#label" << label2 <<" ";
	*outText << "#label" << label1 << " NOP ";

	generateCode(statement2);

	*outText << "#label" << label2 << " NOP ";
}

//STATEMENT ::= while ( EXP ) STATEMENT)
void CodeGenerator::generateCodeStatement_6(Node* node) {
	Node* exp = node->getChildren(0);
	Node* statement = node->getChildren(1);

	int label1 = ++labelCounter;
	int label2 = ++labelCounter;

	*outText << "#label" << label1 << " NOP ";

	generateCode(exp);

	*outText << " JIN " << "#label" << label2 <<" ";

	generateCode(statement);

	*outText << " JMP " << "#label" << label1 <<" ";
	*outText << "#label" << label2 << " NOP ";
}

//EXP ::= EXP2 OP_EXP
void CodeGenerator::generateCodeExp(Node* node) {
	Node* exp2 = node->getChildren(0);
	Node* op_exp = node->getChildren(1);

	if(op_exp->getNodeType() == NO_TYPE) {
		generateCode(exp2);

	} else if (op_exp->getChildren(0)->getNodeType() == OP_GREATER_TYPE) {
		generateCode(op_exp);
		generateCode(exp2);
		*outText << " LES ";

	} else if (op_exp->getChildren(0)->getNodeType() == OP_UN_EQUAL_TYPE) {
		generateCode(exp2);
		generateCode(op_exp);
		*outText << " NOT ";

	} else {
		generateCode(exp2);
		generateCode(op_exp);
	}
}

//INDEX ::= [ EXP ]
void CodeGenerator::generateCodeExp2(Node* node) {
	Node* exp = node->getChildren(0);
	generateCode(exp);
}

//EXP2 ::= identifier INDEX
void CodeGenerator::generateCodeExp2_2(Node* node) {
	Node* identifier = node->getChildren(0);
	Node* index = node->getChildren(1);

	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem() ;

	generateCode(index);

	*outText << " LV ";
}

//EXP2 ::= integer
void CodeGenerator::generateCodeExp2_3(Node* node) {
	*outText << " LC " << node->getChildren(0)->getIntegerValue();
}

//EXP2 ::= - EXP2
void CodeGenerator::generateCodeExp2_4(Node* node) {
	Node *exp2 = node->getChildren(0);

	*outText << "LC " << 0;
	generateCode(exp2);
	*outText << " SUB ";
}

//EXP2 ::= ! EXP2
void CodeGenerator::generateCodeExp2_5(Node* node) {
	Node* exp2 = node->getChildren(0);

	generateCode(exp2);
	*outText << " NOT ";
}

//INDEX ::= [ EXP ]
void CodeGenerator::generateCodeIndex(Node* node) {
	Node* exp = node->getChildren(0);

	generateCode(exp);
	*outText << " ADD ";
}

//INDEX ::= e
void CodeGenerator::generateCodeIndex_2() {
	//NOP
}

//OP_EXP ::= OP EXP
void CodeGenerator::generateCodeOp_Exp(Node* node) {
	Node* op = node->getChildren(0);
	Node* exp = node->getChildren(1);

	generateCode(exp);
	generateCode(op);
}

//OP_EXP ::= e
void CodeGenerator::generateCodeOp_Exp_2() {
	//NOP
}

void CodeGenerator::generateCodeOp() {
	*outText << " ADD ";
}


void CodeGenerator::generateCodeOp_2() {
	*outText << " SUB ";
}

void CodeGenerator::generateCodeOp_3() {
	*outText << " MUL ";
}

void CodeGenerator::generateCodeOp_4() {
	*outText << " DIV ";
}

void CodeGenerator::generateCodeOp_5() {
	*outText << " LES ";
}

void CodeGenerator::generateCodeOp_6() {
	*outText << "  ";
}

void CodeGenerator::generateCodeOp_7() {
	*outText << " EQU ";

}

void CodeGenerator::generateCodeOp_8() {
	*outText << " EQU ";
}

void CodeGenerator::generateCodeOp_9() {
	*outText << " AND ";
}

void CodeGenerator::generateCode(Node* node) {

	if(node == 0L) {
		//cout << "node is null" << endl;
		return;
	}

	//cout << "generateCode: " << ToString(node->getRuleType()) << endl;
	switch(node->getRuleType()) {
		case PROG:
			generateCodeProg(node);
			break;
		case DECLS:
			generateCodeDecls(node);
			break;
		case DECLS_2:
			generateCodeDecls_2();
			break;
		case DECL:
			generateCodeDecl(node);
			break;
		case ARRAY:
			generateCodeArray(node);
			break;
		case ARRAY_2:
			generateCodeArray_2();
			break;
		case STATEMENTS:
			generateCodeStatements(node);
			break;
		case STATEMENTS_2:
			generateCodeStatements_2();
			break;
		case STATEMENT:
			generateCodeStatement(node);
			break;
		case STATEMENT_2:
			generateCodeStatement_2(node);
			break;
		case STATEMENT_3:
			generateCodeStatement_3(node);
			break;
		case STATEMENT_4:
			generateCodeStatement_4(node);
			break;
		case STATEMENT_5:
			generateCodeStatement_5(node);
			break;
		case STATEMENT_6:
			generateCodeStatement_6(node);
			break;
		case EXP:
			generateCodeExp(node);
			break;
		case EXP2:
			generateCodeExp2(node);
			break;
		case EXP2_2:
			generateCodeExp2_2(node);
			break;
		case EXP2_3:
			generateCodeExp2_3(node);
			break;
		case EXP2_4:
			generateCodeExp2_4(node);
			break;
		case EXP2_5:
			generateCodeExp2_5(node);
			break;
		case INDEX:
			generateCodeIndex(node);
			break;
		case INDEX_2:
			generateCodeIndex_2();
			break;
		case OP_EXP:
			generateCodeOp_Exp(node);
			break;
		case OP_EXP_2:
			generateCodeOp_Exp_2();
			break;
		case OP:
			generateCodeOp();
			break;
		case OP_2:
			generateCodeOp_2();
			break;
		case OP_3:
			generateCodeOp_3();
			break;
		case OP_4:
			generateCodeOp_4();
			break;
		case OP_5:
			generateCodeOp_5();
			break;
		case OP_6:
			generateCodeOp_6();
			break;
		case OP_7:
			generateCodeOp_7();
			break;
		case OP_8:
			generateCodeOp_8();
			break;
		case OP_9:
			generateCodeOp_9();
			break;
		default:
			cerr << "node is empty" << endl;
	}
}
