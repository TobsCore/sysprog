#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Buffer/Buffer.h"

TEST(BufferTest, EmptyFile) {
    char const *testFile = "../src/test/testData/Empty.txt";
    Buffer* buffer = new Buffer(testFile);

    ASSERT_TRUE(buffer->hasNext());
    ASSERT_EQ(0, buffer->getChar());
    ASSERT_FALSE(buffer->hasNext());

    delete buffer;
}

TEST(BufferTest, ReadingSomeCharacters) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    ASSERT_TRUE(buffer->hasNext());
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    ASSERT_EQ('4', buffer->getChar());
    ASSERT_EQ('5', buffer->getChar());
    ASSERT_EQ('6', buffer->getChar());
    ASSERT_EQ('7', buffer->getChar());
    ASSERT_EQ('8', buffer->getChar());
    ASSERT_EQ('9', buffer->getChar());
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    delete buffer;
}


TEST(BufferTest, LongFileWithLoopSmallChunk) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    // With a buffer size of 1024, the buffer shouldn't be switched
    for (int i = 0; i < 50; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }

    delete buffer;
}

TEST(BufferTest, LongFileWithLoopSwitchOnce) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    // With a buffer size of 1024, the buffer should be switched at least once
    for (int i = 0; i < 1050; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    delete buffer;
}

TEST(BufferTest, LongFileWithLoopSwitchOften) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    // With a buffer size of 1024, the buffer should be switched at least once
    for (int i = 0; i < 7000; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    delete buffer;
}

TEST(BufferTest, LongFileDifferentCharsAfterBufferExceeded) {
    char const *testFile = "../src/test/testData/LongFileDifferentSymbols.txt";
    Buffer* buffer = new Buffer(testFile);

    // Has some different symbols at the critical part
    for (int i = 0; i < 1020; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    ASSERT_EQ('a', buffer->getChar());
    ASSERT_EQ('b', buffer->getChar());
    ASSERT_EQ('c', buffer->getChar());
    ASSERT_EQ('d', buffer->getChar());
    ASSERT_EQ('e', buffer->getChar());
    ASSERT_EQ('f', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetChar0) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(0);
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetChar1) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(1);
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetCharToBeginning) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(2);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(2);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetCharBy0AtBeginning) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    buffer->ungetChar(0);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharForRightBuffer0) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(0);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharForRightBuffer1) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(1);
    ASSERT_EQ('9', buffer->getChar());
    ASSERT_EQ('0', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharForRightBufferToBeginningOfRightBuffer) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(6);
    ASSERT_EQ('4', buffer->getChar());
    ASSERT_EQ('5', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharFromRightBufferToLeftBuffer) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(7);
    ASSERT_EQ('3', buffer->getChar());
    ASSERT_EQ('4', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharFromRightBufferToLeftBufferFurther) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(8);
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    ASSERT_EQ('4', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, UngetCharFromLeftBufferToRightBuffer) {
    char const *testFile = "../src/test/testData/LongFile.txt";
    Buffer* buffer = new Buffer(testFile);

    for (int i = 0; i < 2060; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(20);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    ASSERT_EQ('4', buffer->getChar());
    ASSERT_EQ('5', buffer->getChar());
    ASSERT_EQ('6', buffer->getChar());
    ASSERT_EQ('7', buffer->getChar());
    ASSERT_EQ('8', buffer->getChar());
    ASSERT_EQ('9', buffer->getChar());
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, BibleMinimized) {
    char const *bible = "../src/test/testData/Bible.min.txt";
    Buffer* buffer = new Buffer(bible);

    int i = 0;
    char letter;
    while (buffer->hasNext()) {
        letter = buffer->getChar();
        i++;
        if (i >= 20800) {
            int a;
        }
    }
    ASSERT_FALSE(buffer->hasNext());
    ASSERT_EQ(0, '\0');
    ASSERT_EQ(0, letter);
}