#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Scanner/Scanner.h"
#include "../main/Token/IdentifierToken.h"
#include "../main/Token/IntegerToken.h"
#include "../main/Token/ErrorToken.h"

using testing::Eq;

TEST(ScannerErrorTest, testingEmpty) {
	char const *file = "../src/test/testData/errors.txt";
    Scanner *scanner = new Scanner(file);

    Token *token = scanner->nextToken();

    delete scanner;
    delete token;
}

TEST(ScannerErrorTest, longIntegerTest) {
    char const *file = "../src/test/testData/testLongInteger.txt";
    Scanner *scanner = new Scanner(file);

    Token *token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(1234567891234, static_cast<IntegerToken *>(token)->getValue());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());

    token = scanner->nextToken();
    ASSERT_EQ(ERROR, token->getType());
    ASSERT_STREQ("Integer out of range", static_cast<ErrorToken*>(token)->getInfo());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());

    delete scanner;
    delete token;
}
