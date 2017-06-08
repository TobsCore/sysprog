//
// Created by Kevin Wolf on 08.06.17.
//

/*
 * Nodes sind Teil des Baumes, oder der Baum selbst.
 * Node kann also Root, Branch, Leaf sein.
 *
 * Node hat Info über sich selbst.
 * Enthält er selbst weitere Nodes ist er eine Root.
 * Enthält er keine weiteren Nodes ist er Leaf.
 * Nodes werden Grammatikregeln zugeordnet.
*/
#ifndef SYSPROG_NODES_H
#define SYSPROG_NODES_H

#include "NodeType.h"
#include "Nodes.h

class Nodes{

private:
    // Maximale Anzahl an Nodes, die Root besitzen kann
    static const short __SIZE = 20;

    // aktueller Node einer Root
    int currentBranch = 0;

    // Node = Leaf? Wegen Get und Set
    bool isALeaf;

    // Nodes einer Root
    Node* branches[__SIZE];

    // zugeordnete Regel
    Rule* rule;

    // Informationen über den Inhalt
    TokenInfo* tokenInfo;

    // NodeType
    NodeInfo nodeTypeInfo;

    // Typ des Inhaltes
    TType type;

public:
    // allgemeiner Konstruktor
    Node();

    // Konstruktor für ein Blatt
    Node(TokenInfo* info);

    // Dekonstruktor
    virtual ~Node();

    // Fügt eine Node zu einer Wurzel hinzu
    void addBranch(Node* branch);

    // gibt ein  Blatt oder ein Teilbaum einer Wurzel zurück
    Node* getBranch(int pos);

    void setRule(Rule* rule);

    Rule* getRule();

    void setNodeTypeInfo(NodeInfo info);

    NodeInfo getNodeTypeInfo();

    void setType(TType type);

    TType getType();

    void setTokenInfo(TokenInfo* tokenInfo);

    TokenInfo* getTokenInfo();

    void setLeaf();

    bool isLeaf();
};

#endif //SYSPROG_NODES_H
