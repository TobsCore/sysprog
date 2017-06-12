//
// Created by Kevin Wolf on 08.06.17.
//

/*
 * Nodes sind Teil des Baumes, oder der Baum selbst!
 * Node kann also Root, Branch, Leaf sein.
 *
 * Node hat Info über sich selbst.
 * Enthält er selbst weitere Nodes ist er eine Root.
 * Enthält er keine weiteren Nodes ist er Leaf.
 * Nodes werden Grammatikregeln zugeordnet.
 *
 * Dies wird für Typisierrung/TypeCheck wichtig, denn dann kann man den Teilbaum (für jede regel ein neuer) ablaufen,
 * und dann entsprechend prüfen und erkennen ob die syntax korrekt ist!
*/
#ifndef SYSPROG_NODES_H
#define SYSPROG_NODES_H

#include "NodeType.h"
#include "Nodes.h"

class Rules;

class Nodes{

private:
    // Maximale Anzahl an Nodes, die Root besitzen kann
    static const short __SIZE = 20;

    // aktueller Node einer Root
    int currentBranch = 0;

    // Node = Leaf? Wegen Get und Set
    bool isLeaf;

    // Nodes einer Root
    Nodes* branches[__SIZE];

    // dem Node zugeordnete Regel
    Rules* rule;

    // NodeType
    NodeType nodeTypeInfo;

    // Typ des Inhaltes
    //ToDo

    // Informationen über den Inhalt
    //ToDO

public:
    Nodes();
    ~Nodes();

    // Konstruktor für Leaf
    //ToDo

    // Fügt eine Node zu einer Wurzel hinzu
    void newBranch(Nodes* branch);

    Nodes* getBranch(int pos);

//setter getter rules noch zu machen

    void setNodeTypeInfo(NodeType info);

    NodeType getNodeTypeInfo();

    void setTreeLeaf();

    bool isTreeLeaf();
};

#endif //SYSPROG_NODES_H

//auch ToDo: Leaf mit Token Informationen befüllen (lexem, lexemtyp, nodetyp ??)