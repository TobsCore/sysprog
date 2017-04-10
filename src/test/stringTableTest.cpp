//
// Created by Tobias Kerst on 09.04.17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/SymbolTable/StringTable/StringTable.h"

TEST(StringTableTest, SimpleInsertTest) {
    char const *lexem = "example";
    StringTable *stringTable = new StringTable();

    char* insertedString = stringTable->insertString(lexem);

    ASSERT_STREQ(insertedString, lexem);
}

TEST(StringTableTest, TenTimesTenCharactersSameString) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 9; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }
}

TEST(StringTableTest, LoadTestSameLexem100Characters) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 10; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }
}

TEST(StringTableTest, LoadTestSameLexem1000Characters) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 100; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }
}

TEST(StringTableTest, LoadTestSameLexem10000Characters) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 1000; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }
}

TEST(StringTableTest, LoadTestSameLexem100000) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 10000; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }
}
