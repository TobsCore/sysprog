#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../main/Parser/Parser/Node.h"

TEST(NodeTest, AddNoNode) {
    Node *node = new Node();
    ASSERT_THROW(node->getChild(0), std::out_of_range);
    ASSERT_THROW(node->getChild(1), std::out_of_range);
}

TEST(NodeTest, AddOneNode) {
    Node *node = new Node();
    Node *insertNode = new Node();

    node->addChild(insertNode);
    ASSERT_EQ(insertNode, node->getChild(0));
}

TEST(NodeTest, AddMaxNodes) {
    Node *node = new Node();

    for (int i = 0; i < UCHAR_MAX; i++) {
        Node *insertNode = new Node();
        node->addChild(insertNode);
        ASSERT_EQ(insertNode, node->getChild(i));
    }
}

TEST(NodeTest, AddMaxNodesPLUSONE) {
    Node *node = new Node();

    for (int i = 0; i < UCHAR_MAX; i++) {
        node->addChild(new Node());
    }
    ASSERT_THROW(node->addChild(new Node), std::out_of_range);
}
