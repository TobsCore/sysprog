#include <iostream>

#include "Compiler.h"
#include "../../colors.h"

using namespace std;

Compiler::Compiler (const char* inputfile, const char* outfile) {
	scanner = new Scanner(inputfile);
	parser = new Parser(scanner);
	typeChecker = new TypeChecker();
	codeGenerator = new CodeGenerator(outfile);
}

Compiler::~Compiler() {
	delete scanner;
	delete parser;
	delete typeChecker;
	delete codeGenerator;
}

void Compiler::parse() {
    this->parseTree = parser->parse();
}

void Compiler::typeCheck() {
	this->parseTree = typeChecker->typeCheck(parseTree);
}

void Compiler::runCodeGenerator() {
	codeGenerator->runCodeGenerator(parseTree);
}
