#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Scanner/Scanner.h"
#include "../main/Token/IdentifierToken.h"
#include "../main/Token/IntegerToken.h"
#include "../main/Token/ErrorToken.h"

using testing::Eq;

TEST(ScannerTest, Empty) {
    char const *folderName = "../src/test/testData/testEmpty.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, EmptyGoFurther) {
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

    idToken = static_cast<IdentifierToken *>(scanner->nextToken());
    ASSERT_EQ(IDENTIFIER, idToken->getType());
    delete idToken;

    idToken = static_cast<IdentifierToken *>(scanner->nextToken());
    ASSERT_EQ(IDENTIFIER, idToken->getType());
    delete idToken;

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, Plus) {
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

TEST(ScannerTest, Spaces) {
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

TEST(ScannerTest, LongerIdentifier) {
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

TEST(ScannerTest, Parenthesis) {
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

TEST(ScannerTest, SimpleIdentifier) {
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

TEST(ScannerTest, Comment) {
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

TEST(ScannerTest, Comment2) {
    char const *folderName = "../src/test/testData/testComment2.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token;

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(1, token->getCol());
    ASSERT_STREQ("Dies", static_cast<IdentifierToken*>(token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(6, token->getCol());
    ASSERT_STREQ("ist", static_cast<IdentifierToken*>(token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(10, token->getCol());
    ASSERT_STREQ("ein", static_cast<IdentifierToken*>(token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(COMMENT, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(14, token->getCol());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(1, token->getRow());
    ASSERT_EQ(32, token->getCol());
    ASSERT_STREQ("Kommentar", static_cast<IdentifierToken*>(token)->getLexem());

    delete scanner;
    delete token;
}

TEST(ScannerTest, CommentWith2Spaces) {
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

TEST(ScannerTest, CommentWithMultipleSpaces) {
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

TEST(ScannerTest, CommentWithSpace) {
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
    ASSERT_STREQ("int", static_cast<IdentifierToken *>(token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_STREQ("a", static_cast<IdentifierToken *>(token)->getLexem());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token->getType());

    delete scanner;
    delete token;
}

TEST(ScannerTest, ReallyLongIdentifier) {
    char const *folderName = "../src/test/testData/testReallyLongIdentifier.txt";
    Scanner *scanner = new Scanner(folderName);

    Token *token = scanner->nextToken();
    ASSERT_EQ(SymbolType::ERROR, token->getType());
    ASSERT_STREQ("Identifier too long", static_cast<ErrorToken* >(token)->getInfo());

    delete scanner;
    delete token;
}


TEST(ScannerTest, ExampleProgram) {
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

    token = scanner->nextToken();
    ASSERT_EQ(WHILETOKEN, token->getType());
    ASSERT_EQ(8, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(8, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(8, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(8, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(BRACES_LEFT, token->getType());
    ASSERT_EQ(8, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IFTOKEN, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_LEFT, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(EQUALS, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(AND, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(LESS, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(AND, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(GREATER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(PARANTHESES_RIGHT, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(BRACES_LEFT, token->getType());
    ASSERT_EQ(9, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(ASSIGN, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(PLUS, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(INTEGER, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(SEMICOLON, token->getType());
    ASSERT_EQ(10, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(BRACES_RIGHT, token->getType());
    ASSERT_EQ(11, token->getRow());

    token = scanner->nextToken();
    ASSERT_EQ(BRACES_RIGHT, token->getType());
    ASSERT_EQ(12, token->getRow());

}


TEST(ScannerTest, toStringOfIdentifierAndNormaleToken)  {
	char const *folderName = "../src/test/testData/testProgramm.txt";
	Scanner *scanner = new Scanner(folderName);

	Token *token = scanner->nextToken();
	ASSERT_EQ(IDENTIFIER, token->getType());
	ASSERT_STREQ("Token Identifier           Line:     1  Column:   1  Lexem: int", token->toString());

	token = scanner->nextToken();
	token = scanner->nextToken();
	ASSERT_STREQ("Token Semicolon            Line:     1  Column:   6", token->toString());

}

TEST(ScannerTest, DISABLED_BibleMinimized) {
    char const *bible = "../src/test/testData/bible.min.txt";
    Scanner *scanner = new Scanner(bible);
    Token *token = scanner->nextToken();
    int i = 0;
    while (!token->isEOF()) {
        token = scanner->nextToken();
        i++;
    }
    ASSERT_TRUE(token->isEOF());
    ASSERT_EQ(i, 4543);
    delete scanner;
}

