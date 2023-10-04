#include<iostream>
using namespace std;

const int r=2;
const int c=2;

void displayArray1(int arr[r][c])
{
    for (int i =0 ; i < r; i++)
    {
        for( int j=0; j<c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void displayArray2(int arr[][c],int n)
{
    for (int i =0 ; i < n; i++)
    {
        for( int j=0; j<c; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void displayArray3(int * arr , int row , int col)
{
    for (int i =0 ; i < row; i++)
    {
        for( int j=0; j<col; j++)
        {
            cout<<*(arr + i*c + j)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    int arr[r][c]={{1,2},{3,4}};
    displayArray1(arr);
    displayArray2(arr,2);
    displayArray3((int*)arr,2,2);
}