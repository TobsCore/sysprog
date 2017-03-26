#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Token/token.h"

using testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test {
    public:
        Token obj;
        ClassDeclaration() {
            //obj;
        }
    };
}

TEST_F(ClassDeclaration, exampleTestName1) {
    ASSERT_EQ("", "");
}

TEST_F(ClassDeclaration, exampleShouldFail) {
    ASSERT_EQ("", "-");
}