#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Scanner/Scanner/scanner.h"

using testing::Eq;


class ScannerTest : public ::testing::Test {
public:
    std::string folder = "../test/testData/";
};

TEST_F(ScannerTest, testingEmpty) {
    char const *folderName = (folder + "testEmpty.txt").c_str();
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}

TEST_F(ScannerTest, emptyGoFurther) {
    char const *folderName = (folder + "testEmpty.txt").c_str();
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());

    Token token2 = scanner->nextToken();
    ASSERT_EQ(FILE_END, token2.getType());
}

TEST_F(ScannerTest, ReadSomeIdentifier) {
    char const *folderName = (folder + "testIdentifier.txt").c_str();
    Scanner *scanner = new Scanner(folderName);

    Token token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(IDENTIFIER, token.getType());

    token = scanner->nextToken();
    ASSERT_EQ(FILE_END, token.getType());
}
