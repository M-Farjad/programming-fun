#include <iostream>
#include"IntArray.h"
using namespace std;


int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    IntArray a1(size);            //it will declare an array of 3 elements in heap segment
    int index, val;
    a1.fillArray();

    cout << "\nEnter the index of array to set value: ";
    cin >> index;

    cout << "Enter value: ";
    cin >> val;

    a1.setValue(val, index);

    cout << "Enter the index of array to get the value: ";
    cin >> index;
    if (index>0&&index<size)
        cout << "Value of index is: " << a1.getValue(index);
    else {
        do {
            cout << "Enter value less than " << size << " or greter than 0: ";
            cin >> index;
        } while (index<0 || index>size);
        cout << "Value of index is: " << a1.getValue(index);
    }
    a1.print();

    return 0;
}