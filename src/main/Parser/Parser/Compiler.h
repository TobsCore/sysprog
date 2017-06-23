#ifndef SYSPROG_COMPILER_H
#define SYSPROG_COMPILER_H

#include "Parser.h"
#include "SemanticAnalyser.h"
#include "CodeGenerator.h"

class Compiler {
public:
	Compiler (const char* inputfile, const char* outfile);
	~Compiler();
	void compile();
	Parser* parser;

private:
	Scanner* scanner;
	SemanticAnalyser* semanticAnalyser;
	CodeGenerator* codeGenerator;
};

#endif
