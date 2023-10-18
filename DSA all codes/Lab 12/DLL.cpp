#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
class doublyLinkedList
{
public:
    Node* head;
    static int length;
    doublyLinkedList()
    {
        head = NULL;
    }
    bool isEmpty()
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

    void insertAtHead(int value)
    {
        Node* newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            length++;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            length++;
        }
    }
    void deleteAtHead()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            // 1-2-3
            Node* temp = head;
            head = head->next;
            if (head->next != NULL)
            {
                head->prev = NULL;
            }
            delete temp;
            length--;
        }
    }
    void display()
    {
        Node* temp = head;
        cout << "NULL->";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int getLength() {
        return length;
    }
};

int doublyLinkedList::length = 0;

int main()
{
    doublyLinkedList L1;
    L1.insertAtHead(10);
    L1.insertAtHead(20);
    L1.insertAtHead(30);
    L1.deleteAtHead();
    L1.display();
    return 0;
}