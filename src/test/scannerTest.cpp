#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Scanner/Scanner.h"
#include "../main/Token/IdentifierToken.h"
#include "../main/Token/IntegerToken.h"
#include "../main/Token/ErrorToken.h"

using testing::Eq;

TEST(ScannerTest, testingEmpty) {
	char const *folderName = "../src/test/testData/testEmpty.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, emptyGoFurther) {
	char const *folderName = "../src/test/testData/testEmpty.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    Token *token2 = scanner->nextToken();
    ASSERT_EQ(FILE_END, token2->getType());

    delete scanner;
    delete token;
    delete token2;
}

TEST(ScannerTest, ArithmaticExpressionTokenType) {
    char const *folderName = "../src/test/testData/testCloseArithmeticExp.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;
    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    delete token;

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    delete token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    delete token;

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    delete token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    delete token;

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, ReadSomeIdentifier) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;
    IdentifierToken *idToken;
    IntegerToken *intToken;

    idToken = (IdentifierToken *) scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, idToken->getType());
    delete idToken;

    idToken = (IdentifierToken *) scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, idToken->getType());
    delete idToken;

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, PlusTest) {
    char const *folderName = "../src/test/testData/testPluses.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(2, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, SpacesTest) {
    char const *folderName = "../src/test/testData/testSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, ArithmeticExpPosition) {
    char const *folderName = "../src/test/testData/testCloseArithmeticExp.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(2, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    delete scanner;
    delete token;
}



TEST(ScannerTest, IdentifierExPositionsOneAtBeginning) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, testLongerIdentifier) {
    char const *folderName = "../src/test/testData/testIdentifierLonger.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(9, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(13, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, testParenthesis) {
    char const *folderName = "../src/test/testData/testParenthesis.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());


    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(2, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, DISABLED_DifferentSpaces) {
    char const *folderName = "../src/test/testData/testDifferentSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(18, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(25, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, SimpleMultiline) {
    char const *folderName = "../src/test/testData/testSimpleMultiline.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(2, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(2, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(3, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(3, token->getRow());
    ASSERT_EQ(3, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, SpecialCharsSpaces) {
    char const *folderName = "../src/test/testData/testSpecialCharsSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SPECIAL, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(10, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(14, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(16, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, SpecialChars) {
    char const *folderName = "../src/test/testData/testSpecialChars.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SPECIAL, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(9, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(13, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(14, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, EOF_Test) {
    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, commentTest) {
    char const *folderName = "../src/test/testData/testComment.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(COMMENT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(24, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(25, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(26, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, commentWith2SpacesTest) {
    char const *folderName = "../src/test/testData/testCommentWith2Spaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(COMMENT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(15, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(16, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(17, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, commentWithMultipleSpacesTest) {
    char const *folderName = "../src/test/testData/testCommentWithMultipleSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(COMMENT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(26, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(27, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(28, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, commentWithSpaceTest) {
    char const *folderName = "../src/test/testData/testCommentWithSpace.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(COMMENT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(14, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(15, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(16, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, DISABLED_StartsWithSpaces) {
    char const *folderName = "../src/test/testData/testStartWithSpaces.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(9, token->getCol());

    delete scanner;
    delete token;
}



TEST(ScannerTest, ErronuousSpecialChar) {
    // a =:+ b;
    char const *folderName = "../src/test/testData/testErroneousSpecial.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(3, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(COLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(4, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(5, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(7, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(8, token->getCol());

    delete scanner;
    delete token;
}

TEST(ScannerTest, IdentifierExValues) {

    char const *folderName = "../src/test/testData/testIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_STREQ("int", ((IdentifierToken*)token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_STREQ("a", ((IdentifierToken*)token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, ReallyLongIdentifier) {
    char const *folderName = "../src/test/testData/testReallyLongIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(ERROR, token->getType());

    delete scanner;
    delete token;
}


TEST(ScannerTest, TestExampleProgram) {
    char const *folderName = "../src/test/testData/testProgramm.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(1, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(2, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(2, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(2, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(2, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(3, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(3, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(3, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(3, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(3, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(STAR, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(4, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(7, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(7, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(7, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(7, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(7, token->getRow());


}



