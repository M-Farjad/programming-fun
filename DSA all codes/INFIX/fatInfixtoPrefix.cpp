#include <iostream>
#include<list>
using namespace std;

class Node
{
public:
    Node *next;
    char data;

public:
    Node(char c)
    {
        next = NULL;
        data = c;
    }
};
class Stack
{
    Node *head;
    int length = 0;

public:
    Stack()
    {
        head = NULL;
    }
    bool IsEmpty()
    {
        return head == NULL;
    }
    void Push(char c)
    {
        Node *newnode = new Node(c);
        if (IsEmpty())
        {
            head = newnode;
        }
        else
        {
            // head->next = newnode;
            // head = newnode;
            newnode->next=head;
            head=newnode;
        }
        length++;
    }
    Node *Pop()
    {
        if(IsEmpty())
            return NULL;
        Node *temp = head;
        head = head->next;
        return temp;
    }
    char top()
    {
        return head->data;
    }
    void display(){
        Node* temp = head;
        for ( ; temp!=NULL;temp=temp->next){
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
};
int inputprec(char input)
{
    int num = 0;
    if (input == '+' || input == '-')
        num = 1;
    else if (input == '*' || input == '/' || input == '%')
        num = 2;
    else if (input == '^')
        num = 7;
    return num;
}
int outputprec(char input)
{
    int num = 0;
    if (input == '+' || input == '-')
        num = 1;
    else if (input == '*' || input == '/' || input == '%')
        num = 2;
    else if (input == '^')
        num = 3;
    return num;
}
string InfixToPrefix(string infix)
{
    string temp;
    string add;
    Stack s;
    Node *n = nullptr;
    for (int i = infix.length() - 1; i >= 0; i--)
    {
        temp += infix[i];
    }
    infix = temp;
    for (int i = 0; i < infix.length(); i++)
    {
        if ((infix[i] >= '0' && infix[i] <= '9') || (infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            add += infix[i];
        }
        else if (s.IsEmpty())
            s.Push(infix[i]);
        else if (infix[i] == ')' || s.top() == ')')
        {
            s.Push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (s.top() != ')')
            {
                n = s.Pop();
                add += n->data;
            }
            s.Pop();
        }
        else
        {
            while (!s.IsEmpty() && (inputprec(s.top()) > outputprec(infix[i])))
            {
                n = s.Pop();
                add += n->data;
            }
            s.Push(infix[i]);
        }
    }
    while (!s.IsEmpty())
    {
        n = s.Pop();
        add += n->data;
    }
    temp = "";
    for (int i = add.length() - 1; i >= 0; i--)
    {
        temp += add[i];
    }
    add = temp;
    return add;
    delete n;
}
int main()
{
    list<int> L;
    L.push_back(20);
    L.push_front(40);
    L.push_back(33);
    L.push_front(60);
    for (list<int>::iterator i=L.begin(); i!=L.end(); i++)
       cout << *i << " ";
    cout << endl;
    // string str = "2+7-8*7";
    // cout << InfixToPrefix(str);
    // Stack s;
    // s.Pop();
    // s.Push('2');
    // s.Push('1');
    // s.Push('4');
    // s.Pop();
    // s.Pop();

    // s.display();
}

// #include <iostream>
// using namespace std;
// template <typename T>
// class Weight
// {
// private:
//     T kg;

// public:
//     void setData(T x)
//     {
//         kg = x;
//     }
//     T getData() {return kg;}
// };
// int main()
// {
//     Weight<int> obj1;
//     obj1.setData(5);
//     cout << "Value is: " << obj1.getData() << endl;
//     return 0;
// }