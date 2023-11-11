#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* getNext()
    {
        return next;
    }
    int getData()
    {
        return data;
    }
    void setNext(Node* node)
    {
        next = node;
    }
    Node(int val = 0) : data(val) {}
};
class linkedList
{
    Node* head, * tail;

public:
    linkedList() : head(), tail() {}
    bool IsEmpty()
    {
        return (head == NULL);
    }
    void insert(int val)
    {
        Node* newNode = new Node(val);
        if (IsEmpty())
            head = tail = newNode;
        else
        {
            tail->setNext(newNode);
            tail = newNode;
        }
    }
    // void deleteAtHead(){
    //     if(!head)
    //         cout<<"Already Empty ... !";
    //     else{
    //         Node* del
    //     }
        
    // }
    void display()
    {
        Node* temp = head;
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
};
int main()
{
    Node obj;
    
    linkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.display();
    return 0;
}