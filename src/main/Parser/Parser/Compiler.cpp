#include <iostream>

#include "Compiler.h"
#include "../../colors.h"

using namespace std;

Compiler::Compiler (const char* inputfile, const char* outfile) {
	scanner = new Scanner(inputfile);
	parser = new Parser(scanner);
	semanticAnalyser = new SemanticAnalyser();
	codeGenerator = new CodeGenerator(outfile);
}

Compiler::~Compiler() {
	delete scanner;
	delete parser;
	delete semanticAnalyser;
	delete codeGenerator;
}

void Compiler::compile() {
	ParseTree* parseTree = parser->parse();

	cerr << GREEN << "run semantic analyser.." << COLOR_RESET << endl;
	Node* typedTree = semanticAnalyser->typeCheck(parseTree);

	cerr << GREEN << "run code generator.." << COLOR_RESET << endl;
	codeGenerator->runCodeGenerator(typedTree);

	cerr << GREEN << "finished compile process.." << COLOR_RESET << endl;

}
