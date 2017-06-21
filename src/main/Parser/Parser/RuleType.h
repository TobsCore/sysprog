//
// Created by Tobias Kerst on 12.06.17.
//

#ifndef SYSPROG_RULE_H
#define SYSPROG_RULE_H

enum RuleType {
    PROG,
    DECLS,
    DECLS_EMPTY,
    DECL,
    ARRAY,
    ARRAY_EMPTY,
    STATEMENTS,
    STATEMENTS_EMPTY,
    STATEMENT_IDENTIFIER,
    STATEMENT_WRITE,
    STATEMENT_READ,
    STATEMENT_BLOCK,
    STATEMENT_IF,
    STATEMENT_WHILE,
    EXP,
	EXP2,
    EXP2_INBRACKETS,
    EXP2_IDENTIFIER,
    EXP2_INTEGER,
    EXP2_MINUS,
	EXP2_NEGATION,
    INDEX,
    INDEX_EMPTY,
    OP_EXP,
    OP_EXP_EMPTY,
    OP_PLUS,
    OP_MINUS,
    OP_MUL,
    OP_DIV,
    OP_LESS,
    OP_GREATER,
    OP_EQUAL,
    OP_SPECIAL,
	OP_AND,
    RULE_NOT_SET
};

inline const char *toString(RuleType type) {
    switch (type) {
        case PROG:
            return "PROG";
        case DECLS:
            return "DECLS";
        case DECLS_EMPTY:
            return "DECLS_EMPTY";
        case DECL:
            return "DECL";
        case ARRAY:
        	return "ARRAY";
        case ARRAY_EMPTY:
            return "ARRAY_EMPTY";
        case STATEMENTS:
            return "STATEMENTS";
        case STATEMENTS_EMPTY:
            return "STATEMENTS_EMPTY";
        case STATEMENT_IDENTIFIER:
            return "STATEMENT_IDENTIFIER";
        case STATEMENT_WRITE:
            return "STATEMENT_WRITE";
        case STATEMENT_READ:
            return "STATEMENT_READ";
        case STATEMENT_BLOCK:
            return "STATEMENT_BLOCK";
        case STATEMENT_IF:
            return "STATEMENT_IF";
        case STATEMENT_WHILE:
            return "STATEMENT_WHILE";
        case EXP:
            return "EXP";
        case EXP2:
            return "EXP2";
        case EXP2_INBRACKETS:
            return "EXP2_INBRACKETS";
        case EXP2_IDENTIFIER:
            return "EXP2_IDENTIFIER";
        case EXP2_INTEGER:
            return "EXP2_INTEGER";
        case EXP2_MINUS:
            return "EXP2_MINUS";
        case EXP2_NEGATION:
            return "EXP2_NEGATION";
        case INDEX:
            return "INDEX";
        case INDEX_EMPTY:
            return "INDEX_EMPTY";
        case OP_EXP :
            return "OP_EXP";
        case OP_EXP_EMPTY :
            return "OP_EXP_EMPTY";
        case OP_PLUS:
            return "OP_PLUS";
        case OP_MINUS:
            return "OP_MINUS";
        case OP_MUL:
            return "OP_MUL";
        case OP_DIV:
            return "OP_DIV";
        case OP_LESS:
            return "OP_LESS";
        case OP_GREATER:
            return "OP_GREATER";
        case OP_EQUAL:
            return "OP_EQUAL";
        case OP_SPECIAL:
            return "OP_SPECIAL";
        case OP_AND:
            return "OP_AND";
        case RULE_NOT_SET:
            return "RULE_NOT_SET";
        default:
            return "Unknown Rule";
    }
};

#endif //SYSPROG_RULE_H
