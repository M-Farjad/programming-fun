#ifndef DAWN_H
#define DAWN_H

#include <iostream>
#include <conio.h>
using namespace std;

class DSA
{
    int *arr1;
    int size;

public:
    DSA();
    int getSize()
    {
        return size;
    }
    void setSize(int);
    void menu();
    void display();
    void insertVal();
    void updateVal();
    void removeVal();
    void searchVal();
    ~DSA();
};

void DSA::menu()
{
    display();
    cout << "1. Insert (head or tail)" << endl;
    cout << "2. Remove Element" << endl;
    cout << "3. Update Element" << endl;
    cout << "4. Search Element" << endl;
    cout << "0. Quit" << endl;
    cout << "Enter choice: ";
}
void DSA ::setSize(int sizePassed)
{
    size = sizePassed;
}
DSA::DSA()
{
    cout << "Enter the size of array: ";
    cin >> size;
    arr1 = new int[size];
    cout << "Fill the array and u will be rewarded\n";
    for (int i = 0; i < size; i++)
    {
        cout << "index[" << i << "] : ";
        cin >> *(arr1 + i);
    }
}

DSA::~DSA()
{
    delete[] arr1;
}
void DSA ::insertVal()
{
    size = size + 1;
    // arr1 = new int[size];
    int value;
    char choice;
    cout << "Enter the value to insert: ";
    while (!(cin >> value))
    {
        cout << "Enter valid Value: ";
        cin.clear();
        cin.ignore();
    }

    cout << "\nEnter the choice(h or t): ";
    while (!(cin >> choice) || !(choice == 'h' || choice == 't'))
    {
        cout << "Enter a valid value: ";
    }
    int *newArray = new int[size];
    if (choice == 'h')
    {
        *(newArray + 0) = value;
        for (int i = 1; i <= size; i++)
        {
            *(newArray + i) = *(arr1 + (i - 1));
        }
    }
    else if (choice == 't')
    {
        for (int i = 0; i <= size; i++)
        {
            *(newArray + i) = *(arr1 + (i));
        }
        cout << "Size: " << size << endl;
        *(newArray + size - 1) = value;
    }
    delete[] arr1;
    arr1 = newArray;
}
void DSA::updateVal()

{
    bool flag = false;
    int index;
    int element;
    int number;
    char choice;
    cout << "\n to update an Array\n by index or by element\n i for index\n e for element\n";
    while (!(cin >> choice) && (choice != 'i' || choice != 'e'))
    {
        cout << "Enter Valid: ";
    }

    if (choice == 'i')
    {
        do
        {
            cout << "Enter the Index: ";
            cin >> index;

        } while (index > size - 1 || index < 0);

        cout << "Enter new Value: ";
        cin >> number;
        arr1[index] = number;
    }
    else if (choice == 'e')
    {
        cout << "Enter the Value in Array u want to Update: ";
        cin >> element;

        cout << "Enter new Value: ";
        cin >> number;

        for (int i = 0; i < size; i++)
        {
            if (arr1[i] == element)

            {
                arr1[i] = number;
                flag = true; // if found
            }
        }
        if (flag)
        {
            cout << "element not found." << endl;
        }
    }
}
void DSA::removeVal()
{
    char choice;
    int index = -1;
    int value = 0;
    int no_of_index = 0;
    int *element_index = new int[size];

    cout << "To Remove Element : " << endl;
    cout << "1. By Index " << endl;
    cout << "2. By Element " << endl;
    cout << "0. Cancel " << endl;

    cout << "Option: ";
    choice = getche();
    cout << endl;

    while (choice < '0' || choice > '2')
    {
        cout << "Invalid Choice !" << endl;
        cout << "Option: ";
        choice = getche();
        cout << endl;
    }

    switch (choice)
    {
    case '0':
        break;
    case '1':

        cout << "Entered Index Must be between ( 0 - " << size - 1 << " ) : " << endl;
        cout << "Enter Index : ";
        cin >> index;

        while (index < 0 || index >= size)
        {
            cout << "Invalid Index Entered : ";
            cout << "Enter index again : ";
            cin >> index;
        }

        // Removing Element from the index
        for (int i = index; i < size - 1; i++)
        {
            *(arr1 + i) = *(arr1 + (i + 1));
        }
        size--;

        break;
    case '2':

        cout << "Enter Element Value : ";
        cin >> value;
        for (int i = 0; i < size; i++)
        {
            if (value == *(arr1 + i))
            {
                element_index[no_of_index] = i;
                no_of_index++;
            }
        }

        if (no_of_index)
        {
            int temp_size = size - no_of_index;
            int *temp_arr = new int[temp_size];
            int element_index_counter = 0;

            for (int i = 0; i < size; i++)
            {
                if (i == element_index[element_index_counter])
                {
                    element_index_counter++;
                }
                else
                {
                    temp_arr[i - element_index_counter] = arr1[i];
                }
            }
            cout << "Elements removed press any key to go back: ";
            getch();

            delete[] element_index;
            delete[] arr1;
            arr1 = temp_arr;
            size = temp_size;
        }
        else
        {
            cout << "The Array has no element having " << value << " value" << endl;
            getch();
        }
        break;

    default:
        break;
    }
}
void DSA::searchVal()
{

    char choice;
    int index = -1;
    int value = 0;
    int size_of_new_array = 0;
    int *foundElemntsArray = new int[size];

    cout << "Search Element using : " << endl;
    cout << "1. Index ( one value ) " << endl;
    cout << "2. Value    ( many ) " << endl;
    cout << "0. Cancel " << endl;

    cout << "Enter Your option: ";
    choice = getche();
    cout << endl;

    while (choice < '0' || choice > '2')
    {
        cout << "Invalid Option !" << endl;
        cout << "option: ";
        choice = getche();
        cout << endl;
    }

    switch (choice)
    {
    case '0':
        break;
    case '1':
        cout << "Entered Index Must be between ( 0 - " << size - 1 << " ) : " << endl;
        cout << "Enter Index : ";
        cin >> index;

        while (index < 0 || index >= size)
        {
            cout << "Invalid Index Entered : ";
            cout << "Re-enter Index : ";
            cin >> index;
        }

        cout << "At Index " << index << " Values is " << arr1[index] << endl;
        cout << "Press Any Key to Continue ";
        getch();
        break;
    case '2':
        cout << "Enter Value : ";
        cin >> value;
        for (int i = 0; i < size; i++)
        {
            if (value == arr1[i])
            {
                foundElemntsArray[size_of_new_array] = i;
                size_of_new_array++;
            }
        }

        if (size_of_new_array)
        {

            cout << "Total Elements Found : " << size_of_new_array << endl;
            cout << "and there indices are : ";
            for (int i = 0; i < size_of_new_array; i++)
            {
                cout << foundElemntsArray[i] << " ";
            }
            cout << endl;
            cout << "Press Any Key to Continue ";
            getch();
        }
        else
        {
            cout << "No Element Found in Array having " << value << " value" << endl;
            getch();
        }

        break;

    default:
        break;
    }
}
void DSA ::display()
{
    system("cls");
    cout << "########################################\n";
    cout << "Elements currently: ";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr1 + i) << " ";
    }
    cout << "\n########################################\n";
}

#endif