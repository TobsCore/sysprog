#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Token/token.h"

using testing::Eq;

namespace {
    class TokenTest : public testing::Test {
    public:
        Token testToken;
    };
}

TEST_F(TokenTest, getSetIntegerToken) {
    testToken.setRow(5);
    testToken.setColumn(1);
    testToken.setType(INTEGER);

    ASSERT_EQ(5, testToken.getRow());
    ASSERT_EQ(1, testToken.getColumn());
    ASSERT_EQ(INTEGER, testToken.getType());
    ASSERT_EQ("", testToken.getValue());
}

TEST_F(TokenTest, getSetIdentifier) {
    testToken.setRow(1);
    testToken.setColumn(1);
    testToken.setType(IDENTIFIER);
    testToken.setValue("testVar");

    ASSERT_EQ(1, testToken.getRow());
    ASSERT_EQ(1, testToken.getColumn());
    ASSERT_EQ(IDENTIFIER, testToken.getType());
    ASSERT_EQ("testVar", testToken.getValue());
}

TEST_F(TokenTest, eof) {
    testToken.setType(FILE_END);

    ASSERT_TRUE(testToken.isEOF());
}
