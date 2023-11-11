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
    BST();
    void insert(int value);
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
void BST::inorder(BSTNode *node)
{
    if (node)
    {
        inorder(node->getLeft());
        cout << node->getInfo() << " ";
        inorder(node->getRight());
    }
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
bool BST::search(int val)
{
    BSTNode *temp = root;
    while (temp != 0)
    {
        if (val == temp->getInfo())
            return 1;
        else if (val < temp->getInfo())
            temp = temp->getLeft();
        else
            temp = temp->getRight();
    }
    return 0;
}
BSTNode *BST::findMax(BSTNode *node)
{
    while (node->getRight())
    {
        node = node->getRight();
    }
    return node;
}
BSTNode *BST::findMin(BSTNode *node)
{
    while (node->getLeft())
    {
        node = node->getLeft();
    }
    return node;
}
BSTNode *BST::remove(BSTNode *tree, int val)
{
    cout<<"HIHIH";
    BSTNode *t;
    if (val < tree->getInfo())
    {
        t = remove(tree->getLeft(), val);
        tree->setLeft(t);
    }
    else if (val > tree->getInfo())
    {
        t = remove(tree->getRight(), val);
        tree->setRight(t);
    }
    else if ((tree->getLeft()) && (tree->getRight()))
    {
        BSTNode *minNode = findMin(tree->getRight());
        tree->setInfo(minNode->getInfo());
        t = remove(tree->getRight(), minNode->getInfo());
        tree->setRight(t);
    }
    else
    {
        BSTNode *del = tree;
        if (tree->getLeft() == NULL)
            tree = tree->getRight();
        else if (!(tree->getRight()))
            tree = tree->getLeft();
        else
            tree = NULL;
        delete del;
    }
    return tree;
}
// BSTNode* BST::remove(BSTNode *node,int val)
// {
//     BSTNode* del = node;
//     if(root->getInfo()==val&&root!=NULL)
//     {
//         BSTNode* rootRight=root->getRight(),*p= root->getRight();
//         while(p->getLeft()!=NULL)
//             p=p->getLeft();
//         root->setInfo(p->getInfo());
//         del = p;
//     }
//     while(node!=NULL||node->getInfo()!=val){
//         if(node->getInfo()>val)
//             node = node->getLeft();
//         else
//             node = node->getRight();
//     }
//     if(node==NULL){
//         cout<<"Already Empty or not found the value";
//     }
//     else if(node->getLeft()==0&&node->getRight()==0)
//         del = node;
//     else if(node->getLeft()==0){
//         node->getRight()->setParent(node->getParent());
//         node->getParent()->setLeft(node->getRight());
//         del = node;
//     }
//     else if(node->getRight()==0)
//     {
//         node->getParent()->setRight(node->getLeft());
//         node->setParent(NULL);
//         del = node;
//     }
//     else
//         cout<<"Errror";
//     delete del;
//     return 0;
// }
int main()
{
    BST obj;
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
    obj.insert(40);
    obj.inorder(obj.root);
    if (obj.search(10))
        cout << "FOund\n";
    cout << "MAx: " << obj.findMax(obj.root)->getInfo() << endl;
    cout << "Min: " << obj.findMin(obj.root)->getInfo() << endl;

    obj.remove(obj.root, 10);
    obj.inorder(obj.root);
    return 0;
}
