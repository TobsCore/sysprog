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

//STATEMENTS ::= STATEMENT_IDENTIFIER ; STATEMENTS)
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

//STATEMENT_IDENTIFIER ::= identifier INDEX := EXP
void CodeGenerator::generateCodeStatement(Node *node) {
	Node* exp = node->getChildren(2);
	Node* index = node->getChildren(1);
	Node* identifier = node->getChildren(0);

	generateCode(exp);
	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem();
	generateCode(index);
	*outText << " STR ";
}

//STATEMENT_IDENTIFIER ::= write( EXP )
void CodeGenerator::generateCodeStatement_2(Node* node) {
	Node* exp = node->getChildren(0);
	generateCode(exp);

	*outText << " PRI ";
}

//STATEMENT_IDENTIFIER ::= read( identifier INDEX)
void CodeGenerator::generateCodeStatement_3(Node* node) {
	Node* identifier = node->getChildren(0);
	Node* index = node->getChildren(1);


	*outText << " REA ";
	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem();

	generateCode(index);

	*outText << " STR ";
}

//STATEMENT_IDENTIFIER ::= { STATEMENTS }
void CodeGenerator::generateCodeStatement_4(Node* node) {
	Node* statements = node->getChildren(0);
	generateCode(statements);
}

//STATEMENT_IDENTIFIER ::= if ( EXP ) STATEMENT_IDENTIFIER else STATEMENT_IDENTIFIER
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

//STATEMENT_IDENTIFIER ::= while ( EXP ) STATEMENT_IDENTIFIER)
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

//EXP ::= EXP2_PARENS OP_EXP
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

//EXP2_PARENS ::= identifier INDEX
void CodeGenerator::generateCodeExp2_2(Node* node) {
	Node* identifier = node->getChildren(0);
	Node* index = node->getChildren(1);

	*outText << " LA " << "$" << static_cast<IdentifierToken*>(identifier->getToken())->getLexem() ;

	generateCode(index);

	*outText << " LV ";
}

//EXP2_PARENS ::= integer
void CodeGenerator::generateCodeExp2_3(Node* node) {
	*outText << " LC " << node->getChildren(0)->getIntegerValue();
}

//EXP2_PARENS ::= - EXP2_PARENS
void CodeGenerator::generateCodeExp2_4(Node* node) {
	Node *exp2 = node->getChildren(0);

	*outText << "LC " << 0;
	generateCode(exp2);
	*outText << " SUB ";
}

//EXP2_PARENS ::= ! EXP2_PARENS
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

//OP_EXP ::= OP_PLUS EXP
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
		case DECLS_EMPTY:
			generateCodeDecls_2();
			break;
		case DECL:
			generateCodeDecl(node);
			break;
		case ARRAY:
			generateCodeArray(node);
			break;
		case ARRAY_Empty:
			generateCodeArray_2();
			break;
		case STATEMENTS:
			generateCodeStatements(node);
			break;
		case STATEMENTS_EMPTY:
			generateCodeStatements_2();
			break;
		case STATEMENT_IDENTIFIER:
			generateCodeStatement(node);
			break;
		case STATEMENT_WRITE:
			generateCodeStatement_2(node);
			break;
		case STATEMENT_READ:
			generateCodeStatement_3(node);
			break;
		case STATEMENT_BRACES:
			generateCodeStatement_4(node);
			break;
		case STATEMENT_IF:
			generateCodeStatement_5(node);
			break;
		case STATEMENT_WHILE:
			generateCodeStatement_6(node);
			break;
		case EXP:
			generateCodeExp(node);
			break;
		case EXP2_PARENS:
			generateCodeExp2(node);
			break;
		case EXP2_IDENTIFIER:
			generateCodeExp2_2(node);
			break;
		case EXP2_INTEGER:
			generateCodeExp2_3(node);
			break;
		case EXP2_NEGATIVE:
			generateCodeExp2_4(node);
			break;
		case EXP2_NEGATION:
			generateCodeExp2_5(node);
			break;
		case INDEX:
			generateCodeIndex(node);
			break;
		case INDEX_EMPTY:
			generateCodeIndex_2();
			break;
		case OP_EXP:
			generateCodeOp_Exp(node);
			break;
		case OP_EXP_EMPTY:
			generateCodeOp_Exp_2();
			break;
		case OP_PLUS:
			generateCodeOp();
			break;
		case OP_MINUS:
			generateCodeOp_2();
			break;
		case OP_MULTIPLICATION:
			generateCodeOp_3();
			break;
		case OP_DIVISION:
			generateCodeOp_4();
			break;
		case OP_LESS:
			generateCodeOp_5();
			break;
		case OP_GREATER:
			generateCodeOp_6();
			break;
		case OP_EQUALS:
			generateCodeOp_7();
			break;
		case OP_SPECIAL:
			generateCodeOp_8();
			break;
		case OP_AND:
			generateCodeOp_9();
			break;
		default:
			cerr << "node is empty" << endl;
	}
}
