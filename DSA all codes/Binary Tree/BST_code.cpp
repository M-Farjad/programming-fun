// Online C++ compiler to run C++ program online
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
void BSTNode::setParent(BSTNode *parent)
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
    void insert(int value);
    BST();
    BSTNode *root;
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

BSTNode *BST::remove(BSTNode *tree, int info)
{
    BSTNode *t;
    int cmp = info - tree->getInfo();
    if (cmp < 0)
    {
        t = remove(tree->getLeft(), info);
        tree->setLeft(t);
        if (t != NULL) // updating parent
            t->setParent(tree);
    }
    else if (cmp > 0)
    {
        t = remove(tree->getRight(), info);
        tree->setRight(t);
        if (t != NULL) // updating parent
            t->setParent(tree);
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
        if (t != NULL) // updating parent
            t->setParent(tree);
    }
    else
    { // case 1
        BSTNode *nodeToDelete = tree;
        if (tree->getLeft() == NULL) // will handle 0 children
            tree = tree->getRight();
        else if (tree->getRight() == NULL)
            tree = tree->getLeft();
        else
            tree = NULL;

        delete nodeToDelete;
    }
    return tree;
}

int main()
{
    // Write C++ code here
    // std::cout << "Hello world!";
    BST mybst;
    mybst.insert(10);
    mybst.insert(20);
    mybst.insert(21);
    cout << endl;
    cout << "Pre Order" << endl;
    mybst.preorder(mybst.root);
    cout << endl;
    cout << "Post Order" << endl;
    mybst.postorder(mybst.root);
    cout << endl;
    cout << "In Order" << endl;
    mybst.inorder(mybst.root);
    cout << endl;
    cout << "Mix: " << mybst.findMin(mybst.root)->getInfo() << endl;
    cout << "Max: " << mybst.findMax(mybst.root)->getInfo() << endl;
    cout << "Searching 30 in the tree returned " << mybst.search(30) << endl;
    cout << "Traversing tree pre order after Deleting node with value 20 in the tree ";
    mybst.remove(mybst.root, 20);
    mybst.preorder(mybst.root);
    return 0;
}





// void insert(int value)
    // {
    //     Node *currentNode = root, *prev = 0;
    //     while (currentNode != 0 && root != 0)
    //     {
    //         prev = currentNode;
    //         if (value < currentNode->getdata())
    //             currentNode = currentNode->getleft();
    //         else
    //             currentNode = currentNode->getright();
    //     }
    //     if (root == 0)
    //         root = new Node(value);
    //     else if (value < prev->getdata())
    //     {
    //         Node *temp = new Node(value);
    //         temp->setparent(prev);
    //         prev->setleft(temp);
    //     }
    //     else if (value > prev->getdata())
    //     {
    //         Node *temp = new Node(value);
    //         temp->setparent(prev);
    //         prev->setright(temp);
    //     }
    //     else
    //         cout << "ERROR";
    // }