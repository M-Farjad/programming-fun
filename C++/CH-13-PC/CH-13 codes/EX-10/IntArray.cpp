//class definitions
#include"IntArray.h"
#include<iostream>

using namespace std;

IntArray::~IntArray()
{
    delete[] arr;
}
//constru
IntArray::IntArray(int s)
{
    if (s > 0)
        size = s;
    else
    {
        do {
            cout << "Enter Size of Array : ";
            cin >> s;
        } while (s <= 0);
        size = s;
    }
    arr = new float[size];
}
void IntArray::fillArray()
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " Enter Number in arr[" << i << "] : ";
        cin >> arr[i];
    }
}
void IntArray::setValue(float val, int index)  //set value at particular index
{
    if (index < size && index>0)
    {
        arr[index] = val;
    }
    else
    {
        do {
            cout << "Kindly Enter Index less then " << size << " or greater than 0 : ";
            cin >> index;
        } while (index > size || index < 0);
        arr[index] = val;
    }
}
float IntArray::getValue(int index)              //to get value of a particular index
{
    if (index < size)
    {
        return arr[index];
    }
    else
    {
        do {
            cout << "Kindly Enter Index less then " << size << " : ";
            cin >> index;
        } while (index > size || index < 0);
        return arr[index];
    }
}
float IntArray::gethighest()                      //to get highest element of the array
{
    float max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
float IntArray::getLowest()                      //to get lowest element of the array
{
    float min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    return min;
}
float IntArray::getAverage()                    // to get average of all elements in array
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return (sum) / size;
}
void IntArray::print()
{
    cout << endl;
    cout << "The Highest Value is : " << gethighest() << endl;
    cout << "The Lowest  Value is : " << getLowest() << endl;
    cout << "The Average Value is : " << getAverage() << endl;
    cout << "============================================\n";
    for (int i = 0; i < size; i++)               // to display elements of array 
    {
        cout << " arr[" << i << "] : " << arr[i] << "\t";
    }
}