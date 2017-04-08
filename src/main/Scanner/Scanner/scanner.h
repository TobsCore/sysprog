#ifndef TOKEN
#define TOKEN
#include "../../Token/Token.h"
#endif

#ifndef SYMTYPE
#define SYMTYPE
#include "../../SymbolType/symboltype.h"
#endif

#ifndef BUFFER
#define BUFFER
#include "../Buffer/Buffer.h"
#endif

#ifndef AUTOMAT
#define AUTOMAT
#include "../Automat/automat.h"
#endif

#ifndef SYMBOLTABLE
#define SYMBOLTABLE
#include "../../Symtab/Symboltable.h"
#endif

class Scanner {

public:
	Scanner(char const *filePath);
	~Scanner();

	Token* nextToken();

private:
	Buffer* buffer;
	Automat* automat;
	Position* currentPosition;
    Position *nextTokenPosition;
    Position *currentTokenPosition;

    Symboltable* symboltable;


	void setTokenPosition(Token *token);
    void setCurrentPosition(char c, Signtype type);

    bool firstToken;
    int tokenSize;
    int countSpace;
    int countChars;
};
