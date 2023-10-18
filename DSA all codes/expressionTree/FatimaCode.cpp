#include <iostream>
#include <string>
#include <stack>
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
    ExpTreeNode *evaluateExpTree(ExpTreeNode *root);
    void levelOrder2queue(ExpTreeNode *root);
    void levelOrder1queue(ExpTreeNode *root);
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
ExpTreeNode *ExpTree::evaluateExpTree(ExpTreeNode *root)
{
    cout << "\nEvaluation: ";
    evaluateExpTree(root->getLeft());
}

void ExpTree::levelOrder1queue(ExpTreeNode *root)
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
            cout << temp->getInfo()<<"  ";
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

void ExpTree::levelOrder2queue(ExpTreeNode *root)
{
    if (!root)
        return;
    queue<ExpTreeNode *> q1;
    queue<ExpTreeNode *> q2;
    q1.push(root);
    while (!q1.empty() || !q2.empty())
    {
        while (!q1.empty())
        {
            root = q1.front();
            cout << root->getInfo();
            q1.pop();
            if (root->getLeft())
                q2.push(root->getLeft());
            if (root->getRight())
                q2.push(root->getRight());
        }
            cout << endl;
        while (!q2.empty())
        {
            root = q2.front();
            cout << root->getInfo() << "\t";
            q2.pop();
            if (root->getLeft())
                q1.push(root->getLeft());
            if (root->getRight())
                q1.push(root->getRight());
        }
    }
}

// The main function to convert infix expression
// to postfix expression
string infixToPostfix(string s)
{

    stack<char> st; // For stack operations, we are using
                    // C++ built in stack
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If the scanned character is
        // an operand, add it to output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
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
    cout << "Enter an infix expression: ";
    cin >> inExp;
    string postFix = infixToPostfix(inExp);
    // t.insertion("ab*c/ef/g*+k+xy*-");       //ab+cde+**
    t.insertion(postFix); // ab+cde+** //a+b*2*3-4-i
    cout << "Postfix is : " << postFix << endl;
    t.inorder(t.root);
    // t.evaluateExpTree(t.root);
    cout << "Level 2 order: \n";
    t.levelOrder2queue(t.root);
    cout << "\nLevel 1 order: \n";
    t.levelOrder1queue(t.root);
    return 0;
}