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
