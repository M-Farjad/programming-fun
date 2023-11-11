#include <iostream>
using namespace std;
class BSTNode
{
public:
    BSTNode();
    BSTNode(int value);
    void setLeft(BSTNode *left);
    void setRight(BSTNode *right);
    void setParent(BSTNode *parent);
    BSTNode *getLeft();
    BSTNode *getRight();
    BSTNode *getParent();
    int getInfo();
    void setInfo(int info);

private:
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
    int info;
};
BSTNode::BSTNode(int val = -1)
{
    this->info = val;
    this->left = this->right = this->parent = NULL;
}
void BSTNode::setLeft(BSTNode *left)
{
    this->left = left;
}
void BSTNode::setRight(BSTNode *right)
{
    this->right = right;
}
void BSTNode::setParent(BSTNode *parent) // a.setleft(B)//B.setparent(a);
{

    this->parent = parent;
}
BSTNode *BSTNode::getLeft()
{

    return this->left;
}
BSTNode *BSTNode::getRight()
{

    return this->right;
}
BSTNode *BSTNode::getParent()
{

    return this->parent;
}
int BSTNode::getInfo()
{

    return this->info;
}
void BSTNode::setInfo(int info)
{

    this->info = info;
}

class BST
{
public:
    BSTNode *root;
    int length = 0;
    BST();
    void insert(int value);
    void inorder(BSTNode *node);
    void setLength(BSTNode *);
    BSTNode *findMin(BSTNode *Node)
    {
        if (Node == NULL)
            return NULL;
        if (Node->getLeft() == NULL)
            return Node; // this is it.
        return findMin(Node->getLeft());
    }
    int getlength() const
    {
        return length;
    }
    bool search(int value);
    void merge(BSTNode *root2){
        if(root2==NULL){return;}
        else {
            merge(root2->getLeft());
            merge(root2->getRight());
            if(search(root2->getInfo())) return;
            insert(root2->getInfo()); 
        }
    }
    BSTNode *remove(BSTNode *tree, int info);
    friend class Union;
};
BST::BST()
{
    this->root = NULL;
}
void BST::insert(int value)
{

    BSTNode *p = root,
            *prev = 0;
    // find a place for inserting new node;
    while (p != 0 && root != 0)
    {
        prev = p;
        if (value < p->getInfo())
            p = p->getLeft();
        else
            p = p->getRight();
    }

    if (root == 0) // tree is empty;
        root = new BSTNode(value);
    else if (value < prev->getInfo())
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setLeft(temp);
    }
    else
    {
        BSTNode *temp = new BSTNode(value);
        temp->setParent(prev);
        prev->setRight(temp);
    }
    length++;
}
void BST::inorder(BSTNode *BSTNode)
{
    if (BSTNode != NULL)
    {
        inorder(BSTNode->getLeft());
        cout << BSTNode->getInfo() << " ";
        inorder(BSTNode->getRight());
    }
}
void BST::setLength(BSTNode *BSTNode)
{
    if (BSTNode != NULL)
    {
        length++;
        setLength(BSTNode->getLeft());
        setLength(BSTNode->getRight());
    }
}
bool BST::search(int value)
{
    BSTNode *p = root;
    while (p != 0)
    {
        if (value == p->getInfo())
            return true;
        else if (value < p->getInfo())
            p = p->getLeft();
        else
            p = p->getRight();
    }
    return 0;
}

//           6
//      4       7
// 1       5      9
//   2              8
//     3

BSTNode *BST::remove(BSTNode *tree, int info)
{
    BSTNode *t;
    // int cmp = info - tree->getInfo();
    if (info < tree->getInfo())
    {
        t = remove(tree->getLeft(), info);
        tree->setLeft(t);
    }
    else if (info > tree->getInfo())
    {
        t = remove(tree->getRight(), info);
        tree->setRight(t);
    }
    // two children, replace with inorder successor
    else if (tree->getLeft() != NULL && tree->getRight() != NULL)
    {
        BSTNode *minNode;
        minNode = findMin(tree->getRight());
        tree->setInfo(minNode->getInfo());
        t = remove(tree->getRight(),
                   minNode->getInfo());
        tree->setRight(t);
    }
    else
    {
        BSTNode *nodeToDelete = tree;
        if (tree->getLeft() == NULL)       //         4
            tree = tree->getRight();       //     3       8
        else if (tree->getRight() == NULL) //   4     6       5
            tree = tree->getLeft();
        else
            tree = NULL;
        delete nodeToDelete;
    }
    
    return tree;
}
int main()
{
    BST tree1, tree2;
    tree1.insert(34);
    tree2.insert(10);
    tree1.insert(234);
    tree2.insert(234);
    tree2.insert(10);
    tree2.insert(15);
    tree2.insert(18);
    tree1.merge(tree2.root);
    tree1.inorder(tree1.root);

    return 0;
}