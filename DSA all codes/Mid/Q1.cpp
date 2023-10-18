#include <iostream>
using namespace std;

class Node
{
    int data;

public:
    Node *next;
    Node(int d = 0, Node *n = nullptr)
    {
        data = d;
        next = n;
    }
    void setData(int d)
    {
        data = d;
    }
    int getData()
    {
        return data;
    }
    void setNext(Node *n = nullptr)
    {
        next = n;
    }
    Node *getNext()
    {
        return next;
    }
};
class SinglyLinkedList
{
    Node *tail;
    int length = 0;

public:
    Node *head;
    SinglyLinkedList(Node *h = nullptr, Node *t = nullptr)
    {
        head = h;
        tail = t;
        length = 0;
    }
    // SinglyLinkedList()
    // {
    // 	head = tail = NULL;
    // }
    int getLength()
    {
        return length;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    // void InsertInAscendingOrder(int value)
    // {
    //     if (head == NULL)
    //     {
    //         insertAtEnd(value);
    //         return;
    //     }
    //     if (head->getData() > value)
    //     {
    //         Node *newNode = new Node(value);
    //         newNode->setNext(head);
    //         head = newNode;
    //         return;
    //     }
    //     Node *temp = head;
    //     while (temp->getNext() != NULL && temp->getNext()->getData() < value)
    //     {
    //         temp = temp->getNext();
    //     }
    //     Node *newNode = new Node(value);
    //     newNode->setNext(temp->getNext());
    //     temp->setNext(newNode);
    // }
    void insertInAscOrder(Node *&head, int value)
    {
        if (!head)
        {
            Node *newNode = new Node(value);
            head = newNode;
            return;
        }
        else if (head->getData() > value)
        {
            Node *newNode = new Node(value);
            newNode->setNext(head);
            head = newNode;
            return;
        }
        if (!head->getNext())
        {
            Node *newNode = new Node(value);
            head->setNext(newNode);
            return;
        }
        insertInAscOrder(head->next, value);
    }
    void insertAtStart(int val)
    {
        Node *newNode = new Node(val);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            newNode->setNext(head);
            head = newNode;
        }
        length++;
    }
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (IsEmpty())
            head = tail = newNode;
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
        length++;
    }

    void display()
    {
        Node *temp = head;
        if (IsEmpty())
            cout << "Your list is empty";
        else
        {
            while (temp != nullptr)
            {
                cout << temp->getData() << "  ";
                temp = temp->getNext();
            }
        }
    }
    ~SinglyLinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            head = head->getNext();
            delete temp;
            temp = head;
        }
        temp = nullptr;
    }
    void findMedian()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node *x = head;
        Node *y = head;
        while (y->next != NULL && y->next->next != NULL)
        {
            x = x->next;
            y = y->next->next;
        }
        if (y->next == NULL)
        {
            cout << "Median value is " << x->getData() << endl;
        }
        else
        {
            cout << "Median value is " << (x->getData() + x->next->getData()) / 2.0 << endl;
        }
    }
};

int main()
{
    SinglyLinkedList list;
    list.insertInAscOrder(list.head, 67);
    list.insertInAscOrder(list.head, 90);
    list.insertInAscOrder(list.head, 43);
    list.findMedian();
    list.display();
}