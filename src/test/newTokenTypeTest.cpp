//
// Created by Patrick König on 13.06.17.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Scanner/Scanner.h"
#include "../main/Scanner/Token/IdentifierToken.h"
#include "../main/Scanner/Token/IntegerToken.h"
#include "../main/Scanner/Token/ReadToken.h"

using testing::Eq;

TEST(NewTokenTypeTest, SomeTokens) {
    char const *folderName = "../src/test/testData/NewTokenTypeTest1.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(READTOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(WRITETOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(10, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(16, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(INTTOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(18, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IFTOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(22, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ELSETOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(25, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(30, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(WRITETOKEN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(46, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(51, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(52, token->getCol());

    delete scanner;
    delete token;
}

// TODO: Patty, du kannst diese Tests hier nutzen um den Automaten anzupassen.
TEST(NewTokenTypeTest, DISABLED_LowerCaseWhile) {
    Automat *testAutomat = new Automat();
    // while
    ASSERT_EQ(testAutomat->checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('l'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), WHILETOKEN);
}

TEST(NewTokenTypeTest, DISABLED_UpperCaseWhile) {
    Automat *testAutomat = new Automat();
    // WHILE
    ASSERT_EQ(testAutomat->checkExpression('W'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('H'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('L'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('E'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), WHILETOKEN);
}

TEST(NewTokenTypeTest, DISABLED_DifferentCasesWhile) {
    Automat *testAutomat = new Automat();
    // WhiLe
    ASSERT_EQ(testAutomat->checkExpression('W'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('h'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('L'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_SpellingMistakeWhile) {
    Automat *testAutomat = new Automat();
    // WHILE
    ASSERT_EQ(testAutomat->checkExpression('W'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('H'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('H'), NEXTCHAR); //Spelling mistake here
    ASSERT_EQ(testAutomat->checkExpression('E'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_UpperCaseIf) {
    Automat *testAutomat = new Automat();
    // IF
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('F'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IFTOKEN);
}

TEST(NewTokenTypeTest, DISABLED_DifferentCasesIf) {
    Automat *testAutomat = new Automat();
    // If
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('f'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_DifferentCasesIf2) {
    Automat *testAutomat = new Automat();
    // iF
    ASSERT_EQ(testAutomat->checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('F'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_UpperCaseRead) {
    Automat *testAutomat = new Automat();
    // READ
    ASSERT_EQ(testAutomat->checkExpression('R'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('E'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('A'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('D'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_DifferentCasesRead) {
    Automat *testAutomat = new Automat();
    // ReAd
    ASSERT_EQ(testAutomat->checkExpression('R'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('A'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('d'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_UpperCaseWrite) {
    Automat *testAutomat = new Automat();
    // WRITE
    ASSERT_EQ(testAutomat->checkExpression('W'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('R'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('T'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('E'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

TEST(NewTokenTypeTest, DISABLED_WriteToken) {
    Automat *testAutomat = new Automat();
    // write
    ASSERT_EQ(testAutomat->checkExpression('w'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('i'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('e'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), WRITETOKEN);
}

TEST(NewTokenTypeTest, DISABLED_DifferentCasesWrite) {
    Automat *testAutomat = new Automat();
    // WrItE
    ASSERT_EQ(testAutomat->checkExpression('W'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('r'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('I'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('t'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('E'), NEXTCHAR);
    ASSERT_EQ(testAutomat->checkExpression('\0'), IDENTIFIER);
}

