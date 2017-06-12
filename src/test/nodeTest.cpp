#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Node.h"

using testing::Eq;

namespace {
    class NodeTest : public testing::Test {
    public:
        Node node;
    };
}

TEST_F(NodeTest, AddNoNode) {
    ASSERT_THROW(node.getChild(0), std::out_of_range);
    ASSERT_THROW(node.getChild(1), std::out_of_range);
}

TEST_F(NodeTest, AddOneNode) {
    Node *insertNode = new Node();

    node.addChild(insertNode);
    ASSERT_EQ(insertNode, node.getChild(0));
}

TEST_F(NodeTest, AddMaxNodes) {
    for (int i = 0; i < UCHAR_MAX; i++) {
        Node *insertNode = new Node();
        node.addChild(insertNode);
        ASSERT_EQ(insertNode, node.getChild(i));
    }
}

TEST_F(NodeTest, AddMaxNodesPLUSONE) {
    for (int i = 0; i < UCHAR_MAX; i++) {
        node.addChild(new Node());
    }
    ASSERT_THROW(node.addChild(new Node), std::out_of_range);
}

TEST_F(NodeTest, IsLeafForNewlyCreatedNode) {
    ASSERT_TRUE(node.isLeaf());
}

TEST_F(NodeTest, IsLeafAfterAddingChil) {
    node.addChild(new Node());
    ASSERT_FALSE(node.isLeaf());
}
