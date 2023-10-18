#include <iostream>
#include <string>
#include <stack>
#include <conio.h>

#include <queue>

using namespace std;
class ExpTreeNode
{
public:
    ExpTreeNode();
    ExpTreeNode(char value);
    void setLeft(ExpTreeNode *left);
    void setRight(ExpTreeNode *right);
    ExpTreeNode *getLeft();
    ExpTreeNode *getRight();
    ExpTreeNode *getParent();
    char getInfo();
    void setInfo(char info);

private:
    ExpTreeNode *parent;
    ExpTreeNode *left;
    ExpTreeNode *right;
    char info;
};

ExpTreeNode::ExpTreeNode()
{
    this->info = -1;
    this->left = this->right = this->parent = NULL;
}
ExpTreeNode::ExpTreeNode(char value)
{
    this->info = value;
    this->left = this->right = this->parent = NULL;
}
void ExpTreeNode::setLeft(ExpTreeNode *left)
{
    this->left = left;
}
void ExpTreeNode::setRight(ExpTreeNode *right)
{
    this->right = right;
}
ExpTreeNode *ExpTreeNode::getLeft()
{

    return this->left;
}
ExpTreeNode *ExpTreeNode::getRight()
{

    return this->right;
}
ExpTreeNode *ExpTreeNode::getParent()
{

    return this->parent;
}
char ExpTreeNode::getInfo()
{

    return this->info;
}
void ExpTreeNode::setInfo(char info)
{

    this->info = info;
}
class ExpTree
{
public:
    ExpTreeNode *root;
    void inorder(ExpTreeNode *);
    void insertion(string);
    float evaluateExpTree(ExpTreeNode *root);
    void levelOrder(ExpTreeNode *root);
};

void ExpTree::insertion(string str)
{
    stack<ExpTreeNode *> mystack;
    cout << "Length of string: " << str.length() << endl; // ab+e*f/
    for (int i = 0; i < str.length(); i++)
    {
        ExpTreeNode *node = new ExpTreeNode(str[i]);
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            node->setRight(mystack.top());
            mystack.pop();
            node->setLeft(mystack.top());
            mystack.pop();
        }
        mystack.push(node);
    }
    root = mystack.top();
    mystack.pop();
    if (!(mystack.empty()))
    {
        cout << "Wrong expression";
    }
}
void ExpTree::inorder(ExpTreeNode *node)
{
    if (node)
    {
        if ((node->getLeft()) && (node->getRight()))
            cout << "(";
        inorder(node->getLeft());
        cout << node->getInfo() << " ";
        inorder(node->getRight());
        if ((node->getLeft()) && (node->getRight()))
            cout << ")";
    }
}

// Function to return precedence of operators
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

float ExpTree::evaluateExpTree(ExpTreeNode *root)
{
    if (!root)
        return 0;
    else if (!root->getLeft() && !root->getRight())
    {
        if (root->getInfo() >= '0' && root->getInfo() <= '9')
            return (int(root->getInfo()) - 48);
        else
            return root->getInfo();
    }
    else // if (root)
    {
        float var1 = evaluateExpTree(root->getLeft());
        float var2 = evaluateExpTree(root->getRight());
        cout << endl
             << "Variable 1 is: " << var1;
        cout << endl
             << "Variable 2 is: " << var2;
        cout << endl;
        if (root->getInfo() == '+')
            return var1 + var2;
        else if (root->getInfo() == '-')
            return var1 - var2;
        else if (root->getInfo() == '/')
            return var1 / var2;
        return var1 * var2;
    }
}

void ExpTree::levelOrder(ExpTreeNode *root)
{
    queue<ExpTreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        ExpTreeNode *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->getInfo() << "  ";
            if (temp->getLeft())
            {
                q.push(temp->getLeft());
            }
            if (temp->getRight())
            {
                q.push(temp->getRight());
            }
        }
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char character = s[i];
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z') || (character >= '0' && character <= '9'))
            result += character;
        else if (character == '(')
            st.push('(');
        else if (character == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(character);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}
int main()
{
    ExpTree t;
    string inExp;
    int count = 0;
    cout << "Enter an infix expression: ";
    cin >> inExp;
    string postFix = infixToPostfix(inExp);
    t.insertion(postFix); // ab+cde+** //a+b*2*3-4-i
    int choice;
    do
    {
        system("cls");
        cout << "Enter values (1,2,3,4,5) to perform it's functionality" << endl;
        cout << "1->DISPLAY INFIX EXPRESSION" << endl;
        cout << "2->DISPLAY POSTFIX EXPRESSION" << endl;
        cout << "3->DISPLAY INORDER TRAVERSAL OF EXPRESSION TREE" << endl;
        cout << "4->DISPLAY LEVEL ORDER TRAVERSAL OF EXPRESSION TREE" << endl;
        cout << "5->DISPLAY THE SOLUTION OF EXPRESSION TREE" << endl;
        cout << "-1->EXIT THE SYSTEM" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "The infix is: " << inExp;
        }
        else if (choice == 2)
        {
            cout << "Postfix is : " << postFix << endl;
        }
        else if (choice == 3)
        {
            cout << "Expression with brackets : ";
            t.inorder(t.root);
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << "\nLevel order: \n";
            t.levelOrder(t.root);
        }
        else if (choice == 5)
        {
            cout << "\nEvalatuing Expression : ";
            float result = t.evaluateExpTree(t.root);
            cout << "\nThe Result is: " << result;
        }
        else if (choice == -1)
        {
            exit(0);
            break;
        }
        else{
            cout<<"Invalid choice ... !";
        }
    getch();
    } while (true);

    return 0;
}
