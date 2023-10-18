#include <iostream>
#include <queue>
using namespace std;

class avlNode
{
    avlNode *prev;
    avlNode *left;
    avlNode *right;
    int info;
    int height;

public:
    avlNode();
    avlNode(int);
    void setLeft(avlNode *left);
    void setRight(avlNode *right);
    void setParent(avlNode *parent);
    void setInfo(int info);
    avlNode *getLeft();
    avlNode *getRight();
    avlNode *getParent();
    int getInfo();
    int getHeight(avlNode *node);
    int max(int, int);
};
avlNode::avlNode() : prev(), left(), right(), info(), height() {}
avlNode::avlNode(int val) : prev(), left(), right(), info(val), height() {}
void avlNode::setInfo(int val) { info = val; }
void avlNode::setLeft(avlNode *leftSubTree)
{
    left = leftSubTree;
}
void avlNode::setRight(avlNode *rightSubTree)
{
    right = rightSubTree;
}
void avlNode::setParent(avlNode *parent)
{
    this->prev = parent;
}
avlNode *avlNode::getLeft()
{
    return this->left;
}
avlNode *avlNode::getParent()
{
    return this->prev;
}
avlNode *avlNode::getRight()
{
    return this->right;
}
int avlNode::getInfo() { return info; }
// A utility function to get the
// height of the tree
int avlNode::getHeight(avlNode *node)
{
    if (!node)
        return 0;
    return node->height;
}
// A utility function to get maximum
// of two integers
int avlNode::max(int a, int b)
{
    return (a > b) ? a : b;
}
/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */

class AVL
{
public:
    avlNode *root;
    AVL();
    int height(avlNode *);
    int diff(avlNode *);
    void insert(int value);
    void preorder(avlNode *node);
    void postorder(avlNode *node);
    void reverseOrder(avlNode *avlNode);
    void inorder(avlNode *node);
    void levelOrder(avlNode *node);
    avlNode *findMin(avlNode *Node);
    avlNode *findMax(avlNode *Node);
    void balanceFactor(avlNode *);
    bool search(int);
    avlNode *remove(avlNode *tree, int info);
};
AVL::AVL() : root(NULL) {}
void AVL::preorder(avlNode *avlNode)
{
    if (avlNode != NULL)
    {
        cout << avlNode->getInfo() << " ";
        preorder(avlNode->getLeft());
        preorder(avlNode->getRight());
    }
}
void AVL::postorder(avlNode *avlNode)
{
    if (avlNode != NULL)
    {
        postorder(avlNode->getLeft());
        postorder(avlNode->getRight());
        cout << avlNode->getInfo() << " ";
    }
}
void AVL::inorder(avlNode *avlNode)
{
    if (avlNode != NULL)
    {
        inorder(avlNode->getLeft());
        cout << avlNode->getInfo() << " ";
        inorder(avlNode->getRight());
    }
}
// void AVL::levelOrder(){

// }
int AVL::diff(avlNode *temp)
{
    int l_height = height(temp->getLeft());
    int r_height = height(temp->getRight());
    int b_factor = l_height - r_height;
    return b_factor;
}
void AVL::balanceFactor(avlNode *avlNode)
{
    if (avlNode)
    {
        balanceFactor(avlNode->getLeft());
        int balFactor = diff(avlNode);
        cout << "For node with the value " << avlNode->getInfo() << ": ";
        if (balFactor < -1)
        {
            if (diff(avlNode->getRight()) > 0)
                cout << "RL" << endl;
            else
                cout << "RR" << endl;
        }
        else if (balFactor > 1)
        {
            if (diff(avlNode->getLeft()) > 0)
                cout << "LL" << endl;
            else
                cout << "LR" << endl;
        }
        else
            cout << "this particular tree is balanced\n";
        balanceFactor(avlNode->getRight());
    }
}
void AVL::reverseOrder(avlNode *avlNode)
{
    if (avlNode != NULL)
    {
        reverseOrder(avlNode->getRight());
        cout << avlNode->getInfo() << " ";
        reverseOrder(avlNode->getLeft());
    }
}
avlNode *AVL::findMax(avlNode *avlNode)
{
    while (avlNode->getRight() != NULL)
    {
        avlNode = avlNode->getRight();
    }
    return avlNode;
}
avlNode *AVL::findMin(avlNode *avlNode)
{
    while (avlNode->getLeft() != NULL)
    {
        avlNode = avlNode->getLeft();
    }
    return avlNode;
}
void AVL::levelOrder(avlNode *node)
{
    if (node == NULL)
    {
        return;
    }
    queue<avlNode *> q;
    q.push(node);
    while (!q.empty())
    {
        avlNode *temp = q.front();
        cout << temp->getInfo() << " ";
        q.pop();
        if (temp->getLeft() != NULL)
            q.push(temp->getLeft());
        if (temp->getRight() != NULL)
            q.push(temp->getRight());
    }
}
bool AVL::search(int val)
{
    avlNode *currentNode = root;
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
void AVL::insert(int value)
{
    avlNode *currentNode = root, *prev = 0;
    while (currentNode != 0 && root != 0)
    {
        prev = currentNode;
        if (value < currentNode->getInfo())
            currentNode = currentNode->getLeft();
        else
            currentNode = currentNode->getRight();
    }
    if (root == 0)
        root = new avlNode(value);
    else if (value < prev->getInfo())
    {
        avlNode *temp = new avlNode(value);
        temp->setParent(prev);
        prev->setLeft(temp);
    }
    else if (value > prev->getInfo())
    {
        avlNode *temp = new avlNode(value);
        temp->setParent(prev);
        prev->setRight(temp);
    }
    else
        cout << "ERROR";
}
int AVL::height(avlNode *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->getLeft());
        int r_height = height(temp->getRight());
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
avlNode *AVL::remove(avlNode *tree, int val)
{
    avlNode *temp; // for removing nodes
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
        avlNode *minNode;
        minNode = findMin(tree->getRight());
        tree->setInfo(minNode->getInfo());
        temp = remove(tree->getRight(), minNode->getInfo());
        tree->setRight(temp);
        if (temp)
            temp->setParent(tree); // not sure
    }
    else
    {
        avlNode *del = tree;
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
    AVL tree;
    tree.insert(50);
    tree.insert(10);
    tree.insert(20);
    tree.insert(40);
    tree.insert(30);
    cout << "\nThe Min Value of tree is: " << tree.findMin(tree.root)->getInfo() << endl;
    tree.insert(60);
    cout << "Max Value of tree is: " << tree.findMax(tree.root)->getInfo() << endl;
    tree.reverseOrder(tree.root);
    cout << "\n";
    tree.inorder(tree.root);
    cout << "\n";
    tree.levelOrder(tree.root);
    cout << "\n";
    tree.balanceFactor(tree.root);
}