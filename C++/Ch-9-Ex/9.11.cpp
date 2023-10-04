#include <iostream>
using namespace std;
int *doubleArraySize(int[], const int);
void display(int *, const int);
int main()
{
    const int SIZE = 5;
    int numbers[SIZE] = {2, 3, 8, 5, 4};
    int *numberDoubled = doubleArraySize(numbers, SIZE);
    display(numbers, SIZE);
    cout << endl;
    display(numberDoubled, SIZE * 2);
    cout << endl
         << endl;

    delete[] numberDoubled;
    numberDoubled = nullptr;
    return 0;
}
int *doubleArraySize(int arr[], const int SIZE)
{
    const int NEWSIZE = SIZE * 2;
    int *newArray = new int[NEWSIZE];
    for (int i = 0; i < NEWSIZE; i++)
    {
        if (i >= SIZE)
            *(newArray + i) = 0;
        else
            *(newArray + i) = arr[i];
    }
    return newArray;
}
void display(int *arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << *(arr + i) << " ";
}
