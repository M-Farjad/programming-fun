// This Program will move the Array to Anti Clock Wise 
#include<iostream>
using namespace std;
const int colSize = 3;
const int rowSize = 3;

void displayArray(int*, int, int);
void check(int, int, int, int);
void swapArray(int*, int, int);



int main()
{
    const int colSize = 3;
    const int rowSize = 3;
    int arr[rowSize][colSize] = { {1,2,3},{4,5,6},{7,8,9} };
    cout << " The array before suffling is : \n";
    displayArray((int*)arr, rowSize, colSize);
    cout << " Now move the array by 1 \n";
    swapArray((int*)arr, rowSize, colSize);
    displayArray((int*)arr, rowSize, colSize);
}

void displayArray(int* arr, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << *(arr + i * c + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void check(int i, int j, int& a, int& b, int r, int c)
{ 
    if (j  == 0)
    {
        a = i - 1;
        b = c-1;
    }
    else
    {   
        a=i;
        b=j-1;
    }
}

void swapArray(int* arr, int r, int c)
{
    int a, b;
    for (int i = r-1; i >=0 ; i--)
    {
        for (int j = c-1; j >=0; j--)
        {
            if (i == 0 && j  == 0)
                break;
            check(i, j, a, b, r, c);
            swap(*(arr + i * c + j), *(arr + a * c + b));  //  built in function so there is not need to define it 
        }

    }
} 