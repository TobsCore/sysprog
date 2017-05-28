#ifndef SYMTYPE
#define SYMTYPE
#include "../../SymbolType/Symboltype.h"
#endif

class Automat {

public:
	Automat();
	SymbolType checkExpression(char currentChar);

private:
	int findColumn(char currentChar);

	int currentState;
	int newState;
	int column;


};
