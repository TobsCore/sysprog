//
// Created by Kevin Wolf on 08.06.17.
// Als BitShift (Performance)?
//

#ifndef SYSPROG_NODETYPE_H
#define SYSPROG_NODETYPE_H

enum NodeType : unsigned long long {
    UNDEFINED = (unsigned long long) 0,
    INT_TYPE = (unsigned long long) 1,
    INT_ARRAY_TYPE = (unsigned long long) 1<<2,
    ARRAY_TYPE = (unsigned long long) 1<<3,
    NO_TYPE = (unsigned long long) 1<<4,
    ERROR_TYPE = (unsigned long long) 1<<5,
    OP_PLUS = (unsigned long long) 1<<6,
    OP_MINUS = (unsigned long long) 1<<7,
    OP_MULT = (unsigned long long) 1<<8,
    OP_DIV = (unsigned long long) 1<<9,
    OP_LESS = (unsigned long long) 1<<10,
    OP_GREATER = (unsigned long long) 1<<11,
    OP_EQUAL = (unsigned long long) 1<<12,
    OP_UN_EQUAL = (unsigned long long) 1<<13,
    OP_AND = (unsigned long long) 1<<14,
    EPSILON = (unsigned long long) 1<<15
};

#endif SYSPROG_NODETYPE_H
