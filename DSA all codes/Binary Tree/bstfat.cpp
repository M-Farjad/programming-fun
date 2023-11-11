#include <iostream>
using namespace std;

class Node
{
    Node *parent;
    Node *right;
    Node *left;
    int data;

public:
    Node(int val=0):data(val)
    {
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    void setparent(Node *parent)
    {
        this->parent = parent;
    }
    void setleft(Node *left)
    {
        this->left = left;
    }
    void setright(Node *right)
    {
        this->right = right;
    }
    void setdata(int data)
    {
        this->data = data;
    }
    Node *getparent()
    {
        return this->parent;
    }
    Node *getleft()
    {
        return this->left;
    }
    Node *getright()
    {
        return this->right;
    }
    int getdata()
    {
        return this->data;
    }
    friend class BST;
};
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    void insert(int val)
    {
        Node *curr = root;
        Node *prev = 0;

        while (curr != NULL && root != 0)
        {
            prev = curr;
            if (val < curr->getdata())
                curr = curr->getleft();
            else
                curr = curr->getright();
        }
        if (root == 0)
        {
            Node *newnode = new Node();
            newnode->setdata(val);
            root = newnode;
        }
        else if (val < prev->getdata())
        {
            Node *newnode = new Node();
            newnode->setdata(val);
            newnode->setparent(prev);
            prev->setleft(newnode);
        }
        else
        {
            Node *newnode = new Node();
            newnode->setdata(val);
            newnode->setparent(prev);
            prev->setright(newnode);
        }
    }
    void Inorder(Node *node)
    {
        if (node != NULL)
        {
            Inorder(node->getleft());
            cout << node->getdata()<<" ";
            Inorder(node->getright());
        }
    }
};
int main()
{
    BST tree;
    tree.insert(67);
    tree.insert(56);
    tree.insert(65);
    tree.Inorder(tree.root);
}