#ifndef SYMTYPE
#define SYMTYPE
#include "../SymbolType/symboltype.h"
#endif

class Token {
public:
    Token();
    
    char* getValue();
    void setValue(char* value);
    
    Signtype getType();
    void setType(Signtype type);
    
    int getColumn();
    void setColumn(int column);
    
    int getRow();
    void setRow(int row);
    
    bool isEOF();

private:
    
    char* value;
    Signtype type;
    int column;
    int row;
};

