#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include<conio.h>
using namespace std;

class IntArray
{
private:
    int *arr;
    int size;

    void initialize_array();

public:
    IntArray();
    IntArray(int *second_array, int size);

    void insert(bool inser_at_first);
    void remove();
    void display();
    void update();
    void search();
    bool back(int);
    bool front(int);
    void index_at();
};

// Constructors
IntArray::IntArray()
{
    initialize_array();
}
IntArray::IntArray(int *sec_arr, int size)
{
    if (size > 0)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = sec_arr[i];
        }
    }
    else
    {
        char choice;
        cout << "Invalid Size Of Array !" << endl;

        do
        {
            cout << "DO you Want to Make & Intilize array on your own ? (Y/N) ";
            choice = getche();
            cout << endl;
        } while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'));

        if (choice == 'y' || choice == 'Y')
        {
            cout << "Calling Int Array Construcotr " << endl;
            initialize_array();
        }
    }
}
// Member Functions
void IntArray::insert(bool insert_at_first)
{
    int value;
    if (insert_at_first)
    {
        // Insert Array at First
        cout << "Enter Value to add in array : " << endl;
        cin >> value;

        // making temp_array & filling it
        int *temp_arr = new int[size + 1];
        temp_arr[0] = value;
        for (int i = 0; i < size; i++)
        {
            temp_arr[i + 1] = arr[i];
        }

        // Passing pointer of temp array to arr
        delete[] arr;
        arr = temp_arr;
    }
    else
    {
        // Insert Element at Last
        // Insert Array at First
        cout << "Enter Value to add in array : " << endl;
        cin >> value;

        // making temp_array & filling it
        int *temp_arr = new int[size + 1];
        temp_arr[size] = value;
        for (int i = 0; i < size; i++)
        {
            temp_arr[i] = arr[i];
        }

        // Passing pointer of temp array to arr
        delete[] arr;
        arr = temp_arr;
    }
    size++;
}
void IntArray::remove()
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

    cout << "Choice =>";
    choice = getche();
    cout << endl;

    while (choice < '0' || choice > '2')
    {
        cout << "Invalid Choice !" << endl;
        cout << "Choice =>";
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

        // Removing Element from the index
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;

        break;
    case '2':

        cout << "Enter Element Value : ";
        cin >> value;
        for (int i = 0; i < size; i++)
        {
            if (value == arr[i])
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
                    cout << "Increadees" << endl;
                }
                else
                {
                    temp_arr[i - element_index_counter] = arr[i];
                    cout << i - element_index_counter << " ";
                }
            }
            cout << endl;

            // delte this
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < temp_size; i++)
            {
                cout << temp_arr[i] << " ";
            }
            cout << endl;
            for (int i = 0; i < no_of_index; i++)
            {
                cout << element_index[i] << " ";
            }
            cout << endl;
            getch();

            delete[] element_index;
            delete[] arr;
            arr = temp_arr;
            size = temp_size;
        }
        else
        {
            cout << "No Element Find in Array having " << value << " value" << endl;
            getch();
        }
        break;

    default:
        break;
    }
}
void IntArray::update()
{

    char choice;
    int index = -1;
    int value = 0;
    int no_of_index = 0;
    int *element_index = new int[size];

    cout << "Update Element using : " << endl;
    cout << "1. Index - use for one " << endl;
    cout << "2. Value - use for many " << endl;
    cout << "0. Cancel " << endl;

    cout << "Choice =>";
    choice = getche();
    cout << endl;

    while (choice < '0' || choice > '2')
    {
        cout << "Invalid Choice !" << endl;
        cout << "Choice =>";
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

        cout << "arr [" << index << "] : " << arr[index] << endl;
        cout << "To Update, Enter Value : ";
        cin >> value;

        arr[index] = value;

        break;
    case '2':
        char choice;
        cout << "Enter Value : ";
        cin >> value;
        for (int i = 0; i < size; i++)
        {
            if (value == arr[i])
            {
                element_index[no_of_index] = i;
                no_of_index++;
            }
        }

        if (no_of_index)
        {

            cout << "Total Elements Found : " << no_of_index << endl;
            cout << "At Index : ";
            for (int i = 0; i < no_of_index; i++)
            {
                cout << element_index[i] << " ";
            }
            cout << endl;

            cout << "Do you Want to Update it ? (y/n) : ";
            choice = getche();
            cout << endl;

            while (!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'))
            {
                cout << "Do you Want to Update it ? (y/n) : ";
                choice = getche();
                cout << endl;
            }
            // Replacing Specifc Elements values 
            if(choice=='y' || choice=='Y'){
                cout<<"Enter Value : ";
                cin>>value;
                for (int i =0 ; i<no_of_index; i++ ){
                    arr[element_index[i]]=value;
                }
            }
        }
        else
        {
            cout << "No Element Find in Array having " << value << " value" << endl;
            getch();
        }

        break;

    default:
        break;
    }
}
void IntArray::search()
{

    char choice;
    int index = -1;
    int value = 0;
    int no_of_index = 0;
    int *element_index = new int[size];

    cout << "Search Element using : " << endl;
    cout << "1. Index - use for one " << endl;
    cout << "2. Value - use for many " << endl;
    cout << "0. Cancel " << endl;

    cout << "Choice =>";
    choice = getche();
    cout << endl;

    while (choice < '0' || choice > '2')
    {
        cout << "Invalid Choice !" << endl;
        cout << "Choice =>";
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

        cout<<"At Index "<<index <<" Values is "<<value<<endl;
        cout<<"Press Any Key to Continue ";
            getch();

        break;
    case '2':
        char choice;
        cout << "Enter Value : ";
        cin >> value;
        for (int i = 0; i < size; i++)
        {
            if (value == arr[i])
            {
                element_index[no_of_index] = i;
                no_of_index++;
            }
        }

        if (no_of_index)
        {

            cout << "Total Elements Found : " << no_of_index << endl;
            cout << "At Index : ";
            for (int i = 0; i < no_of_index; i++)
            {
                cout << element_index[i] << " ";
            }
            cout << endl;
            cout<<"Press Any Key to Continue ";
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
// Member Utility Functions
void IntArray::display()
{
    cout << "===========================================" << endl;
    cout << "                Array" << endl;
    cout << "Element : ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "===========================================" << endl;
}
void IntArray::initialize_array()
{
    bool invalid_size = false;
    do
    {
        cout << "Enter Size of Array ";
        cin >> size;
        // If Size is VAlid
        if (size > 0)
        {
            arr = new int[size];
            // Intializing Array ;
            cout << "Enter Array Values" << endl;
            for (int i = 0; i < size; i++)
            {
                cout << " Arr [" << i << "] : ";
                cin >> arr[i];
            }
        }
        // If Size is InVAlid
        else
        {
            cout << "You Have Entered Invalid Array Size! " << endl;
            invalid_size = true;
        }
    } while (invalid_size);
}
#endif