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

private:
	Scanner* scanner;
	Parser* parser;
	SemanticAnalyser* semanticAnalyser;
	CodeGenerator* codeGenerator;
};

#endif
