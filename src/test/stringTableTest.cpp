//
// Created by Tobias Kerst on 09.04.17.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/SymbolTable/StringTable/StringTable.h"

TEST(StringTableTest, SimpleInsert) {
    char const *lexem = "example";
    StringTable *stringTable = new StringTable();

    char *insertedString = stringTable->insertString(lexem);

    ASSERT_STREQ(insertedString, lexem);

    delete stringTable;
}

TEST(StringTableTest, TenTimesTenCharactersSameString) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 9; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }

    delete stringTable;
}

TEST(StringTableTest, LoadTestSameLexem10) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 10; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }

    delete stringTable;
}

TEST(StringTableTest, LoadTestSameLexem100) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 100; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }

    delete stringTable;
}

TEST(StringTableTest, LoadTestSameLexem1000) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 1000; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);

    }

    delete stringTable;
}

TEST(StringTableTest, LoadTestSameLexem10000) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 10000; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }

    delete stringTable;
}

TEST(StringTableTest, LoadTestSameLexem100000) {
    char const *lexem = "0123456789";
    StringTable *stringTable = new StringTable();

    for (int i = 0; i < 100000; i++) {
        char *insertedString = stringTable->insertString(lexem);
        ASSERT_STREQ(insertedString, lexem);
    }

    delete stringTable;
}

TEST(StringTableTest, LoadAlphabet100000) {
    StringTable *stringTable = new StringTable();

    const char *letter[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                            "s", "t", "u", "v", "w", "x", "y", "z"};
    for (int i = 0; i < 100000; i++) {
        const char *val = letter[i % 26];
        char *insertedString = stringTable->insertString(val);
        ASSERT_STREQ(insertedString, val);
    }

    delete stringTable;
}

TEST(StringTableTest, CheckIfExistsAfter10000OtherSymbols) {
    StringTable *stringTable = new StringTable();

    const char *val;
    const char *letter[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
                            "s", "t", "u", "v", "w", "x", "y", "z"};

    char const *first = "example";
    char* firstInStringTable = stringTable->insertString(first);

    for (int i = 0; i < 100000; i++) {
        val = letter[i % 26];
        char *insertedString = stringTable->insertString(val);
        ASSERT_STREQ(insertedString, val);
    }

    ASSERT_STREQ(firstInStringTable, first);

    delete stringTable;
}
