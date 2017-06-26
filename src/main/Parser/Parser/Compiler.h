#ifndef SYSPROG_COMPILER_H
#define SYSPROG_COMPILER_H

#include "Parser.h"
#include "TypeChecker.h"
#include "CodeGenerator.h"

class Compiler {
public:
	Compiler (const char* inputfile, const char* outfile);
	~Compiler();
    void parse();
	void typeCheck();
	void runCodeGenerator();

private:
	Parser* parser;
	Scanner* scanner;
	TypeChecker* typeChecker;
	CodeGenerator* codeGenerator;
    ParseTree* parseTree;
};

#endif
