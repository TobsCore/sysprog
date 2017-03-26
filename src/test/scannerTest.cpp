#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Scanner/scanner.h"

using testing::Eq;

TEST(ScannerTest, testingEmpty) {
	char const *folderName = "../src/test/testData/testEmpty.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}

TEST(ScannerTest, emptyGoFurther) {
	char const *folderName = "../src/test/testData/testEmpty.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());

    Token token2 = scanner->nextToken();
    ASSERT_EQ(FILE_END, token2.getType());
}

TEST(ScannerTest, ReadSomeIdentifier) {
	char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_STREQ("int", token.getValue());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getColumn());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_STREQ("a", token.getValue());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getColumn());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}
