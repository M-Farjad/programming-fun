#include <algorithm>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
class avl_node
{
public:
    int data;
    int height;
    avl_node *left;
    avl_node *right;
    avl_node(int val = 0) : data(val), height(), left(), right() {}
};
avl_node *root;
avl_node *temp1;

// Class Declaration
class avlTree
{
public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node *balance(avl_node *);
    avl_node *balanceTree(avl_node *);
    avl_node *insert(avl_node *, int);
    void display(avl_node *, int);
    void drawNode(avl_node *, int, int, int);
    void drawTree(avl_node *, int, int);
    void inorder(avl_node *);
    void preorder(avl_node *);
    void postorder(avl_node *);
    int validate(string s);
    bool checkInput(string s);
    avlTree()
    {
        root = NULL;
        temp1 = NULL;
    }
};

// Driver Code
int main()
{
    int choice,
        item; // for storing the value to be inserted
    int c;
    string str;
    avlTree avl;

    cout << "\n---------------------" << endl;
    cout << "AVL Tree Implementation" << endl;
    cout << "\n---------------------" << endl;
    cout << "1.Insert Element into the tree" << endl;
    cout << "2.Display the tree" << endl;
    cout << "3.Balance Tree" << endl;
    cout << "4.PreOrder traversal" << endl;
    cout << "5.InOrder traversal" << endl;
    cout << "6.PostOrder traversal" << endl;
    cout << "7.Exit" << endl;

    while (1)
    {
        cout << "\nEnter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            // Accept input as string
            cout << "Enter the value "
                 << "to be inserted: ";
            cin >> str;
            c = avl.validate(str);

            if (c == 100)
            {
                item = std::stoi(str);
                root = avl.insert(root, item);
            }
            else
                cout << "\n\t\tInvalid Input!" << endl;

            break;
        case 2:
            if (root == NULL)
                cout << "Tree is Empty" << endl;

            avl.display(root, 1);
            break;
        case 3:
            root = avl.balanceTree(root);

            break;
        case 4:
            cout << "Preorder Traversal : ";
            avl.preorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Inorder Traversal: " << endl;
            avl.inorder(root);
            cout << endl;
            break;
        case 6:
            cout << "Postorder Traversal: " << endl;
            avl.postorder(root);
            cout << endl;
            break;
        case 7:
            exit(1);
            break;
        default:
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
int avlTree::height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent)
{
    // left rotation
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
avl_node *avlTree::ll_rotation(avl_node *parent)
{
    // right rotation
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

// Function to perform the Left-Right Rotation
avl_node *avlTree::lr_rotation(avl_node *parent)
{
    // left-subtree -> right		//left+ right
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

// Function to perform the Right-Left Rotation
avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

// Function to balance the tree
avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    cout << "balance factor of "<<temp->data<<"is : " << bal_factor<<endl;
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
        {
            temp = ll_rotation(temp);
            cout << "LL";
        }
        else
        {
            temp = lr_rotation(temp);
            cout << "lr";
        }
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
        {
            temp = rl_rotation(temp);
            cout << "lr";
        }
        else
        {
            temp = rr_rotation(temp);
            cout << "rr";
        }
    }

    return temp;
}
// Function to display the AVL Tree
void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level + 1);
        printf("\n");
        if (ptr == root)
            cout << "Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout << "	 ";

        cout << ptr->data;
        display(ptr->left, level + 1);
    }
}

// Function to balance the tree
avl_node *avlTree::balanceTree(avl_node *root)
{
    if (root == NULL)
        return NULL;

    root->left = balanceTree(root->left);

    root->right = balanceTree(root->right);

    root = balance(root);
    return root;
}

avl_node *avlTree::insert(avl_node *root, int value)
{

    if (root == NULL)
    {
        root = new avl_node(value);
        return root;
    }

    if (value < root->data)
        root->left = insert(root->left, value); // basically returning its node

    else if (value > root->data)
        root->right = insert(root->right, value); // basically returning its node

    else
        cout << "\n\tValue already"
             << " exists!" << endl;

    return root;
}

void avlTree::inorder(avl_node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";

    inorder(root->right);
}
void avlTree::preorder(avl_node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void avlTree::postorder(avl_node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
bool avlTree::checkInput(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}
int avlTree::validate(string str)
{
    if (checkInput(str))
        return 100;
    else
        return 10;
}