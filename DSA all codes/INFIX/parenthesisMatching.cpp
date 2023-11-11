#include <iostream>
using namespace std;

// class StNode
// {
// private:
//     char data;
//     StNode *next;

// public:
//     StNode(int val = 0) : data(val)
//     {
//         next = NULL;
//     }
//     ~StNode() {}
//     friend class StackLL;
// };
// class StackLL
// {
// private:
//     StNode *head;

// public:
//     bool isEmpty()
//     {
//         return head == NULL;
//     }
//     StackLL()
//     {
//         head = NULL;
//     }
//     int top()
//     {
//         return head->data;
//     }
//     int pop()
//     {
//         if (isEmpty())
//             cout << "Stack Already Empty ... !";
//         else
//         {
//             StNode *tempN = head;
//             int temp = head->data;
//             head = head->next;
//             delete tempN;
//             return temp;
//         }
//         return 0;
//     }
//     void push(int val)
//     {
//         StNode *node = new StNode(val);
//         node->next = head;
//         head = node;
//     }
//     void display()
//     {
//         StNode *temp = head;
//         cout << "List : ";
//         while (temp != NULL)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };

// bool checkBalanced(string expression)
// {
//     StackLL s;
//     for (int i = 0; i < expression.length(); i++)
//     {
//         if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
//             s.push(expression[i]);
//         else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
//         {
//             if (s.isEmpty())
//                 return false;
//             else if (s.top() == '[' && expression[i] != ']')
//                 return false;
//             else if (s.top() == '{' && expression[i] != '}')
//                 return false;
//             else if (s.top() == '(' && expression[i] != ')')
//                 return false;
//             else
//                 s.pop();
//         }
//     }
//         return s.isEmpty() ? true : false;
// }
int main()
{
    // (checkBalanced("{}}}"))?cout<<"true":cout<<"false";
    try
    {
        int b = 0;
        if(b==0)
            throw b;
        int res = 10 / b;
    }
    catch (int e)
    {
        cout << "zero division error "<<e;
    }

    return 0;
}