#include "../SymbolType/Symboltype.h"

#ifndef AUTOMAT
#define AUTOMAT
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
#endif
