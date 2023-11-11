#include <iostream>
#include <climits>
using namespace std;

class BSTNode
{
    BSTNode *prev;
    BSTNode *left;
    BSTNode *right;
    int info;

public:
    BSTNode();
    BSTNode(int);
    void setLeft(BSTNode *left);
    void setRight(BSTNode *right);
    void setParent(BSTNode *parent);
    void setInfo(int info);
    BSTNode *getLeft();
    BSTNode *getRight();
    BSTNode *getParent();
    int getInfo();
};
BSTNode::BSTNode() : prev(), left(), right(), info() {}
BSTNode::BSTNode(int val) : prev(), left(), right(), info(val) {}
void BSTNode::setInfo(int val) { info = val; }
void BSTNode::setLeft(BSTNode *leftSubTree)
{
    left = leftSubTree;
}
void BSTNode::setRight(BSTNode *rightSubTree)
{
    right = rightSubTree;
}
void BSTNode::setParent(BSTNode *parent)
{
    this->prev = parent;
}
BSTNode *BSTNode::getLeft()
{
    return this->left;
}
BSTNode *BSTNode::getParent()
{
    return this->prev;
}
BSTNode *BSTNode::getRight()
{
    return this->right;
}
int BSTNode::getInfo() { return info; }

class BST
{
public:
    BSTNode *root;
    BST();
    void insert(int value);
    void preorder(BSTNode *node);
    void postorder(BSTNode *node);
    void inorder(BSTNode *node);
    BSTNode *findMin(BSTNode *Node);
    BSTNode *findMax(BSTNode *Node);
    bool search(int);
    BSTNode *remove(BSTNode *tree, int info);
};
BST::BST() : root(NULL) {}
void BST::preorder(BSTNode *BstNode)
{
    if (BstNode != NULL)
    {
        cout << BstNode->getInfo() << " ";
        preorder(BstNode->getLeft());
        preorder(BstNode->getRight());
    }
}
void BST::postorder(BSTNode *BstNode)
{
    if (BstNode != NULL)
    {
        postorder(BstNode->getLeft());
        postorder(BstNode->getRight());
        cout << BstNode->getInfo() << " ";
    }
}
void BST::inorder(BSTNode *BstNode)
{
    if (BstNode != NULL)
    {
        inorder(BstNode->getLeft());
        cout << BstNode->getInfo() << " ";
        inorder(BstNode->getRight());
    }
}
BSTNode *BST::findMax(BSTNode *BsTNode)
{
    while (BsTNode->getRight() != NULL)
    {
        BsTNode = BsTNode->getRight();
    }
    return BsTNode;
}
BSTNode *BST::findMin(BSTNode *BsTNode)
{
    while (BsTNode->getLeft() != NULL)
    {
        BsTNode = BsTNode->getLeft();
    }
    return BsTNode;
}
bool BST::search(int val)
{
    BSTNode *currentNode = root;
    while (currentNode != 0)
    {
        if (val == currentNode->getInfo())
            return true;
        else if (val < currentNode->getInfo())
            currentNode = currentNode->getLeft();
        else
            currentNode = currentNode->getRight();
    }
    return 0;
}
void BST::insert(int value)
{
    BSTNode *currentNode = root, *prev = 0;
    while (currentNode != 0 && root != 0)
    {
        prev = currentNode;
        if (value < currentNode->getInfo())
            currentNode = currentNode->getLeft();
        else
            currentNode = currentNode->getRight();
    }
    if (root == 0)
        root = new BSTNode(value);
    else if (value < prev->getInfo())
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setLeft(temp);
    }
    else if (value > prev->getInfo())
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setRight(temp);
    }
    else
        cout << "ERROR";
}

BSTNode *BST::remove(BSTNode *tree, int val)
{
    BSTNode *temp; // for removing nodes
    if (search(val) == 0)
        return 0; // if value not found
    if (val > tree->getInfo())
    {
        temp = remove(tree->getRight(), val);
        tree->setRight(temp);
        if (!temp)
            temp->setParent(tree); // not sure
    }
    else if (val < tree->getInfo())
    {
        temp = remove(tree->getLeft(), val);
        tree->setLeft(temp);
        if (!temp)
            temp->setParent(tree);
    }

    // two children, replace with inorder successor
    else if ((tree->getLeft()) && (tree->getRight()))
    {
        BSTNode *minNode;
        minNode = findMin(tree->getRight());
        tree->setInfo(minNode->getInfo());
        temp = remove(tree->getRight(), minNode->getInfo());
        tree->setRight(temp);
        if (temp)
            temp->setParent(tree); // not sure
    }
    else
    {
        BSTNode *del = tree;
        if (!(tree->getRight()))
            tree = tree->getLeft();
        else if (!(tree->getLeft()))
            tree = tree->getRight();
        else
            tree = NULL;

        delete del;
    }
    return tree;
}
int main()
{

    BST tree;
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    cout << "Preorder: ";
    tree.preorder(tree.root);
    cout << "\npostorder: ";
    tree.postorder(tree.root);
    cout << "\ninorder: ";
    tree.inorder(tree.root);
    cout << "\nThe Min Value of tree is: " << tree.findMin(tree.root)->getInfo() << endl;
    cout << "Max Value of tree is: " << tree.findMax(tree.root)->getInfo() << endl;
    cout << "searching 30 : " << tree.search(21) << endl;

    cout << "deleting root with val : 20";
    tree.remove(tree.root, 20);
    cout << "\ndisplaying the inorder traversal: ";
    tree.preorder(tree.root);
    return 0;
}
