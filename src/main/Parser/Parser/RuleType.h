#ifndef SYSPROG_RULETYPE_H
#define SYSPROG_RULETYPE_H

enum RuleType {
    PROG,
    DECLS, DECLS_EMPTY,
    DECL,
    ARRAY, ARRAY_Empty,
    STATEMENTS, STATEMENTS_EMPTY,
    STATEMENT_IDENTIFIER, STATEMENT_WRITE, STATEMENT_READ, STATEMENT_BRACES, STATEMENT_IF, STATEMENT_WHILE,
    EXP, EXP2_PARENS, EXP2_IDENTIFIER, EXP2_INTEGER, EXP2_NEGATIVE, EXP2_NEGATION,
    INDEX, INDEX_EMPTY,
    OP_EXP, OP_EXP_EMPTY,
    OP_PLUS, OP_MINUS, OP_MULTIPLICATION, OP_DIVISION, OP_LESS, OP_GREATER, OP_EQUALS, OP_SPECIAL, OP_AND,
    RULE_NOT_SET
};

inline const char *ToString(RuleType type) {
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
        case ARRAY_Empty:
            return "ARRAY_Empty";
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
        case STATEMENT_BRACES:
            return "STATEMENT_BRACES";
        case STATEMENT_IF:
            return "STATEMENT_IF";
        case STATEMENT_WHILE:
            return "STATEMENT_WHILE";
        case EXP:
            return "EXP";
        case EXP2_PARENS:
            return "EXP2_PARENS";
        case EXP2_IDENTIFIER:
            return "EXP2_IDENTIFIER";
        case EXP2_INTEGER:
            return "EXP2_INTEGER";
        case EXP2_NEGATIVE:
            return "EXP2_NEGATIVE";
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
        case OP_MULTIPLICATION:
            return "OP_MULTIPLICATION";
        case OP_DIVISION:
            return "OP_DIVISION";
        case OP_LESS:
            return "OP_LESS";
        case OP_GREATER:
            return "OP_GREATER";
        case OP_EQUALS:
            return "OP_EQUALS";
        case OP_SPECIAL:
            return "OP_SPECIAL";
        case OP_AND:
            return "OP_AND";
        case RULE_NOT_SET:
            return "RULE_NOT_SET";
        default:
            return "Unknown Type";
    }
};

#endif //SYSPROG_RULETYPE_H
