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
#include <climits>
#include "NodeType.h"
#include "RuleType.h"
#include "../../Scanner/Token/Token.h"

#ifndef NODE_H
#define NODE_H
class Node{

public:
    Node();
    Node(RuleType ruleType);
    ~Node();

    Node* getChild(unsigned char pos);
    void addChild(Node* newChild);

    void setType(NodeType type);
    NodeType getType();

    bool isLeaf();

    RuleType getRuleType() const;
    void setRuleType(RuleType ruleType);

    Token *getToken() const;
    void setToken(Token *token);

    unsigned char getAmountOfChildren();

private:
    // Maximale Anzahl an Node, die Root besitzen kann
    static const unsigned char MAX_CHILDREN = UCHAR_MAX;
    unsigned char currentChild = 0;

    Node* children[MAX_CHILDREN];

    NodeType nodeType;
    RuleType ruleType;
    Token *token;
};
#endif
