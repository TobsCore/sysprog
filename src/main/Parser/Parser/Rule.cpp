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
            //return
        case DECLS:
        case DECLS_EMPTY:
            //return
        case DECL:
            //return
        case ARRAY:
        case ARRAY_EMPTY:
            //return
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
            //return
        case EXP2:
        case EXP2_INBRACKETS:
        case EXP2_IDENTIFIER:
        case EXP2_INTEGER:
        case EXP2_MINUS:
        case EXP2_NEGATION:
            return PARANTHESES_LEFT | IDENTIFIER | INTEGER | MINUS | EXCLAMATION;
        case INDEX:
        case INDEX_EMPTY:
            //return
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
            //return
        case ARRAY:
        case ARRAY_EMPTY:
            //return
        case STATEMENTS:
        case STATEMENTS_EMPTY:
            //return
        case INDEX:
        case INDEX_EMPTY:
            //return
        case OP_EXP:
        case OP_EXP_EMPTY:
            //return
        default:
            return 0;
    }}

// ToDo man muss noch die neuen Teile der Grammatik in den Automaten adden.
// also: add return values to the cases. therefore we should discuss the given grammar in the group.
// this is propably easy (pdfs), but i'd like to discuss it just to be sure. better safe that awp! *dies by headshot*