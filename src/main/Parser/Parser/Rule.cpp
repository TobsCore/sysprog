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
        case STATEMENT_IDENTIFIER:
        case STATEMENT_WRITE:
        case STATEMENT_READ:
        case STATEMENT_BLOCK:
        case STATEMENT_IF:
        case STATEMENT_WHILE:
            return IDENTIFIER | WRITETOKEN | READTOKEN | BRACES_LEFT | IFTOKEN | WHILETOKEN;
        case EXP:
            return PARANTHESES_LEFT | IDENTIFIER | INTEGER | MINUS | EXCLAMATION;
        case EXP2:
        case EXP2_INBRACKETS:
        case EXP2_IDENTIFIER:
        case EXP2_INTEGER:
        case EXP2_MINUS:
        case EXP2_NEGATION:
            return PARANTHESES_LEFT | IDENTIFIER | INTEGER | MINUS | EXCLAMATION;
        case INDEX:
        case INDEX_EMPTY:
            return BRACKET_LEFT;
        case OP_EXP:
        case OP_EXP_EMPTY:
            return PLUS | MINUS | STAR | COLON | LESS | GREATER | EQUALS | SPECIAL | AND;
        case OP_PLUS:
        case OP_MINUS:
        case OP_MUL:
        case OP_DIV:
        case OP_LESS:
        case OP_GREATER:
        case OP_EQUAL:
        case OP_SPECIAL:
        case OP_AND:
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

