#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Scanner/Buffer/Buffer.h"

TEST(BufferTest, DISABLED_testEmptyFile) {
    char const *folderName = "../src/test/testData/testEmpty.txt";
    Buffer* buffer = new Buffer(folderName);

    ASSERT_TRUE(buffer->hasNext());
    ASSERT_EQ(0, buffer->getChar());
    ASSERT_FALSE(buffer->hasNext());

    delete buffer;
}

TEST(BufferTest, testReadingSomeCharacters) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

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


TEST(BufferTest, testLongFileWithLoopSmallChunk) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    // With a buffer size of 1024, the buffer shouldn't be switched
    for (int i = 0; i < 50; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }

    delete buffer;
}

TEST(BufferTest, testLongFileWithLoopSwitchOnce) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    // With a buffer size of 1024, the buffer should be switched at least once
    for (int i = 0; i < 1050; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    delete buffer;
}

TEST(BufferTest, testLongFileWithLoopSwitchOften) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    // With a buffer size of 1024, the buffer should be switched at least once
    for (int i = 0; i < 7000; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    delete buffer;
}

TEST(BufferTest, testLongFileDifferentCharsAfterBufferExceeded) {
    char const *folderName = "../src/test/testData/testLongFileDifferentSymbols.txt";
    Buffer* buffer = new Buffer(folderName);

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
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(0);
    ASSERT_EQ('2', buffer->getChar());
    ASSERT_EQ('3', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetChar1) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    buffer->ungetChar(1);
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, simpleUngetCharToBeginning) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

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
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    buffer->ungetChar(0);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    ASSERT_EQ('2', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, testUngetCharForRightBuffer0) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(0);
    ASSERT_EQ('0', buffer->getChar());
    ASSERT_EQ('1', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, testUngetCharForRightBuffer1) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(1);
    ASSERT_EQ('9', buffer->getChar());
    ASSERT_EQ('0', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, testUngetCharForRightBufferToBeginningOfRightBuffer) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(6);
    ASSERT_EQ('4', buffer->getChar());
    ASSERT_EQ('5', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, testUngetCharFromRightBufferToLeftBuffer) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

    for (int i = 0; i < 1030; i++) {
        char charVal = (i % 10) + 48;
        ASSERT_EQ(charVal, buffer->getChar());
    }
    buffer->ungetChar(7);
    ASSERT_EQ('3', buffer->getChar());
    ASSERT_EQ('4', buffer->getChar());
    delete buffer;
}

TEST(BufferTest, testUngetCharFromRightBufferToLeftBufferFurther) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

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

TEST(BufferTest, testUngetCharFromLeftBufferToRightBuffer) {
    char const *folderName = "../src/test/testData/testLongFile.txt";
    Buffer* buffer = new Buffer(folderName);

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
