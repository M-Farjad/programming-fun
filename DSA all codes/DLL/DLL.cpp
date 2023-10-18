#include <iostream>
using namespace std;
class dNode
{
public:
    int data;
    dNode *prev;
    dNode *next;
    dNode()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
    dNode(int value)
    {
        this->data = value;
        prev = NULL;
        next = NULL;
    }
};
class DLL
{
public:
    DLL()
    {
        head = NULL;
    }
    bool Empty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertAtHead(dNode *newNode)
    {
        if (Empty())
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(dNode *newNode)
    {
        if (Empty())
        {
            head = newNode;
        }
        else
        {
            dNode *rptr;
            rptr = head;
            while (rptr->next != NULL)
            {
                rptr = rptr->next;
            }
            rptr->next = newNode;
            newNode->prev = rptr;
        }
    }
    void insertAtAnyPosition(dNode *newNode, int pos)
    {
        if (Empty())
        {
            head = newNode;
        }
        else
        {
            dNode *rptr;
            rptr = head;
            for (int i = 0; i < (pos - 1); i++)
            {
                rptr = rptr->next;
            }
            newNode->prev = rptr;
            newNode->next = rptr->next;
            rptr->next->prev = newNode;
            rptr->next = newNode;
        }
    }
    void deleteAtHead()
    {
        dNode *temp;
        temp = head;
        head = head->next;
        head->prev = NULL;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void deleteAtTail()
    {
        dNode *temp;
        dNode *rptr;
        rptr = head;
        while (rptr->next->next != NULL)
        {
            rptr = rptr->next;
        }
        temp = rptr->next;
        rptr->next = NULL;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void deleteAtAnyPosition(int pos)
    {
        dNode *rptr;
        dNode *temp;
        rptr = head;
        for (int i = 0; i < (pos - 2); i++)
        {
            rptr = rptr->next;
        }
        temp = rptr->next;
        rptr->next->prev = rptr;
        rptr->next = rptr->next->next;
        temp->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    void search(int value)
    {
        int count = 0;
        dNode *rptr;
        rptr = head;
        if (rptr == NULL)
        {
            cout << "\nEmpty List.\n";
        }
        while (rptr != NULL)
        {
            if (rptr->data == value)
            {
                cout << "The value is at position " << (count + 1) << endl;
            }
            count++;
            rptr = rptr->next;
        }
    }
    void update(int initial, int final)
    {
        int count = 0;
        dNode *rptr;
        rptr = head;
        if (rptr == NULL)
        {
            cout << "\nEmpty List.\n";
        }
        while (rptr != NULL)
        {
            if (rptr->data == initial)
            {
                rptr->data = final;
            }
            count++;
            rptr = rptr->next;
        }
    }
    void display()
    {
        dNode *rptr;
        rptr = head;
        while (rptr != NULL)
        {
            cout << rptr->data << " ";
            rptr = rptr->next;
        }
    }

private:
    dNode *head;
};
int main()
{
    DLL wow;
    cout << "List Created.\n";
    wow.insertAtHead(new dNode(2));
    wow.insertAtTail(new dNode(10));
    wow.insertAtTail(new dNode(2));
    wow.insertAtTail(new dNode(5));
    wow.insertAtTail(new dNode(7));
    wow.insertAtTail(new dNode(4));
    wow.insertAtHead(new dNode(1));
    wow.insertAtAnyPosition(new dNode(3), 2);
    wow.display();
    cout << "\n\n";
    cout << "Delete at the start.\n";
    wow.deleteAtHead();
    wow.display();
    cout << "\n\n";
    cout << "Delete at the end.\n";
    wow.deleteAtTail();
    wow.display();
    cout << "\n\n";
    cout << "Delete at any position.\n";
    wow.deleteAtAnyPosition(3);
    wow.display();
    cout << "\n\n";
    cout << "Searching.\n";
    wow.search(5);
    wow.display();
    cout << "\n\n";
    cout << "Updation.\n";
    wow.update(5, 9);
    wow.display();
    cout << "\n\n";
}