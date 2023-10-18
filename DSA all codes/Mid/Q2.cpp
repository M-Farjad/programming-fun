// #include <iostream>
// using namespace std;

// class StNode
// {
//     // private:
// public:
//     union
//     {
//         char cdata;
//         float fdata;
//     };
//     StNode *next;
//     StNode(char val) : cdata(val)
//     {
//         next = NULL;
//     }
//     StNode(float val) : fdata(val)
//     {
//         next = NULL;
//     }
//     ~StNode() {}
//     // friend class StackLL;
// };
// template <typename T>
// class StackLL
// {
// private:
//     StNode *head;
//     bool isEmpty()
//     {
//         return head == NULL;
//     }

// public:
//     StackLL()
//     {
//         head = NULL;
//     }
//     T ftop()
//     {
//         return head->fdata;
//     }
//     T fpop()
//     {
//         if (isEmpty())
//             cout << "Stack Already Empty ... !";
//         else
//         {
//             StNode *tempN = head;
//             T temp = head->fdata;
//             head = head->next;
//             delete tempN;
//             return temp;
//         }
//         return 0;
//     }
//     void fpush(T val)
//     {
//         StNode *node = new StNode(val);
//         node->next = head;
//         head = node;
//     }
//     void fdisplay()
//     {
//         StNode *temp = head;
//         cout << "List : ";
//         while (temp != NULL)
//         {
//             cout << temp->fdata << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };

// int main()
// {
//     int data;
//     int Fdata;
//     int choice;
//     cout << "1. char\n2. Float\nEnter choice: ";
//     cin >> choice;
//     switch (choice)
//     {
//         StackLL<float> L;
//         // StackLL<char> Lchar;
//     // case (1):
//     //     data = Lchar.fpop();
//     //     Lchar.fpush('c');
//     //     Lchar.fpush('s');
//     //     Lchar.fpush('q');
//     //     Lchar.fpush('w');
//     //     Lchar.fdisplay();
//     //     data = Lchar.fpop();
//     //     Lchar.fdisplay();
//     //     break;
//     case (2):
//         Fdata = L.fpop();
//         L.fpush(1);
//         L.fpush(2);
//         L.fpush(3);
//         L.fpush(4);
//         L.fdisplay();
//         Fdata = L.fpop();
//         L.fdisplay();
//         break;
//     default:
//         break;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    char VAL;
    Node *next;
    Node()
    {
        next = NULL;
        data = 0;
        VAL = '\0';
    }
    Node(int val, char c)
    {
        next = NULL;
        data = val;
        VAL = c;
    }
};
class LinkStack
{
    Node *head;

public:
    LinkStack()
    {
        head = NULL;
    }
    void push(int val, char c)
    {
        Node *newNode;
        newNode = new Node(val, c);
        newNode->next = head;
        head = newNode;
    }
    void pop()
    {
        if (head!=NULL)
        {
            Node *old = head;
            head = head->next;
            delete old;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " " << temp->VAL << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkStack S1;
    char val;
    float fval;
    char repeat;
    do
    {
        cout << "############## Menu #############";
        cout << "\n1. push\n2. pop\n";
        int choice;
        cin>>choice;
        if (choice == 1)
        {
            cout<<"Enter the char and float val to push: ";
            cin>>val>>fval;
            S1.push(fval,val);
            S1.display();
        }
        else if(choice == 2){
            S1.pop();
        }
        else {
            cout<<"Enter Valid option";
        }
        cout<<"Do you want to enter again(y/n): ";
        cin>>repeat;

    } while (repeat == 'y' || repeat=='Y');

    return 0;
}