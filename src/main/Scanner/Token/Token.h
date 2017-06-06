
#ifndef SYMTYPE
#define SYMTYPE

#include "../SymbolType/Symboltype.h"
#include "../Position/Position.h"

#endif

class Token {
public:
    Token();

    virtual ~Token();

    SymbolType getType();

    void setType(SymbolType type);

    bool isEOF();

    const char *getTypeString();

    void setPosition(Position *pos);

    void setPosition(int row, int col);

    Position *getPosition();

    int getCol();

    int getRow();

    virtual const char *toString();

protected:
    SymbolType type;
    Position *position;
};
