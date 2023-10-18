#include <iostream>
#define MAX_SIZE 5
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

class QueueArray
{
private:
    int myQueueArray[MAX_SIZE];
    int front, rear, noElements;

public:
    QueueArray();
    bool isFull();
    void enQueueArray(int);
    int deQueueArray();
    bool isEmpty();
    void display();
};
bool QueueArray::isFull()
{
    return noElements == MAX_SIZE;
}
bool QueueArray::isEmpty()
{
    return noElements == 0;
}
void QueueArray::enQueueArray(int x)
{
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    myQueueArray[rear] = x;
    noElements++;
}
int QueueArray::deQueueArray()
{
    int x = myQueueArray[front];
    front = (front + 1) % MAX_SIZE;
    noElements--;
    return x;
}
QueueArray::QueueArray()
{
    front = rear = -1;
    noElements = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        myQueueArray[i] = -1;
    }
}
void QueueArray::display()
{
    if (isEmpty())
    {
        cout << "Empty QueueArray ... !\n";
    }
    else
    {
        cout << "\nElements in QueueArray: ";
        for (int i = 0; i < noElements; i++)
        {
            if (myQueueArray[front + i] == -1)
                continue;
            cout << myQueueArray[front + i] << " ";
        }
    }
}

int main()
{
    char repeat;
    do
    {
        char choice;
        int data;
        cout << "Enter the choice\n(a/A for array) or (l/L for linked list):";
        while (!(cin >> choice) && choice != 'a' || choice != 'A' || choice != 'l' || choice != 'L')
        {
            cout << "Enter valid(a/A for array) or (l/L for linked list): ";
            cin.clear();
        }

        switch (choice)
        {
        case 'A':
        case 'a':
            QueueArray q;
            q.display();
            q.enQueueArray(10);
            q.display();
            q.enQueueArray(7);
            q.display();
            q.enQueueArray(5);
            q.display();
            q.enQueueArray(6);
            q.display();

            // Dequeue
            data = q.deQueueArray();
            q.display();
            cout << "data: " << data;
            q.enQueueArray(9);
            q.display();
            break;
        case 'l':
        case 'L':
            QueueLL qll;
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
            break;
        }
        cout << "do you want to check again (y/n): ";
        cin >> repeat;
        // return 0;
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}