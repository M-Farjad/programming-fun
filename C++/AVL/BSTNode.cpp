#include"BSTNode.h"
BSTNode::BSTNode() : prev(), left(), right(), info(), height() {}
BSTNode::BSTNode(int val) : prev(), left(), right(), info(val), height() {}
void BSTNode::setInfo(int val) { info = val; }
void BSTNode::setLeft(BSTNode* leftSubTree)
{
    left = leftSubTree;
}
void BSTNode::setRight(BSTNode* rightSubTree)
{
    right = rightSubTree;
}
void BSTNode::setParent(BSTNode* parent)
{
    this->prev = parent;
}
BSTNode* BSTNode::getLeft()
{
    return this->left;
}
BSTNode* BSTNode::getParent()
{
    return this->prev;
}
BSTNode* BSTNode::getRight()
{
    return this->right;
}
int BSTNode::getInfo() { return info; }