// C++ program to dynamically allocate
// the memory for 2D array in C++
// using new operator
#include <iostream>
using namespace std;

// function to dynamically alocate array
int *dynAllocatedArr(int &, int &);
int *GetValuesInArr(int *, int, int);
void DisplayArr(int *, int, int);
// Driver Code
int main()
{
    // Dimensions of the 2D array
    int N_rows, N_cols;

    // Declare a memory block of
    // size N_rows x N_cols
    cout << "Enter the rows size: ";
    cin >> N_rows;
    cout << "\nEnter the columns size: ";
    cin >> N_cols;
    int *arr = dynAllocatedArr(N_rows, N_cols);

    // entering elements in array
    arr = GetValuesInArr(arr, N_rows, N_cols);

    // display the array
    system("clear");
    cout << "Displaying array elements" << endl;
    cout << "*************************" << endl;
    DisplayArr(arr, N_rows, N_cols);

    // Delete the array created
    delete[] arr;
    arr = nullptr;

    return 0;
}
int *dynAllocatedArr(int &N_rows, int &N_cols)
{
    int *arr = new int[N_rows * N_cols];
    return arr;
}

int *GetValuesInArr(int *arr, int N_rows, int N_cols)
{
    for (int i = 0; i < N_rows; i++)
    {
        for (int j = 0; j < N_cols; j++)
        {

            // Assign values to
            // the memory block
            cout << "Enter the Value in array element [" << i << "][" << j << "] : ";
            cin >> (*(arr + i * N_cols + j));
            cout << endl;
        }
    }
    return arr;
}

void DisplayArr(int *arr, int N_rows, int N_cols)
{
    // display the 2D array
    for (int i = 0; i < N_rows; i++)
    {
        for (int j = 0; j < N_cols; j++)
        {
            // Print values of the
            // memory block
            cout << *(arr + i * N_cols + j)
                 << " ";
        }
        cout << endl;
    }
}
