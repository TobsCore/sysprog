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
