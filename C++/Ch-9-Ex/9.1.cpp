// This program displays the number of days in each month.
#include <iostream>
using namespace std;
int *arr(int);
int main()
{
    const int SIZE = 5;
    int *ptr = arr(SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        cout << "enter #1: ";
        cin >> *(ptr + i);
        cout << endl;
    }
    system("clear");
    for (int i = 0; i < SIZE; i++)
    {

        cout << "THE no." << i + 1 << " is: " << *(ptr + i);
        cout << endl;
    }
}
int *arr(int SIZE)
{
    return new int[SIZE];
}