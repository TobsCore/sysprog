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

TEST(ScannerTest, ArithmaticExpressionTokenType) {
    char const *folderName = "../src/test/testData/testCloseArithmeticExp.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;
    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token.getType());
}

TEST(ScannerTest, ReadSomeIdentifier) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}

TEST(ScannerTest, PlusTest) {
    char const *folderName = "../src/test/testData/testPluses.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(2, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(4, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());
}

TEST(ScannerTest, SpacesTest) {
    char const *folderName = "../src/test/testData/testSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());
}

TEST(ScannerTest, ArithmeticExpPosition) {
    char const *folderName = "../src/test/testData/testCloseArithmeticExp.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(2, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(4, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());
}



TEST(ScannerTest, IdentifierExPositionsOneAtBeginning) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());
}

TEST(ScannerTest, testLongerIdentifier) {
    char const *folderName = "../src/test/testData/testIdentifierLonger.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(9, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(13, token.getCol());
}

TEST(ScannerTest, testParenthesis) {
    char const *folderName = "../src/test/testData/testParenthesis.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());


    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(2, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(4, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(8, token.getCol());
}

TEST(ScannerTest, DISABLED_DifferentSpaces) {
    char const *folderName = "../src/test/testData/testDifferentSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(4, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(8, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(18, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(25, token.getCol());
}

TEST(ScannerTest, SimpleMultiline) {
    char const *folderName = "../src/test/testData/testSimpleMultiline.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(2, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(2, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(3, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(3, token.getRow());
    ASSERT_EQ(3, token.getCol());
}

TEST(ScannerTest, SpecialCharsSpaces) {
    char const *folderName = "../src/test/testData/testSpecialCharsSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(8, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SPECIAL, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(10, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(14, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(16, token.getCol());
}

TEST(ScannerTest, SpecialChars) {
    char const *folderName = "../src/test/testData/testSpecialChars.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(3, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(7, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SPECIAL, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(9, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(13, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(14, token.getCol());
}

TEST(ScannerTest, EOF_Test) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(1, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(5, token.getCol());
}

TEST(ScannerTest, DISABLED_StartsWithSpaces) {
    char const *folderName = "../src/test/testData/testStartWithSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(4, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(6, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(8, token.getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token.getType());
    ASSERT_EQ(1, token.getRow());
    ASSERT_EQ(9, token.getCol());
}

TEST(ScannerTest, DISABLED_IdentifierExValues) {

    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_STREQ("int", token.getValue());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());
    ASSERT_STREQ("a", token.getValue());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}
