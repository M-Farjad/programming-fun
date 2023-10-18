// C++ program to insert a node in AVL tree
#include <iostream>
#include<queue>

using namespace std;

class QueueNode
{
public:
    int data;
    QueueNode *next;
    QueueNode(int d = -1)
    {
        data = d;
        next = NULL;
    }
};
class QueueLL
{
    QueueNode *head, *tail;
    int length;
public:
	bool isEmpty(){
		return (head);
	}
    QueueLL()
    {
        head = tail = NULL;
        length = 0;
    }
    void enQueueLL(int);
    int deQueueLL();
    void display();
    int getlength();
};QueueLL myQueue;
int QueueLL::deQueueLL()
{
    if (isEmpty())
    {
        cout << "Empty QueueLL ... !";
    }
    else
    {
        QueueNode *temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        length--;
        return data;
    }
    return -1;
}
void QueueLL::enQueueLL(int val)
{
    QueueNode *node = new QueueNode(val);
    if (!isEmpty())
    {
        tail->next = node;
        tail = node;
    }
    else
    {
        head = tail = node;
    }
    length++;
}
void QueueLL::display()
{
    QueueNode *temp = head;
    cout << endl;
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << "NULL\nLength: " << length;
    cout << endl;
}
// An AVL tree QueueNode
class Node
{

public:

	int key;		//data
	Node *left;
	Node *right;
	// Node* prev;
	int height;
};

// A utility function to get the
// height of the tree

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}

/* Helper function that allocates a
new node with the given key and
NULL left and right pointers. */
Node *newNode(int key)
{
	Node *node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially
					  // added at leaf
	return (node);
}

// A utility function to right
// rotate subtree rooted with y
Node *rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) +
				1;
	x->height = max(height(x->left),
					height(x->right)) +
				1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) +
				1;
	y->height = max(height(y->left),
					height(y->right)) +
				1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

// Recursive function to insert a key
// in the subtree rooted with node and
// returns the new root of the subtree.
Node *insert(Node *node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return (newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height =  1+max(height(node->left),
						   height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

// A utility function to print preorder,inOrder,postOrder
// traversal of the tree.
// The function also prints height
// of every node
void preOrder(Node *root)
{
	if (root != NULL)
	{
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
	// cout<<"Height: "<<height;
}
void inOrder(Node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);
		cout << root->key << " ";
		inOrder(root->right);
	}
}
void postOrder(Node *root)
{
	if (root != NULL)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout << root->key << " ";
	}
}
void levelOrder(Node* root){
	
	Node* temp = root;
	if(root==NULL)
		return;
	myQueue.enQueueLL(root->key);
	while (!(myQueue.isEmpty()))
	{
		cout<<myQueue.deQueueLL()<<" ";
		levelOrder(root->left);
		levelOrder(root->right);
	}
	
}
// Driver Code
int main()
{
	Node *root = NULL;

	/* Constructing tree given in
	the above figure */
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	root = insert(root, 35);

	/* The constructed AVL Tree would be
			 30
			/  \
		   20   40
		  / \   / \
		 10 25 35  50
	*/
	cout << "Preorder traversal of the "
			"constructed AVL tree is \n";
	preOrder(root);
	cout << "\n";
	inOrder(root);
	cout << "\n";
	postOrder(root);
	cout << "\n";
	cout << "Root height: " << height(root);
	root = insert(root, 55);
	/* The constructed AVL Tree would be
			 30
			/  \
		   20   40
		  / \   / \
		 10 25 35  50
					\
					55
	*/
	cout << "\nRoot height: " << height(root);
	root = insert(root, 60);
	/* The constructed AVL Tree would be
			 30										40
			/  \								   /  \
		   20   40								  30   55
		  / \   / \				=>				 / \  /  \
		 10 25 35  50                           20 35 50 60
				  / \						   / \
				NULL 55						  10 25
			    /	  \				
				NULL  60
	*/
	cout << "Root height: " << height(root);
	levelOrder(root);
	return 0;
}