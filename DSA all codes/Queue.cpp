// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int d = 0)
//     {
//         data = d;
//         next = NULL;
//     }
// };
// class Queue
// {
//     Node *head, *tail;
//     int length;

// public:
//     Queue()
//     {
//         head = tail = NULL;
//         length = 0;
//     }
//     void enqueue(int val);
//     void dequeue();
//     void display();
//     int getlength();
// };

#include <iostream>
using namespace std;

#define MAX_SIZE 5
class Queue
{
private:
    int myqueue[MAX_SIZE];
    int front, rear, noElements;

public:
    Queue();
    bool isFull();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void display();
    void ascendingSortInsert(int);
};

bool Queue::isFull()
{
    return noElements == MAX_SIZE;
}
bool Queue::isEmpty()
{
    return noElements == 0;
}
void Queue::enqueue(int x)
{
    if (front == -1)
        front = 0;
    rear = (rear + 1) % MAX_SIZE;
    myqueue[rear] = x;
    noElements++;
}
int Queue::dequeue()
{
    int x = myqueue[front];
    front = (front + 1) % MAX_SIZE;
    noElements--;
    return x;
}
Queue::Queue()
{
    front = rear = -1;
    noElements = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        myqueue[i] = -1;
    }
}
void Queue::display()
{
    if (isEmpty())
    {
        cout << "Empty Queue ... !\n";
    }
    else
    {
        cout << "\nElements in Queue: ";
        for (int i = 0; i < noElements; i++)
        {
            if (myqueue[front + i] == -1)
                continue;
            cout << myqueue[front + i] << " ";
        }
    }
}

int main()
{
    Queue q;
    q.display();
    q.enqueue(10);
    q.display();
    q.enqueue(7);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(6);
    q.display();

    // Dequeue
    int data = q.dequeue();
    q.display();
    cout << "data: " << data;
    q.enqueue(9);
    q.display();
    return 0;
}









// /*Developed by Alina Munir*/

// #include <iostream>
// //#include "Lab6Queue_LL.h"
// using namespace std;

// // Array based Queue Class
// class queue {
//     int front;
//     int rear;
//     int capacity;
//     int* q;

// public:
//     queue(int val);
//     void enqueue(int size);
//     void dequeue();
//     void display();
//     bool isFull();
//     bool isEmpty();
// };

// // struct node, by default all parameters are public in struct
// struct Node {
//     int data;
//     Node* next;
//     Node(int val);
// };

// // Linked List based Queue
// class queueLL {
//     Node* front;
//     Node* rear;

// public:
//     queueLL();
//     void enqueue(int val);
//     void dequeue();
//     void display();
//     bool isEmpty();
// };


// // array based queue class implemetation
// // Default constructor
// queue::queue(int size) {
//     front = 0;
//     rear = 0;
//     capacity = size;
//     q = new int[size];
// }

// bool queue::isEmpty() {
//     if (front == rear) {
//         return true;
//     }
//     return false;
// }

// bool queue::isFull() {
//     if (capacity == rear) {
//         return true;
//     }
//     return false;
// }

// void queue::enqueue(int val) {
//     if (isFull()) {
//         cout << "Value not enqueued. Queue is Full" << endl;
//     }
//     else {
//         q[rear] = val;
//         rear++;
//     }
// }

// void queue::dequeue() {
//     if (isEmpty()) {
//         cout << "Value not dequeued. Queue is Empty" << endl;
//     }
//     else {
//         for (int i = 0; i < rear - 1; i++) {
//             q[i] = q[i + 1];
//         }
//         rear--;
//     }
// }

// void queue::display() {
//     if (isEmpty()) {
//         cout << "Queue is Empty" << endl;
//     }
//     else{
//         cout << "DISPLAY QUEUE" << endl;
//         for (int i = 0; i < rear; i++) {
//             cout << q[i] << endl;
//         }
//     }    
// }


// // Node struct implementation
// Node::Node(int val) {
//     data = val;
//     next = NULL;
// }


// // Linked List based Queue implementation
// queueLL::queueLL() {
//     front = NULL;
//     rear = NULL;
// }

// bool queueLL::isEmpty() {
//     if (front == NULL) {
//         return true;
//     }
//     return false;
// }

// void queueLL::enqueue(int val) {
//     Node* temp = new Node(val);

//     if (isEmpty()) {
//         front = temp;
//         rear = temp;
//     }
//     else {
//         rear->next = temp;
//         rear = temp;
//     }
// }

// void queueLL::dequeue() {
//     if (isEmpty()) {
//         cout << "Value not dequeued. Queue is Empty" << endl;
//     }
//     else {
//         front = front->next;
//     }
// }

// void queueLL::display() {
//     if (isEmpty()) {
//         cout << "Queue is Empty" << endl;
//     }
//     else {
//         Node* temp = front;
//         cout << "DISPLAY QUEUE" << endl;
//         while (temp != NULL) {
//             cout << temp->data << endl;
//             temp = temp->next;
//         }
//     }
// }

// int main()
// {
//     // Displaying menu is recommended.
//     // object for linked list
//     queueLL q;
//     cout << "Linked list Based Queue" << endl;
//     q.display();
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.enqueue(50);
//     q.enqueue(60);
//     //cout << "is Empty: " << q.isEmpty() << endl;

//     q.display();
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();
//     q.dequeue();
//     q.display();
//     q.dequeue();
//     q.dequeue();
//     q.display();

//     // object for array based list
//     cout << "Array Based Queue" << endl;
//     queue qA(5); // make a queue with size 5, the size here can be change just by updating 
//                  // parameter. The size is not fixed in code implementation therefore the size 
//                 // of array based queue is dynamic.
//     qA.enqueue(2);
//     qA.enqueue(3);
//     qA.enqueue(4);
//     qA.enqueue(5);
//     qA.enqueue(6);
//     qA.display();

//     qA.dequeue();
//     qA.dequeue();
//     qA.dequeue();
//     qA.dequeue();
//     qA.dequeue();
//     qA.display();
//     qA.dequeue();
//     qA.dequeue();
//     qA.display();

// }