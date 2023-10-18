#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    // Node* prev;
    Node(int value) : data(value)
    {
        next = NULL;
        // prev=NULL;
    }
};
class link
{
public:
    Node *head, *last;
    link()
    {
        head = last = nullptr;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    //####### Menu #######
    void menu()
    {
        display();
        cout << "1. Enter (1) for Search\n";
        cout << "1. Enter (2) for Insert at tail\n";
        cout << "1. Enter (3) for Finding Greatest Value\n";
        cout << "1. Enter (4) for display in reverse order\n";
    }
    //################## insert Rear Normal #####################
    void addRear(int val)
    {
        Node *node = new Node(val);
        if (isEmpty())
        {
            head = node;
            last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
    }
    //################## insert Front #####################
    void addFront(int val)
    {
        Node *node = new Node(val);
        // if (isEmpty())
        // {
        //     head = node;
        //     last = node;
        // }
        // else
        // {
        node->next = head;
        head = node;
        // }
    }
    //########## Search #############
    void search(int value)
    {
        int count = 0;
        Node *runner_ptr;
        runner_ptr = head;
        if (runner_ptr == NULL)
        {
            cout << "\nEmpty List.\n";
        }
        cout << "The value is at position ";
        while (runner_ptr != NULL)
        {
            if (runner_ptr->data == value)
            {
                cout << " -> " << (count + 1) << " ";
            }
            count++;
            runner_ptr = runner_ptr->next;
        }
        cout << "\n";
    }
    //############# Recursive Search ################
    bool RecursiveSearch(Node *head, int val)
    {
        if (head->data == val)
            return true;
        else if (head->next == NULL)
            return false;
        else
            return RecursiveSearch(head->next, val);
    }
    //######### Recursive print Reverse #########
    void printReverse(Node *head)
    {
        if (head == NULL)
            return;
        printReverse(head->next);
        cout << head->data << " ";
    }
    //######### Insert at tail Recursive ##########
    void insertTailRecursive(Node *currentNode, int val)
    {
        if (currentNode->next == NULL)
        {
            Node *node = new Node(val);
            currentNode->next = node;
        }
        else
            insertTailRecursive(currentNode->next, val);
    }
    //######### Greatest Value Recursive ##########

    int findGreatest(Node *currentNode)
    {
        static int currentHighest = 0;
        if (currentNode == NULL)
            return currentHighest;
        else
        {
            if (currentHighest < currentNode->data)
                currentHighest = currentNode->data;
            return findGreatest(currentNode->next);
        }
        return currentHighest;
    }
    //######### Display ##########
    void display()
    {
        Node *temp;
        temp = head;
        cout << "List: ";
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "NULL";
        }
        cout << "\n";
        delete temp;
    }
    //######### Destructor ############
    ~link()
    {
        delete head;
    }
};
int main()
{
    link L;
    int data;
    char repeat;
    L.addRear(1);
    L.addRear(2);
    L.addFront(7);
    L.search(10);
    L.display();
    do
    {
        L.menu();
        char choice;
        int data;
        cout << "Enter the choice\n(1-4):";
        while (!(cin >> choice) && (choice != '1' || choice != '2' || choice != '3' || choice != '4'))
        {
            cout << "Enter valid(1-4): ";
            cin.clear();
        }
        switch (choice)
        {
        case '1':
            cout<<"Enter value to search: ";
            cin>>data;
            if (L.RecursiveSearch(L.head, data))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;
        case '2':
            cout<<"Enter value to insert: ";
            cin>>data;
            L.insertTailRecursive(L.head, data);
            L.display();
            break;
        case '3':
            cout << "Greatest: " << L.findGreatest(L.head)<<endl;
            break;
        case '4':
            L.printReverse(L.head);
            cout << "\n";
            break;
        }
        cout << "do you want to check again (y/n): ";
        cin >> repeat;
        system("CLS");
    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}
