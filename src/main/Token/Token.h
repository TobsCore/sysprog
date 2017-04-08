
#ifndef SYMTYPE
#define SYMTYPE
#include "../SymbolType/symboltype.h"
#include "../Symtab/SymbolItem.h"
#include "../Position/Position.h"
#endif

class Token {
public:
    Token();
    
    Signtype getType();
    void setType(Signtype type);
    
    bool isEOF();
    const char* getTypeString();

    void setPosition(Position *pos);
    void setPosition(int row, int col);
    Position* getPosition();

    int getCol();
    int getRow();

    virtual const char* toString();

protected:
    Signtype type;
    Position* position;
    SymbolItem* itemSymtab;
};