#include "../Token/Token.h"
#include "../SymbolType/Symboltype.h"
#include "../Buffer/Buffer.h"
#include "../Automat/Automat.h"
#include "../SymbolTable/SymbolTable.h"

#ifndef SCANNER_H
#define SCANNER_H
static const int bufferSize = 255;

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

#endif
