//
// Created by Kevin Wolf on 08.06.17.
//
#include "RuleType.h"

#ifndef SYSPROG_RULES_H
#define SYSPROG_RULES_H

class Rules {
private:
    RuleType type;

    // First-Menge
    unsigned long long first;

    // Follow-Menge
    unsigned long long follow;

    // FirstMenge in Bezug auf Regeltyp
    unsigned long long codeFirst(RuleType type);

    // FollowMenge in Bezug auf Regeltyp
    unsigned long long codeFollow(RuleType type);

public:
    Rules(RuleType type);

    unsigned long long getFirst();

    unsigned long long getFollow();

    RuleType getRuleType();

    void setRuleType(RuleType ruleType);
};

//ToDo man muss noch die neuen Teile der Grammatik in den Automaten adden.

#endif //SYSPROG_RULES_H
