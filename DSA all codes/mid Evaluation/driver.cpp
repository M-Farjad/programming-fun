#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node *next;

public:
    Node(T data = 0)
    {
        this->data = data;
        next = NULL;
    }
    friend class StackGarage;
};
// template <typename T>
class StackGarage
{
    Node<int> *head;
    Node<int> *tail;
    int length;

public:
    StackGarage()
    {
        head = tail = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(int truck_id)
    {
        Node<int>* node = new Node(truck_id);
        if (isEmpty())
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        length++;
    }
    int pop()
    {
        if (isEmpty())
            cout << "Already empty ... !";
        else
        {
            Node<int>* temp = head;
            head = head->next;
            return temp->data;
        length--;
        }
        return 0;
    }
    void show_truck()
    {
        Node<int>* temp = head;
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    StackGarage g;
    g.push(10);
    g.push(20);
    g.push(30);
    g.show_truck();
    int data = g.pop();
    data = g.pop();
    g.show_truck();
    return 0;
}