#pragma once
class BSTNode
{
    int info;
    BSTNode* prev;
    BSTNode* left;
    BSTNode* right;
    int height;
public:
    BSTNode();
    BSTNode(int);
    void setLeft(BSTNode* left);
    void setRight(BSTNode* right);
    void setParent(BSTNode* parent);
    void setInfo(int info);
    BSTNode* getLeft();
    BSTNode* getRight();
    BSTNode* getParent();
    int getInfo();
};