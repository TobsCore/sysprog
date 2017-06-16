//
// Created by Kevin Wolf on 08.06.17.
//

/*
 * Nodes sind Teil des Baumes, oder der Baum selbst!
 * Node kann also Root, Branch, Leaf sein.
 *
 * Node hat Info über sich selbst.
 * Enthält er selbst weitere Nodes ist er ein Root.
 * Enthält er keine weiteren Nodes ist er Leaf.
 * Nodes werden Grammatikregeln zugeordnet.
 *
 * Dies wird für Typisierrung/TypeCheck wichtig, denn dann kann man den Teilbaum (für jede regel ein neuer) ablaufen,
 * und dann entsprechend prüfen und erkennen ob die syntax korrekt ist!
*/
#ifndef SYSPROG_NODES_H
#define SYSPROG_NODES_H

#include <climits>
#include "NodeType.h"
#include "Node.h"

#include "../../Scanner/SymbolType/Symboltype.h"
#include "RuleType.h"


class Node{

public:
    Node();
    ~Node();

    Node* getChild(unsigned char pos);
    void addChild(Node* newChild);

    void setType(NodeType type);
    NodeType getType();

    bool isLeaf();

    SymbolType getTokenType() const;
    void setTokenType(SymbolType tokenType);

    RuleType getRuleType() const;
    void setRuleType(RuleType ruleType);


    void setLexem(const char *lexem);
    const char *getLexem() const;

    void setIntegerValue(long integerValue);
    long getIntegerValue() const;

private:
    // Maximale Anzahl an Node, die Root besitzen kann
    static const unsigned char MAX_CHILDREN = UCHAR_MAX;
    unsigned char currentChild = 0;

    Node* children[MAX_CHILDREN];

    //Rule* rule; // TODO: Ich checke das mit der Rule noch nicht so wirklich.
    NodeType nodeType;
    RuleType ruleType;
    SymbolType tokenType;
    const char* lexem;
    long integerValue;
};

#endif //SYSPROG_NODES_H

