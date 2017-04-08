#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Token/IntegerToken.h"
#include "../main/Token/IdentifierToken.h"

using testing::Eq;


TEST(TokenTest, IntegerToken) {

    IntegerToken *testToken = new IntegerToken();
    testToken->setPosition(5,1);

    ASSERT_EQ(5, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(INTEGER, testToken->getType());
    ASSERT_EQ(0, testToken->getValue());
}

TEST(TokenTest, IdentifierToken) {

    IdentifierToken *testToken = new IdentifierToken();
    testToken->setPosition(1,1);
    testToken->setLexem("testVar");

    ASSERT_EQ(1, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(IDENTIFIER, testToken->getType());
    ASSERT_STREQ("testVar", testToken->getLexem());
}

TEST(TokenTest, eof) {
    Token *testToken = new Token();
    testToken->setType(FILE_END);

    ASSERT_TRUE(testToken->isEOF());
}