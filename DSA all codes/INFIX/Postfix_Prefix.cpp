#include <iostream>
using namespace std;
class node
{
private:
	int data;
	node *next;

public:
	node(int value)
	{
		data = value;
		next = NULL;
	}

	friend class linkedListStack;
};

class linkedListStack
{
private:
	node *head;

public:
	linkedListStack()
	{
		head = NULL;
	}
	void push(int value)
	{
		node *newNode = new node(value);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	int pop()
	{
		// if (head == NULL) {
		// 	return ;
		// }
		if (head->next == NULL)
		{
			int value = head->data;
			node *del = head;
			head = head->next;
			delete del;
			return value;
		}
		node *temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		int value = temp->next->data;
		node *del = temp->next;
		temp->next = temp->next->next;
		delete del;
		return value;
	}
	int top()
	{
		if (head == NULL)
		{
			return -1;
		}
		if (head->next == NULL)
		{
			return head->data;
		}
		node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp->data;
	}
	bool empty()
	{
		return (head == NULL);
	}
	void display()
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "NULL\n";
	}
};

class arrayStack
{
private:
	int *arr;
	int top;
	int size;

public:
	arrayStack(int size)
	{
		arr = new int[size];
		top = -1;
		this->size = size;
	}
	bool isFull()
	{
		return (top == size - 1);
	}
	void push(int value)
	{
		if (top == size - 1)
		{
			cout << "Stack Overflow" << endl;
			return;
		}
		arr[++top] = value;
	}
	void pop()
	{
		if (top == -1)
		{
			cout << "Stack Underflow" << endl;
			return;
		}
		top--;
	}

	int peek()
	{
		if (top == -1)
		{
			cout << "Stack Underflow" << endl;
			return -1;
		}
		return arr[top];
	}
	bool empty()
	{
		return (top == -1);
	}
	void display()
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << "->";
		}
		cout << "NULL\n";
	}
};

void evaluateExpression(string str)
{
	cout << "Evaluation: ";
	linkedListStack s;
	for (int i = 0; i < str.length(); i++)
	{

		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			int num1 = s.pop();
			int num2 = s.pop();
			switch (str[i])
			{
			case '+':
				s.push(num1 + num2);
				break;
			case '-':
				s.push(num1 - num2);
				break;
			case '/':
				s.push(num1 / num2);
				break;
			case '*':
				s.push(num1 * num2);
				break;
			}
		}
		else
		{
			s.push(int(str[i] - '0'));
		}
	}
	// cout << endl;
	cout << s.pop();
}

int checkStack(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '%':
	case '/':
		return 4;
	case '(':
		return 0;
	case '^':
		return 5;
	}
	return 0;
}

int checkStr(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '%':
	case '/':
		return 3;
	case '(':
		return 100;
	case '^':
		return 6;
	}
	return 0;
}

string infixToPostfix(string str)
{
	linkedListStack s;
	string des = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			des += str[i];
		}
		else if (str[i] == '(')
		{
			s.push(str[i]);
		}

		else if (str[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				des += char(s.top());
				s.pop();
			}
			if (!s.empty())
			{
				s.pop();
			}
		}
		else
		{
			while (!s.empty() && checkStack(char(s.top())) > checkStr(str[i]))
			{
				des += char(s.top());
				s.pop();
			}
			s.push(str[i]);
		}
	}
	while (!s.empty())
	{
		des += s.top();
		s.pop();
	}
	cout << endl
		 << des << endl;
	return des;
}

void infixToPrefix(string str)
{
	string revStr = "";
	cout << endl
		 << str << endl;

	int length = str.length();
	for (int i = length; i >= 0; i--)
	{
		revStr += str[i];
	}
	cout << endl
		 << revStr << endl;
	for (int i = 0; i < str.length(); i++)
	{
		if (revStr[i] == '(')
		{
			revStr[i] = ')';
		}
		if (revStr[i] == ')')
		{
			revStr[i] = '(';
		}
	}
	linkedListStack s;
	string postfix;
	postfix = infixToPostfix(revStr);
	revStr = "";
	for (int i = postfix.length(); i >= 0; i--)
	{
		revStr += postfix[i];
	}
	cout << endl
		 << revStr << endl;
}

bool isBalanced(string str)
{
	linkedListStack s;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			if (str[i] == ')' && s.top() == '(')
			{
				s.pop();
			}
			else if (str[i] == '}' && s.top() == '{')
			{
				s.pop();
			}
			else if (str[i] == ']' && s.top() == '[')
			{
				s.pop();
			}
			else
			{
				s.push(str[i]);
			}
		}
	}
	return (s.empty());
	// if (s.empty()) {
	// 	return true;
	// }
	// else {
	// 	return false;
	// }
}

int main()
{
	cout << "Default Linked List Stack:\n";
	linkedListStack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	cout << "Default Array stack:\n";
	arrayStack s1(5);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.display();

	cout << "Peek 1st:" << s1.peek() << endl;
	s1.pop();

	cout << "Peek 2nd:" << s1.peek() << endl;
	cout << "Empty:" << s1.empty() << endl;
	s1.display();
	cout << "checking balance function:";
	if (isBalanced("({]}{}[])"))
		cout << "balanced";
	else
		cout << "Not balanced\n";
	cout << "\nInfix to Postfix expression: ";

	infixToPostfix("2+6*5+7");
	cout << "Infix to Prefix expression: ";

	infixToPrefix("3+9/2-4");
	evaluateExpression("375*+6+");
}