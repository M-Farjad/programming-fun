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
BSTNode::BSTNode()
{
    this->info = -1;
    this->left = this->right = this->parent = NULL;
}
BSTNode::BSTNode(int value)
{
    this->info = value;
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
void BSTNode::setParent(BSTNode *parent)        //a.setleft(B)//B.setparent(a);
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
    BST();
    void insert(int value);
    void preorder(BSTNode *node);
    void postorder(BSTNode *node);
    void inorder(BSTNode *node);
    BSTNode *findMin(BSTNode *Node);
    BSTNode *findMax(BSTNode *Node);
    bool search(int value);
    BSTNode *remove(BSTNode *tree, int info);
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
}
void BST::preorder(BSTNode *BSTNode)
{
    if (BSTNode != NULL)
    {
        cout << BSTNode->getInfo() << " ";
        preorder(BSTNode->getLeft());
        preorder(BSTNode->getRight());
    }
}
void BST::postorder(BSTNode *BSTNode)
{
    if (BSTNode != NULL)
    {
        postorder(BSTNode->getLeft());
        postorder(BSTNode->getRight());
        cout << BSTNode->getInfo() << " ";
    }
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
BSTNode *BST::findMin(BSTNode *Node)
{
    if (Node == NULL)
        return NULL;
    if (Node->getLeft() == NULL)
        return Node; // this is it.
    return findMin(Node->getLeft());
}
BSTNode *BST::findMax(BSTNode *Node)
{
    if (Node == NULL)
        return NULL;
    if (Node->getRight() == NULL)
        return Node; // this is it.
    return findMax(Node->getRight());
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
        if (tree->getLeft() == NULL)                //         4
                   tree = tree->getRight();         //     3       8
        else if (tree->getRight() == NULL)          //   4     6       5
            tree = tree->getLeft();
        else           
            tree = NULL;
        delete nodeToDelete;
    }
    return tree;
}

int main()
{
    
    BST tree;
    tree.insert(34);
    tree.insert(56);
    tree.insert(0);      
    tree.insert(5);
    tree.insert(234);
    cout << endl;
    tree.preorder(tree.root);
    cout << "Pre Order" << endl;
    cout << endl;
    cout << "Post Order" << endl;
    tree.postorder(tree.root);
    cout << endl;
    cout << "In Order" << endl;
    tree.inorder(tree.root);
    cout << endl;
    cout << "The Min Value of tree is: " << tree.findMin(tree.root)->getInfo() << endl;
    cout << "Max Value of tree is: " << tree.findMax(tree.root)->getInfo() << endl;
    cout << "search : " << tree.search(20) << endl;
    cout << "Traversing tree pre order after Deleting node with value 0 in the tree ";
    tree.remove(tree.root, 0);
    tree.preorder(tree.root);
    return 0;
}