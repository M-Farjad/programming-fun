#include <iostream>
#include "heapSort.h"
using namespace std;


int main()
{
    heap obj;
    char repeat; // to repeat
    do
    {
        system("cls");
        obj.menu();
        int choice;
        cout << "Enter the choice(1-3): ";
        while (!(cin >> choice) || !(choice == 1 || choice == 2 || choice == 3))
        {
            cout << "\nEnter valid choice(1-3): ";
        }
        switch (choice)
        {
        case (1):
            obj.display();
            break;
        case (2):
            obj.heapSort();
            obj.writeToFile();
            break;
        case (3):
            obj.heapSort();
            obj.display();
            break;
        default:
            break;
        }
        cout << "Enter (y/Y to repeat): ";
        cin>>repeat;
    } while ((repeat == 'y' || repeat == 'Y'));
}