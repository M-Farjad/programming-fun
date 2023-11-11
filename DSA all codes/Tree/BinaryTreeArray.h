#pragma once
#include<iostream>
using namespace std;
#define size 500
class BinaryTree
{
public:
    int treenodes[size];
    BinaryTree();
    bool isLeaf(int);
    int parent(int);     // returns the index of parent
    int leftChild(int);  // returns the index of leftChild
    int rightChild(int); // returns the index of rightChild
    bool rootnode(int);
    bool addLeftChild(int, int);
    bool addRightChild(int, int);
};

BinaryTree::BinaryTree()
{
    for (int i = 0; i < size; i++)
        treenodes[i] = -1;
}
bool BinaryTree::isLeaf(int nodeIndex)
{
    return (leftChild(nodeIndex) == -1 && rightChild(nodeIndex) == -1);
}
int BinaryTree::parent(int nodeIndex)
{
    int parentIndex = (nodeIndex - 1) / 2;
    return (parentIndex >= size || treenodes[parentIndex] == -1) ? -1 : parentIndex;
}
int BinaryTree::leftChild(int nodeIndex)
{
    int lCHild = (2 * nodeIndex) + 1;
    return (lCHild >= size || treenodes[lCHild] == -1) ? -1 : lCHild;
}
int BinaryTree::rightChild(int nodeIndex)
{
    int lCHild = (2 * nodeIndex) + 2;
    return (lCHild >= size || treenodes[lCHild] == -1) ? -1 : lCHild;
}
bool BinaryTree::addRightChild(int val,int parent){
    int index = (2*parent)+2;
    if(index<size)
    {
        treenodes[index]=val;
        return true;
    }
    else{
        cout<<"Can't set child";
        return false;
    }
}
bool BinaryTree::addLeftChild(int val,int parent){
    int index = (2*parent)+1;
    if(index<size)
    {
        treenodes[index]=val;
        return true;
    }
    else{
        cout<<"Can't set child";
        return false;
    }
}
bool BinaryTree::rootnode(int val){
    treenodes[0]=val;
    return true;
}
