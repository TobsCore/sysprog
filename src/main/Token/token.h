#ifndef SYMTYPE
#define SYMTYPE
#include "../SymbolType/symboltype.h"
#include "../Position/Position.h"

#endif

class Token {
public:
    Token();
    
    char* getValue();
    void setValue(char* value);
    
    Signtype getType();
    void setType(Signtype type);
    
    bool isEOF();
    const char* getTypeString();

    void setPosition(Position *pos);
    void setPosition(int row, int col);
    Position* getPosition();

    int getCol();
    int getRow();

private:
    
    char* value;
    Signtype type;
    Position* position;

};

