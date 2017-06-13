//
// Created by Kevin Wolf on 08.06.17.
//

#include "Rule.h"
#include "../../Scanner/SymbolType/Symboltype.h"

Rule::Rule(RuleType type) {
    this->type = type;
    this->first = this->codeFirst(type);
    this->follow = this->codeFollow(type);
}

RuleType Rule::getRuleType() {
    return this->type;
}

unsigned long long Rule::getFirst() {
    return this->first;
}

unsigned long long Rule::getFollow() {
    return this->follow;
}

void Rule::setRuleType(RuleType ruleType) {
    this->type = ruleType;
}


unsigned long long Rule::codeFirst(RuleType type) {
    switch (type) {
        case PROG:
            return INTTOKEN | IDENTIFIER | WRITETOKEN | READTOKEN | BRACES_LEFT | IFTOKEN | WHILETOKEN | FILE_END;
        case DECLS:
        case DECLS_EMPTY:
            return INTTOKEN;
        case DECL:
            return INTTOKEN;
        case ARRAY:
        case ARRAY_EMPTY:
            return BRACKET_LEFT;
        case STATEMENTS:
        case STATEMENTS_EMPTY:
            return IDENTIFIER | WRITETOKEN | READTOKEN | BRACES_LEFT | IFTOKEN | WHILETOKEN;
        case STATEMENT:
        case STATEMENT_2:
        case STATEMENT_3:
        case STATEMENT_4:
        case STATEMENT_5:
        case STATEMENT_6:
            return IDENTIFIER | WRITETOKEN | READTOKEN | BRACES_LEFT | IFTOKEN | WHILETOKEN;
        case EXP:
            return PARANTHESES_LEFT | IDENTIFIER | INTEGER | MINUS | EXCLAMATION;
        case EXP2:
        case EXP2_2:
        case EXP2_3:
        case EXP2_4:
        case EXP2_5:
            return PARANTHESES_LEFT | IDENTIFIER | INTEGER | MINUS | EXCLAMATION;
        case INDEX:
        case INDEX_EMPTY:
            return BRACKET_LEFT;
        case OP_EXP:
        case OP_EXP_EMPTY:
            return PLUS | MINUS | STAR | COLON | LESS | GREATER | EQUALS | SPECIAL | AND;
        case OP:
        case OP_2:
        case OP_3:
        case OP_4:
        case OP_5:
        case OP_6:
        case OP_7:
        case OP_8:
        case OP_9:
            return PLUS | MINUS | STAR | COLON | LESS | GREATER | EQUALS | SPECIAL | AND;
        default:
            return 0;
    }}

unsigned long long Rule::codeFollow(RuleType type) {
    switch (type) {
        case DECLS:
        case DECLS_EMPTY:
            return IDENTIFIER | WRITETOKEN | READTOKEN | BRACES_LEFT | IFTOKEN | WHILETOKEN | FILE_END;
        case ARRAY:
        case ARRAY_EMPTY:
            return IDENTIFIER;
        case STATEMENTS:
        case STATEMENTS_EMPTY:
            return BRACES_RIGHT | FILE_END;
        case INDEX:
        case INDEX_EMPTY:
            return ASSIGN | PARANTHESES_RIGHT | PLUS | MINUS | STAR | COLON | LESS | GREATER | EQUALS | AND | BRACKET_RIGHT | ELSETOKEN | SEMICOLON;
        case OP_EXP:
        case OP_EXP_EMPTY:
            return BRACKET_RIGHT | PARANTHESES_RIGHT | ELSETOKEN | SEMICOLON;
        default:
            return 0;
    }}

