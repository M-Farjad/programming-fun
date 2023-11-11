#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class linkedList
{
public:
    node *head;
    linkedList()
    {
        head = NULL;
    }

    void insertAtBegin()
    {
        int value;
        cout << "Enter the value you wanna enter at Head:";
        cin >> value;
        node *temp = new node(value);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insertInsertAtEnd()
    {
        int value;
        cout << "Enter the value you wanna enter at Tail:";
        cin >> value;
        node *iterator = head;
        node *temp = new node(value);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            while (iterator->next != NULL)
            {
                iterator = iterator->next;
            }
            iterator->next = temp;
        }
    }

    void update()
    {
        display();
        int value;
        cout << "Enter the value:";
        cin >> value;
        int key;
        cout << "Enter the value you want to update:";
        cin >> key;

        node *iterator = head;
        if (head->next == NULL)
        {
            if (head->data == key)
            {
                head->data = value;
            }
            else
            {
                cout << "\nValue not found!" << endl;
            }
        }
        else
        {
            while (iterator->next != NULL)
            {
                if (iterator->data == key)
                {
                    iterator->data = value;
                }
                iterator = iterator->next;
            }
            if (iterator->data == key)
            {
                iterator->data = value;
            }
        }
    }

    void deleteNode()
    {
        display();
        int value;
        cout << "Enter the value you wanna delete:";
        cin >> value;
        if (head == NULL)
        {
            return;
        }

        while (head != NULL && head->data == value)
        { // del at head
            node *del = head;
            head = head->next;
            delete del;
            if (head == NULL)
            {
                return;
            }
        }
        node *temp = head;

        while (temp != NULL)
        { // del after head
            if (temp->next != NULL && temp->next->data == value)
            {
                node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    void search()
    {
        int value;
        cout << "Enter the value you wanna search:";
        cin >> value;
        bool check = false;
        node *temp = head;
        if (head->next == NULL)
        {
            if (head->data == value)
            {
                check = true;
            }
            else
            {
                check = false;
            }
        }
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                check = true;
            }
            temp = temp->next;
        }
        if (check)
        {
            cout << "\nFound!\n";
        }
        else
        {
            cout << "\nNot found!\n";
        }
    }
    void insertAfter()
    {

        int key, // after key new value will be inserted
            val; // to hold the value of the new node

        cout << "Enter the key after that new node will be inserted: ";
        cin >> key;
        cout << "Enter the value of new node: ";
        cin >> val;

        node *iter = head;
        if (head == NULL)
        {
            cout << "No node exist will key " << key << endl;
            return;
        }
        while (iter != NULL)
        {
            if (iter->data == key)
            {
                node *newNode = new node(val);
                newNode->next = iter->next;
                iter->next = newNode;
            }
            iter = iter->next;
        }
    }
    void sort()
    {
        if (head == NULL)
        {
            return;
        }
        node *previous;
        node *curr;
        bool swapped = true;
        while (swapped)
        {
            previous = head;
            curr = previous->next;
            swapped = false;
            while (curr != NULL)
            {
                if (curr->data < previous->data)
                {
                    int temp = previous->data;
                    previous->data = curr->data;
                    curr->data = temp;
                    swapped = true;
                }
                curr = curr->next;
                previous = previous->next;
            }
        }
    }
    void menu()
    {
        int choice;
        do
        {
            cout << "what do you wanna do?\n";
            cout << " 0: insert an Head\n 1: insert an Tail\n 2: update Node\n 3: Delete Node \n 4: Display \n 5: search \n 6: Insert after \n 7: Sort \n 8: Exit \n\n";
            cout << "Enter Choice:";
            cin >> choice;

            switch (choice)
            {
            case 0:
                system("cls");
                insertAtBegin();
                break;
            case 1:
                system("cls");
                insertInsertAtEnd();
                break;
            case 2:
                system("cls");
                update();
                break;
            case 3:
                system("cls");
                deleteNode();
                break;
            case 4:
                system("cls");
                display();
                break;
            case 5:
                system("cls");
                search();
                break;
                //			case 6:
                //				display();
                //				sort();
                //				display();
                //				break;
            case 6:
                system("cls");
                insertAfter();
                display();
                break;
            case 7:
                system("cls");
                cout << "Previous list:\n";
                display();
                cout << "Sorted:\n";
                sort();
                display();
                break;
            case 8:
                exit(0);
                display();
                break;
            default:
                system("cls");
                cout << "invalid choice.";
                break;
            }
        } while (choice < 0 || choice > 8 || choice != 8);
    }
    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    linkedList list;

    list.menu();
    return 0;
}