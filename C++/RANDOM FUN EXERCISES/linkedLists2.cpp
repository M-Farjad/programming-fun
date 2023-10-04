#include <iostream>
#include <conio.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void display(node *, node *);
int main()
{
    node *head, *newnode, *temp;
    head = nullptr;
    int choice;
    while (choice)
    {
        newnode = (node *)malloc(sizeof(node));
        cout << "enter the value: ";
        cin >> newnode->data;
        newnode->next = 0;
        if (head == 0)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        cout << "\nDo you want to continue entering data(0,1)? ";
        cin >> choice;
    }
    display(temp, head);
    getch();
    return 0;
}
void display(node *temp, node *head)
{
    // Now displaying the data
    temp = head;
    while (temp != 0)
    {
        cout << temp->data;
        temp = temp->next;
    }
}