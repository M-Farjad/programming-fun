#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
#include<stack>
#include<string>
// Min and max values only for testing
constexpr const int maxValue = 100;
constexpr auto minValue = 1;
using namespace std;

//class Declaration
class TreeNode;
class StackNode;
class ExpressionTree;

//class Defination
class TreeNode
{
private:
	int value;
	char letter;
	TreeNode* left;
	TreeNode* right;
public:
	TreeNode(char l = '\0', int v = 0) : left(NULL), right(NULL)
	{
		value = v;
		letter = l;
	}

	friend class StackNode;
	friend class ExpressionTree;
};

class StackNode
{
public:
	TreeNode* treeNode;					//Tree Node to hold the expression tree in Stack Node
	StackNode* top;
	StackNode(TreeNode* treeNode) : top(NULL)
	{
		this->treeNode = treeNode;
	}

	TreeNode* getTreeNode()
	{
		return treeNode;
	}

	StackNode* getStackTop()
	{
		return top;
	}

	friend class ExpressionTree;
};

class ExpressionTree {
public:								//public access is used to access it in Main function directly
	StackNode* root;
	int n;							//for size f the expressoin tree

	ExpressionTree() : root(NULL) { n = 0; }

	int size() const				//Return size of expression tree
	{
		return n;
	}

	bool isEmpty() const
	{
		return (root == NULL);
	}

	bool isRoot() const
	{
		return (root->treeNode->left != NULL) && (root->treeNode->right != NULL);
	}

	bool isLeaf() const
	{
		return (root->treeNode->left == NULL) && (root->treeNode->right == NULL);
	}

	StackNode* getRoot() const
	{
		return root;
	}

	TreeNode* top() const
	{
		return root->treeNode;
	}

	TreeNode* getTree() const
	{
		return root->treeNode;
	}

	TreeNode* getLeft() const
	{
		return root->treeNode->left;
	}

	TreeNode* getRight() const
	{
		return root->treeNode->right;
	}

	TreeNode* pop()
	{
		if (root == NULL)
		{
			cout << "Cannot pop!" << endl;
		}
		else
		{
			TreeNode* ptr = root->treeNode;
			root = root->top;
			return ptr;
		}
	}

	void push(TreeNode* ptr)
	{
		if (root == NULL)
			root = new StackNode(ptr);
		else
		{
			StackNode* nptr = new StackNode(ptr);
			nptr->top = root;
			root = nptr;
		}
	}

	int randomValue()
	{
		int x = 0;
		x = (rand() % (maxValue - minValue + 1)) + minValue;
		cout << "Random Value assign to variable: " << x << endl;
		return x;
	}

	void insert(char val)			//function that inserts operator/operand in TreeNode
	{
		if (isOperand(val))			//if the character is operand then just add it in TreeNode
		{
			TreeNode* nptr = new TreeNode(val, randomValue());
			push(nptr);				//Push the treeNode pointer on StackNode
		}
		else if (isOperator(val))	//if the character is operator then pop  
			//from the top of stack and add it to TreeNode's right and left respectively
		{
			TreeNode* nptr = new TreeNode(val);
			nptr->right = pop();
			nptr->left = pop();
			push(nptr);				//Push the treeNode pointer on StackNode
		}
	}

	bool isOperand(char ch)			//Function that check the character is Alphabet or not
	{
		return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
	}

	bool isOperator(char ch)		//Function that check the character is operator or not
	{
		return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
	}

	void buildTree(string eqn)		//Function that calls insert function in a for loop 
		// that iterates = to the length of expression to build tree from the expression
	{
		for (int i = 0; i <= eqn.length(); i++)
			insert(eqn[i]);
	}

	double evaluate(TreeNode* ptr)					//Recursive function to Evaluate ExpressionTree
	{
		if (ptr->left == NULL && ptr->right == NULL)//If the Tree left and right is NULL then return value //Base condition
			return ptr->value;
		else
		{
			double result = 0.0;
			double left = evaluate(ptr->left);
			double right = evaluate(ptr->right);
			char op = ptr->letter;
			switch (op)
			{
			case '+':
				result = left + right;
				break;
			case '-':
				result = left - right;
				break;
			case '*':
				result = left * right;
				break;
			case '/':
				result = left / right;
				break;
			default:
				cout << "Invalid expression." << endl;
				break;
			}
			return result;
		}
	}

	int prec(char c)	//Function that checks the Precision of the operator to convert infix exp. to postfix exp.
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '-' || c == '+')
			return 1;
		else
			return 0;
	}

	string InfixtoPostfix(string exp)
	{
		stack<char> s;				//A STL Stack to convert infix expression to postfix
		string postfix;
		int expLength = exp.length();
		for (int i = 0; i < expLength; i++)
		{
			if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z'))
			{
				postfix += exp[i];
			}
			else if (exp[i] == '(')
			{
				s.push('(');
			}
			else if (exp[i] == ')')
			{
				while (s.top() != '(')
				{
					char c = s.top();
					postfix += c;
					s.pop();

				}
				if (s.top() == '(')
					s.pop();
			}
			else
			{
				while (!s.empty() && prec(exp[i]) <= prec(s.top()))
				{
					char c = s.top();
					postfix += c;
					s.pop();

				}
				s.push(exp[i]);
			}

		}

		while (!s.empty())			//If the stack if not empty then pop all the values and add them in postfix exp.
		{
			char c = s.top();
			postfix += c;
			s.pop();

		}

		return postfix;
	}

	string infixtoExpTree()			//The main function of Expressoin tree that is used to build expression tree
	{
		string postfix, userInput;
		postfix = userInput = "\0";
		cout << "Enter the infix expression: ";
		cin >> userInput;
		postfix = InfixtoPostfix(userInput);
		buildTree(postfix);
		return userInput;
	}

	void inlineDisplay(TreeNode* head)
	{
		if (head == NULL)
			return;

		inlineDisplay(head->left);
		cout << "(" << head->value << ") ";		//The values of the operand are coverd with brackets
		cout << head->letter << " ";
		inlineDisplay(head->right);
	}
};

int main()
{
	ExpressionTree tree;					//Expression tree Object to use Expression class Function

	int choice = 1;
	do
	{
		cout << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|          Expression Tree             |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "|                                      |" << endl;
		cout << "| [1] Infix to Expression Tree         |" << endl;
		cout << "| [2] Evaluate Expression Tree         |" << endl;
		cout << "| [3] Display Expression Tree          |" << endl;
		cout << "| [4] Quit                             |" << endl;
		cout << "+--------------------------------------+" << endl;
		cout << "\n Enter your choice between [1-4] : ";
		cin >> choice;

		if (choice == 1)
		{
			cout << endl << tree.infixtoExpTree();
		}
		else if (choice == 2)
		{
			cout << "Result: " << tree.evaluate(tree.root->treeNode);
		}
		else if (choice == 3)
		{
			tree.inlineDisplay(tree.root->treeNode);
		}
		else if (choice == 4)
		{
			break;
		}

	} while (true);

	return 0;
}