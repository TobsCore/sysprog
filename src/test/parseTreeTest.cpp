//
// Created by Tobias Kerst on 18.06.17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Parser.h"


TEST(ParseTreeTest, ChangeThisName) {
    Node *root = new Node();
    root->setRuleType(RuleType::PROG);

    ParseTree *parseTree = new ParseTree(root);
}

TEST(ParseTreeTest, WrongRootNodeType) {
    Node *root = new Node();
    root->setRuleType(RuleType::DECLS);

    ASSERT_THROW(new ParseTree(root), std::invalid_argument);
}

TEST(ParseTreeTest, NoRootNodeType) {
    Node *root = new Node();

    ASSERT_THROW(new ParseTree(new Node()), std::invalid_argument);
}

TEST(ParseTreeTest, DISBALED_SimplestProgram) {
    Scanner *scanner = new Scanner("../src/test/testData/programs/simplestProgram.txt");
    Token *token1 = scanner->nextToken();
    ASSERT_EQ(token1->getType(), SymbolType::INTTOKEN);

    Token *token2 = scanner->nextToken();
    ASSERT_EQ(token2->getType(), SymbolType::IDENTIFIER);

    Token *token3 = scanner->nextToken();
    ASSERT_EQ(token3->getType(), SymbolType::SEMICOLON);

    Token *token4 = scanner->nextToken();
    ASSERT_TRUE(token4->isEOF());
    //TODO: Fix this test
/*
    Node *root = new Node(PROG);
    Node *decls = new Node(DECLS);
    Node *decl = new Node(DECL);
    Node *declsEmpty = new Node(DECLS_EMPTY);
    Node *statements = new Node(STATEMENTS);
    Node *arrayEmpty = new Node(ARRAY_EMPTY);

    root->addChild(decls);
    root->addChild(statements);

    decls->addChild(decl);
    decls->addChild(declsEmpty);

    decl->addChild(new Node()); // Keyword: int
    decl->addChild(arrayEmpty);
    decl->addChild(new Node()); // Identifier: a

    statements->addChild(new Node(STATEMENTS_EMPTY));*/
}
