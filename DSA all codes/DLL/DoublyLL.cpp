#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val = 0)
    {
        data = val;
        next = prev = NULL;
    }
};
class DLL
{
    Node *head, *tail;
    int length = 0;

public:
    DLL()
    {
        head = tail = NULL;
    }

    bool isEmpty() { return (head == NULL); }
    void inserthead(int val)
    {
        Node *node = new Node(val);
        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            node->next = head;
            head->prev=node;
            head = node;
        }
        length++;
    }
    void insertTail(int val)
    {
        Node *node = new Node(val);
        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        length++;
    }
    void insertAfter(int newVal, int prvVal)
    {
        if (isEmpty())
        {
            cout << "List is empty...!\n";
            inserthead(newVal);
        }
        else
        {
            Node *node = new Node(newVal);
            Node *temp = head;
            while (temp->data != prvVal && temp->next != NULL)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                inserthead(newVal);
                cout << "No Matching Found inserting at head\n";
            }
            else
            {
                
                node->next = temp->next;
                node->prev = temp;
                temp->next = node;
            }
        }
        length++;
    }
    void delAtBeginning()
    {
        if (head == NULL)
            cout << "Already Empty\n";
        else
        {
            Node *ptr = head;
            head->next->prev = NULL;
            head = head->next;
            delete ptr;
            ptr = nullptr;
        }
        length--;
    }
    void delAtIndex(int Index)
    {
        int count = 0;
        if (Index < 0)
        {
            cout << "Index Out of bound ... !\n";
        }
        if (Index == 0)
        {
            if (head->next == NULL)
            {
                Node *ptr = head;
                head = NULL;
                delete ptr;
            }
            else
            {
                Node *ptr = head;
                head = head->next;
                head->next->prev = NULL;
                delete ptr;
            }
        }
        else
        {
            if (isEmpty())
            {
                cout << "Already Empty\n";
            }

            else
            {
                Node *p = head;
                while (count < Index - 1)
                {
                    p = p->next;
                    count++;
                    if (p->next == NULL)
                    {
                        cout << "Index Out of bound ... !\n";
                        return;
                    }
                }
                Node *q = p->next;
                p->next = q->next;
                q->next->prev = p;
                delete q;
                q = NULL;
                // cout<<p->next;
            }
        }
        length--;
    }
    
    void displayReversed(){
        Node *temp;
        temp = tail;
        cout<<"NULL ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        if (temp == NULL)
        {
            cout << "NULL";
        }
        cout << "\n";
        delete temp;
    }
    void displayNormal()
    {
        Node *temp;
        temp = head;
        if (temp->prev==NULL)
        {
            cout<<"NULL ";
        }
        
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "NULL";
        }
        cout << "\n";
        delete temp;
    }
    int getLength(){
        return length;
    }
    ~DLL()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main()
{
    DLL list;
    list.inserthead(10);
    list.insertTail(30);
    list.inserthead(50);
    list.insertAfter(70, 50);
    list.insertTail(40);
    list.displayNormal();
    list.displayReversed();
    list.delAtBeginning();
    list.displayNormal();
    list.delAtIndex(0);
    list.displayNormal();
    list.displayReversed();
    return 0;
}