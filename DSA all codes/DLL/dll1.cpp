#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next, *prev;

public:
    Node()
    {
        next = prev = NULL;
    }
    friend class DLL_lab;
};
class DLL_lab
{
    Node *head, *tail;
    int length = 0;
public:
    DLL_lab()
    {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    bool isEmpty()
    {
        return (head->next == tail);
    }
    void insertHead(int val)
    {
        Node *node = new Node();
        node->data = val;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        length++;
    }
    void insertTail(int val)
    {
        Node *node = new Node();
        node->data = val;
        node->prev= tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        node->next= tail;
        length++;
    }
    void insertAfter(int prvVal,int newVal)
    {
        if (isEmpty())
        {
            cout << "List is empty...!\n";
            insertHead(newVal);
        }
        else
        {
            Node *node = new Node();
            Node *temp = head;
            node->data=newVal;
            while (temp->data != prvVal && temp->next != NULL)
            {
                temp = temp->next;
            }
            if (temp->next == NULL)
            {
                insertHead(newVal);
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
    void display()
    {
        Node *temp = head->next;
        while (temp != tail)
        {
            if (temp->prev == head)
            {
                cout << "NULL->";
            }
            cout << temp->data << "->";
            temp = temp->next;
            if (temp->next == NULL)
            {
                cout << "NULL";
            }
        }
        cout << endl;
    }
    void displayRev()
    {
        Node *temp = tail->prev;
        while (temp != head)
        {
            if (temp->next == tail)
            {
                cout << "NULL->";
            }
            cout << temp->data << "->";
            temp = temp->prev;
            if (temp->prev == NULL)
            {
                cout << "NULL";
            }
        }
        cout << endl;
    }
    ~DLL_lab()
    {
        Node *temp = head;
        while (temp != tail)
        {
            temp = head->next;
            cout<<"Heee";
            delete temp;
        }
        delete head;
        delete tail;
    }
};

int main()
{
    DLL_lab list;
    list.insertHead(10);
    list.insertHead(20);
    list.insertHead(30);
    list.insertHead(40);
    list.display();

    list.insertTail(50);
    list.insertTail(70);
    list.insertTail(80);
    list.display();
    list.displayRev();
    return 0;
}