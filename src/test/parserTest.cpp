
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Parser.h"


TEST(ParserTest, ReadSimpleIntFile) {
    Parser *parser = new Parser("../src/test/testData/IntSimple.txt", "testout.txt");
    parser->parse();
}
