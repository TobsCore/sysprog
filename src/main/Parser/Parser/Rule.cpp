//
// Created by Kevin Wolf on 08.06.17.
//

#include "Rule.h"

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
            //return
        case STATEMENT:
        case STATEMENT_2:
        case STATEMENT_3:
        case STATEMENT_4:
        case STATEMENT_5:
        case STATEMENT_6:
            //return
        case EXP:
            //return
        case EXP2:
        case EXP2_2:
        case EXP2_3:
        case EXP2_4:
        case EXP2_5:
            //return
        case INDEX:
        case INDEX_EMPTY:
            //return
        case OP_EXP:
        case OP_EXP_EMPTY:
            //return
        case OP:
        case OP_2:
        case OP_3:
        case OP_4:
        case OP_5:
        case OP_6:
        case OP_7:
        case OP_8:
        case OP_9:
            //return
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