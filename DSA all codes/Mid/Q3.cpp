#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d = -1)
    {
        data = d;
        next = NULL;
    }
};
class QueueLL
{
    Node *head, *tail;
    int length;
    bool isEmpty()
    {
        return (head == NULL);
    }

public:
    QueueLL()
    {
        head = tail = NULL;
        length = 0;
    }
    void enQueueLL(int);
    int deQueueLL();
    void display();
    int getlength();
    void EnqueueInAscendingOrder(int value)
    {
        if (head == NULL)
        {
            enQueueLL(value);
            return;
        }
        if (head->data > value)
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
};
int QueueLL::deQueueLL()
{
    if (isEmpty())
    {
        cout << "Empty QueueLL ... !";
    }
    else
    {
        Node *temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        length--;
        return data;
    }
    return -1;
}
void QueueLL::enQueueLL(int val)
{
    Node *node = new Node(val);
    if (!isEmpty())
    {
        tail->next = node;
        tail = node;
    }
    else
    {
        head = tail = node;
    }
    length++;
}
void QueueLL::display()
{
    Node *temp = head;
    cout << endl;
    for (; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << "NULL\nLength: " << length;
    cout << endl;
}

int main()
{
    QueueLL qll;
    int data;
    qll.display();
    data = qll.deQueueLL();
    qll.display();
    if (data != (-1))
        cout << "Your deque is: " << data << endl;
    else
        cout << "no dequeue\n";
    qll.enQueueLL(2);
    qll.enQueueLL(4);
    qll.enQueueLL(3);
    qll.display();
    qll.deQueueLL();
    qll.display();
    qll.enQueueLL(5);
    qll.display();
    qll.EnqueueInAscendingOrder(4);
    qll.display();
    return 0;
}