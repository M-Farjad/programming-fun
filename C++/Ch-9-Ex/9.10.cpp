#include <iostream>
using namespace std;
double *ReverseArray(double[], const int);
void display(double *, const int);
int main()
{
    const int SIZE = 10;
    double numbers[SIZE] = {1, 4, 2, 3, 6, 8, 5, 7, 9, 0};
    double *numbersReversed = ReverseArray(numbers, SIZE);
    cout << endl;
    display(numbers, SIZE);
    cout << endl;
    display(numbersReversed, SIZE);

    delete[] numbersReversed;
    numbersReversed = nullptr;
    return 0;
}
double *ReverseArray(double arr[], const int SIZE)
{
    double *newArray = new double[SIZE];
    int j = (SIZE - 1);             //index of last elemnt is n-1
    for (int i = 0; i < SIZE; i++, j--)
    {
        *(newArray + i) = arr[j];
    }
    return newArray;
}
void display(double *arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << *(arr + i) << " ";
    }
}
