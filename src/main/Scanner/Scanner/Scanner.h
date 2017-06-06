#ifndef TOKEN
#define TOKEN

#include "../Token/Token.h"

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
static const int bufferSize = 255;

#include "../SymbolTable/SymbolTable.h"

#endif

class Scanner {

public:
    Scanner(char const *filePath);

    ~Scanner();

    Token *nextToken();

private:
    Buffer *buffer;
    Automat *automat;
    Position *currentPosition;
    Position *nextTokenPosition;
    Position *currentTokenPosition;

    SymbolTable *symboltable;


    Position *tokenPosition();

    void setCurrentPosition(char c);

    bool firstToken;
    int countSpace;
    int countChars;
    bool isInComment;
    int commentCounter;

    char *lexem;
    int i;

    void checkInComment(const SymbolType &symbol);
};
