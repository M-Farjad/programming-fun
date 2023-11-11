#include <iostream>
#include "DSA.h"
using namespace std;

int main()
{

    DSA obj;
    int choice;
    char repeat;
    bool flag = true;
    do
    {
        obj.menu();
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Wanna do it again (y/n): ";
            while (!(cin >> repeat) && (repeat != 'y' || repeat != 'Y' || repeat != 'n' || repeat != 'N'))
            {
                cout << "Invalid enter again: ";
            }

            if (repeat == 'y' || repeat == 'Y')
                flag = true;
            else if (repeat == 'n' || repeat == 'N')
            {
                flag = false;
            }

            break;
        }
        case 1:
        {
            obj.insertVal();
            obj.display();
            break;
        }
        case 2:
        {
            obj.removeVal();
            obj.display();
            break;
        }
        case 3:
        {
            obj.updateVal();
            obj.display();
            break;
        }
        case 4:
        {
            obj.searchVal();
            obj.display();
            break;
        }
        }

    } while (flag == true);

    return 0;
}