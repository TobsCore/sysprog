//
// Created by Tobias Kerst on 27.03.17.
//

#ifndef SYSPROG_POSITION_H
#define SYSPROG_POSITION_H


class Position {

private:
    int row;
    int column;

public:
    Position(int row, int column);

    int getRow() const;
    void setRow(int row);
    int getCol() const;
    void setCol(int column);

    void incRow();
    void incCol();
    void resetRow();
    void resetCol();

    void incRow(int incVal);
    void incCol(int incVal);
};


#endif //SYSPROG_POSITION_H
