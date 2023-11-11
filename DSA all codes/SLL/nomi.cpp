#include <iostream>
using namespace std;
class Node
{
public:
    Node* next;
    int data;
    // Node* prev;
    Node(int value = 0)
    {
        data = value;
        next = NULL;
        // prev=NULL;
    }
};
class link
{
    Node* head, * last;
    int length;
public:
    link()
    {
        head = last = NULL;
        int length = 0;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    //################## insert Front #####################
    void addFront(int val)
    {
        Node* node = new Node(val);
        if (isEmpty())
        {
            head = node;
            last = node;
        }
        else
        {
            node->next = head;
            head = node;
        }
        length++;
    }

    //################## ascending sort #####################
    void ascSortList()
    {
        Node* i, * j; int temp;
        for (i = head; i->next != NULL; i = i->next)
        {
            for (j = i->next; j != NULL; j = j->next)
            {
                if (i->data > j->data)
                {
                    temp = i->data;
                    i->data = j->data;
                    j->data = temp;
                }
            }

        }
    }
    //######### Display ##########
    void display()
    {
        Node* temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "NULL";
        }
        cout << "\n";
        delete temp;
    }
    void insertSorted(int val) {
        Node* node = new Node(val);
        Node* i = head, * j = head->next;
        if (isEmpty()) {
            node->next = head;
            head = node;
        }
        else if ((head->data) > (node->data))
        {
            node->next = head;
            head = node;
            cout << "Hello";
        }
        else
        {

            while (j->next != NULL && (node->data > i->data)) {
                i = j;
                j = j->next;
            }
            node->next = i->next;
            i->next = node;
            cout << "Hello!";
        }
        length++;
    }
    void append(int num) {

        if (num > length) {
            cout << "\nnot possible";
            return;
        }


        Node* temp = head;
        Node* thead = NULL;
        Node* tTail = NULL;



        for (int i = 1; i < (length - num - 1); i++) {
            temp = temp->next;
        }

        tTail = temp;
        thead = temp->next;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = head;

        head = thead;

        tTail->next = NULL;

    }
};
int main()
{
    link L;
    L.addFront(3);
    L.addFront(7);
    L.addFront(6);
    L.addFront(5);
    L.display();
    L.ascSortList();
    L.display();
    L.insertSorted(4);
    L.display();

    L.append(2);
    L.display();
    return 0;
}