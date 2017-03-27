//
// Created by Tobias Kerst on 27.03.17.
//

#include "Position.h"

Position::Position(int row, int column) {
    this->row = row;
    this->column = column;
}

int Position::getRow() const {
    return row;
}

void Position::setRow(int row) {
    Position::row = row;
}

int Position::getCol() const {
    return column;
}

void Position::setCol(int column) {
    Position::column = column;
}

void Position::incRow() {
    incRow(1);
}

void Position::incRow(int incVal) {
    Position::row += incVal;
}

void Position::incCol() {
    incCol(1);
}

void Position::incCol(int incVal) {
    Position::column += incVal;
}

void Position::resetRow() {
    Position::row = 1;
}

void Position::resetCol() {
    Position::column = 1;
}
