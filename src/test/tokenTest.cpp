#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Token/IntegerToken.h"
#include "../main/Scanner/Token/IdentifierToken.h"
#include "../main/Scanner/SymbolTable/SymbolTable.h"

using testing::Eq;


TEST(TokenTest, IntegerToken) {

    IntegerToken *testToken = new IntegerToken();
    testToken->setPosition(5,1);

    ASSERT_EQ(5, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(testToken->getRow(), testToken->getPosition()->getRow());
    ASSERT_EQ(testToken->getCol(), testToken->getPosition()->getCol());

    ASSERT_EQ(INTEGER, testToken->getType());
    ASSERT_EQ(0, testToken->getValue());

    delete testToken;
}

TEST(TokenTest, IdentifierToken) {

    SymbolTable *symboltable = new SymbolTable();
    IdentifierToken *testToken = new IdentifierToken(symboltable->insert("testVar"));
    testToken->setPosition(1,1);

    ASSERT_EQ(1, testToken->getRow());
    ASSERT_EQ(1, testToken->getCol());
    ASSERT_EQ(IDENTIFIER, testToken->getType());
    ASSERT_STREQ("testVar", testToken->getLexem());

    delete testToken;
}

TEST(TokenTest, CheckForEOF) {
    Token *testToken = new Token();
    testToken->setType(FILE_END);

    ASSERT_TRUE(testToken->isEOF());

    delete testToken;
}
