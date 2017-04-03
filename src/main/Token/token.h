
#ifndef SYMTYPE
#define SYMTYPE
#include "../SymbolType/symboltype.h"
#endif

#ifndef SYMBOLITEM
#define SYMBOLITEM
#include "../Symtab/SymbolItem.h"
#endif

#ifndef POSITION
#define POSITION
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

    SymbolItem* getItem();
    void setItem(SymbolItem* itemSymtab);

private:
    
    char* value;
    Signtype type;
    Position* position;
    SymbolItem* itemSymtab;

};

