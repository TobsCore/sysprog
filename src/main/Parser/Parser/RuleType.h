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
    STATEMENT,
    STATEMENT_2,
    STATEMENT_3,
    STATEMENT_4,
    STATEMENT_5,
    STATEMENT_6,
    EXP,
    EXP2,
    EXP2_2,
    EXP2_3,
    EXP2_4,
    EXP2_5,
    INDEX,
    INDEX_EMPTY,
    OP_EXP,
    OP_EXP_EMPTY,
    OP,
    OP_2,
    OP_3,
    OP_4,
    OP_5,
    OP_6,
    OP_7,
    OP_8,
    OP_9,
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
        case ARRAY_EMPTY:
            return "ARRAY_EMPTY";
        case STATEMENTS:
            return "STATEMENTS";
        case STATEMENTS_EMPTY:
            return "STATEMENTS_EMPTY";
        case STATEMENT:
            return "STATEMENT";
        case STATEMENT_2:
            return "STATEMENT_2";
        case STATEMENT_3:
            return "STATEMENT_3";
        case STATEMENT_4:
            return "STATEMENT_4";
        case STATEMENT_5:
            return "STATEMENT_5";
        case STATEMENT_6:
            return "STATEMENT_6";
        case EXP:
            return "EXP";
        case EXP2:
            return "EXP2";
        case EXP2_2:
            return "EXP2_2";
        case EXP2_3:
            return "EXP2_3";
        case EXP2_4:
            return "EXP2_4";
        case EXP2_5:
            return "EXP2_5";
        case INDEX:
            return "INDEX";
        case INDEX_EMPTY:
            return "INDEX_EMPTY";
        case OP_EXP :
            return "OP_EXP";
        case OP_EXP_EMPTY :
            return "OP_EXP_EMPTY";
        case OP:
            return "OP";
        case OP_2:
            return "OP_2";
        case OP_3:
            return "OP_3";
        case OP_4:
            return "OP_4";
        case OP_5:
            return "OP_5";
        case OP_6:
            return "OP_6";
        case OP_7:
            return "OP_7";
        case OP_8:
            return "OP_8";
        case OP_9:
            return "OP_9";
        case RULE_NOT_SET:
            return "RULE_NOT_SET";
        default:
            return "Unknown Rule";
    }
};

#endif //SYSPROG_RULE_H
