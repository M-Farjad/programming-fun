#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
using namespace std;

class List
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    List();
    bool isEmpty();
    void sort();
    void display();
    void insertHead(int d);
    void insertTail(int d);
    void InserSort(int val);
    void Append(int num);
};

List::List()
{
    head = new Node;
    tail = head;
    size = 0;
}
bool List::isEmpty()
{
    return (head == tail);
}
void List::display()
{
    Node *temp = head->next;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
void List::sort()
{
    if (isEmpty())
    {
        cout << " List is Empty" << endl;
    }
    else
    {
        Node *min = NULL; // will store address of a node to swap value with 
        for (Node *outer = head->next; outer != NULL; outer = outer->next)
        {
            min = outer;
            for (Node *inner = outer->next; inner != NULL; inner = inner->next)
            {
                if (inner->data < min->data)
                {
                    min = inner;
                }
            }
            //Swaping Data
            int temp = min->data;
            min->data = outer->data;
            outer->data = temp;
        }
    }
}
void List::insertHead(int d)
{
    Node *node = new Node();
    node->data = d;
    node->next = head->next;
    head->next = node;
    if (isEmpty())
    {
        tail = node;
    }
    size++;
}
void List::insertTail(int d)
{
    Node *node = new Node();
    node->data = d;
    tail->next = node;
    tail = node;
    size++;
}

void List::InserSort(int val)
{
    sort(); // needed if list is not sort

    bool found = false;
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data >= val)
        {
            found = true;
            Node *node = new Node;
            node->data = val;
            node->next = temp->next;
            temp->next = node;
            break;
        }
        temp = temp->next;
    }
    if (!found)
    {
        insertTail(val);
    }
    size++;
}

void List::Append(int num)
{
    if (size <= num)
    {
        cout << " Number of Nodes in List is Less then the Entered Number" << endl;
    }
    else
    {
        Node *temp = head->next;
        int count = 1;
        while (count < num && temp != NULL)
        {
            temp = temp->next;
            count++;
        }

        // COde for Shipting First N nodes to the tail;
        tail->next = head->next;
        head->next = temp->next;
        temp->next = NULL;
        tail = temp;
    }
}

#endif