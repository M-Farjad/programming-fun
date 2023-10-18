#include<iostream>
#include<stack>

using namespace std;
class BSTNode
{
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;
	char Info;
public:
	BSTNode(int val = 0)
	{
		Info = val;
		this->parent = this->left = this->right = NULL;
	}
	void setparent(BSTNode* parent = NULL)
	{
		this->parent = parent;
	}
	void setleft(BSTNode* left = NULL)
	{
		this->left = left;
	}
	void setright(BSTNode* right = NULL)
	{
		this->right = right;
	}
	void setinfo(char Info)
	{
		this->Info = Info;
	}
	BSTNode* getparent()
	{
		return this->parent;
	}
	BSTNode* getleft()
	{
		return this->left;
	}
	BSTNode* getright()
	{
		return this->right;
	}
	char getInfo()
	{
		return Info;
	}
};

class ExpTree
{
public:
	BSTNode* root;

	ExpTree()
	{
		root = NULL;
	}
	void insertion(string str)
	{
		stack<BSTNode*> s;	
		cout << str.length() << endl;		//ab+e*f/
		for (int i = 0; i < str.length(); i++)
		{
			BSTNode* newnode = new BSTNode(str[i]);
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			{
				newnode->setright(s.top());
				s.pop();
				newnode->setleft(s.top());
				s.pop();
				
			}
			s.push(newnode);
		}
		root = s.top();
	}
	void Inorder(BSTNode* tree)
	{
		if (tree)
		{
			Inorder(tree->getleft());
			cout << tree->getInfo() << "  ";
			Inorder(tree->getright());
		}
	}
};
int main()
{
	ExpTree t;
	t.insertion("ab+cde+**");
	t.Inorder(t.root);
}