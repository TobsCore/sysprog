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
    bool isTreeLeaf;

    // Nodes einer Root
    Nodes* branches[__SIZE];

    // zugeordnete Regel
    Rule* rule;

    // NodeType
    NodeInfo nodeTypeInfo;

    // Typ des Inhaltes
    //ToDo

    // Informationen über den Inhalt
    //ToDO

public:
    // allgemeiner Konstruktor
    Nodes();

    // Konstruktor für ein Blatt
    //ToDo

    // Dekonstruktor
    virtual ~Nodes();

    // Fügt eine Node zu einer Wurzel hinzu
    void newBranch(Nodes* branch);

    // gibt ein  Blatt oder ein Teilbaum einer Wurzel zurück
    Nodes* getBranch(int pos);

//setter getter rules noch zu machen

    void setNodeTypeInfo(NodeInfo info);

    NodeInfo getNodeTypeInfo();

    void setTreeLeaf();

    bool isTreeLeaf();
};

#endif //SYSPROG_NODES_H
