#include <iostream>
using namespace std;
int *elementAddedArray(int[], const int);
void display(int *, const int);
int main()
{
    const int SIZE = 5;
    int numbers[SIZE] = {3, 4, 5, 2, 1};
    int *newArray = elementAddedArray(numbers, SIZE);
    display(numbers, SIZE);
    cout << endl
         << endl;
    display(newArray, SIZE + 1);
    cout << endl
         << endl;
    delete[] newArray;
    newArray = nullptr;
    return 0;
}
void display(int *arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << *(arr + i) << " ";
}
int *elementAddedArray(int arr[], const int SIZE)
{
    int *newArray = new int[SIZE + 1];
    *newArray = 0;
    for (int i = 1, j = 0; i <= SIZE; i++, j++)      //when i = SIZE j = SIZE -1 i.e last index of arr
    {
        *(newArray + i) = arr[j];
    }
    return newArray;
}
