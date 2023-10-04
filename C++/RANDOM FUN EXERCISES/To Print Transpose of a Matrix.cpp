/*
for printing transpose of a Matrix
we generally use row loop as nested
inside col loop and diplay it like
>>>arr[j][i];
*/

#include <iostream>
using namespace std;
int main()
{
    const int rSize = 2, cSize = 3;
    int a[rSize][cSize];

    for (int i = 0; i < rSize; i++)
    { // Taking input in matrix
        for (int j = 0; j < cSize; j++)
        {
            cout << "Enter an element: ";
            cin >> a[i][j];
        }
    }

    // Printing Matrix
    cout << endl
         << "The matrix is : " << endl;
    for (int i = 0; i < rSize; i++)
    {
        for (int j = 0; j < cSize; j++)
        {                            // for normal order of matrix
            cout << a[i][j] << "\t"; // column loop is nested
        }
        cout << endl;
    }

    // Printing Transpose of Matrix
    cout << endl
         << "The Transpose of matrix is : " << endl;
    for (int i = 0; i < cSize; i++)
    {
        for (int j = 0; j < rSize; j++)
        {                            // for transposeof matrix
            cout << a[j][i] << "\t"; // row loop is nested
        }
        cout << endl;
    }

    // 2nd Method
    /*Transpose can be created by making a new matrix and copying the contents
    of the given matrix in transpose format.

    cout<<endl<< "Printing Matrix b: "<<endl;
    int b[cSize][rSize];
    for ( int i = 0 ; i < cSize ; i++){
        for ( int j = 0 ; j < rSize ; j++){                 //copying row into column and colum into row
            b[j][i] = a[j][i];
            cout<<b[j][i]<<"\t";
        }
        cout<<endl;
    }
    */

    return 0;
}