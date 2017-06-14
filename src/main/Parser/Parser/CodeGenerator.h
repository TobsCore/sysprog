//
// Created by Kevin Wolf on 13.06.17.
//

#ifndef SYSPROG_CODEGENERATOR_H
#define SYSPROG_CODEGENERATOR_H

#include <fstream>
#include "Node.h"
#include "ParseTree.h"

class Node;

class CodeGenerator {
    private:

        // Gibt den Fehler auf der Konsole aus, beendet dann das Programm.
        void error(const char* string);

        // globaler Sprungmarkenzähler
        unsigned int labelCounter;

        // Filestream zur Ausgabe des Maschinencodes
        std::ofstream file;

    public:
        /* Erzeugt je nach Regel der Grammatik den Code für einen Teilbaum.
         * Dabei wird je nach Regel eine andere Methode zur Codeerzeugung aufgerufen,
         * die dann die Reihenfolge der abarbeitung einhalten und nach den Vorgaben
         * aus dem Skript Code erzeugen.
         *
         * Die Nummerierung und bennenung der Methoden geben an um welche Regel und
         * um welchen Fall es sich handelt. So ist die Methode makeCodeDecls_2()
         * für die Grammatikregel "Decls" und dort für den zweiten Fall (Epsilon).
         *
         * makeCode() kann anhand des RuleTypes entscheiden welche dieser Methoden
         * aufgerufen werden muss.
         */
        void makeCode(Node* root);
        void makeCodeProg(Node* root);
        void makeCodeDecls(Node* root);
        void makeCodeDecls_Empty(Node* root);
        void makeCodeDecl(Node* root);
        void makeCodeArray(Node* root);
        void makeCodeArray_Empty(Node* root);
        void makeCodeStatements(Node* root);
        void makeCodeStatements_Empty(Node* root);
        void makeCodeStatement(Node* root);
        void makeCodeStatement_2(Node* root);
        void makeCodeStatement_3(Node* root);
        void makeCodeStatement_4(Node* root);
        void makeCodeStatement_5(Node* root);
        void makeCodeStatement_6(Node* root);
        void makeCodeExp(Node* root);
        void makeCodeExp2(Node* root);
        void makeCodeExp2_2(Node* root);
        void makeCodeExp2_3(Node* root);
        void makeCodeExp2_4(Node* root);
        void makeCodeExp2_5(Node* root);
        void makeCodeIndex(Node* root);
        void makeCodeIndex_Empty(Node* root);
        void makeCodeOp_Exp(Node* root);
        void makeCodeOp_Exp_Empty(Node* root);
        void makeCodeOp(Node* root);
        void makeCodeOp_2(Node* root);
        void makeCodeOp_3(Node* root);
        void makeCodeOp_4(Node* root);
        void makeCodeOp_5(Node* root);
        void makeCodeOp_6(Node* root);
        void makeCodeOp_7(Node* root);
        void makeCodeOp_8(Node* root);
        void makeCodeOp_9(Node* root);

        // Konstruktor und Dekonstruktor;
        CodeGenerator(char* out);
        virtual ~CodeGenerator();
};

#endif //SYSPROG_CODEGENERATOR_H
