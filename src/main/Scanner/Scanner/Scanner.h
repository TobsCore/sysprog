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
#include "../Automat/Automat.h"
#endif

#ifndef SYMBOLTABLE
#define SYMBOLTABLE
#include "../../SymbolTable/SymbolTable.h"
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

    SymbolTable* symboltable;


	void setTokenPosition(Token *token);
    void setCurrentPosition(char c, SymbolType type);

    bool firstToken;
    int countSpace;
    int countChars;
    bool isInComment;
    int commentCounter;

	void checkInComment(const SymbolType &symbol);
};
