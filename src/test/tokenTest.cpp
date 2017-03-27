#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Token/token.h"

using testing::Eq;


TEST(TokenTest, getSetIntegerToken) {

    Token *testToken = new Token();
    testToken->setPosition(5,1);
    testToken->setType(INTEGER);

    ASSERT_EQ(5, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(INTEGER, testToken->getType());
    ASSERT_STREQ("", testToken->getValue());
}

TEST(TokenTest, getSetIdentifier) {

    Token *testToken = new Token();
    testToken->setPosition(1,1);
    testToken->setType(IDENTIFIER);
    testToken->setValue((char *) "testVar");

    ASSERT_EQ(1, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(IDENTIFIER, testToken->getType());
    ASSERT_STREQ("testVar", testToken->getValue());
}

TEST(TokenTest, eof) {

    Token *testToken = new Token();
    testToken->setType(FILE_END);

    ASSERT_TRUE(testToken->isEOF());
}
