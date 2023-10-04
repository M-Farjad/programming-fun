#include <iostream>

using namespace std;

int main()
{
    int a[3][3] = {6, 2, 5, 0, 1, 3, 4, 9, 8};
    int *p;
    p = a[0];
    cout << "they all print the same address\n";
    cout << "*******************************" << endl;
    cout << p << endl;
    cout << a << endl;
    cout << &a[0][0] << endl;
    cout << &a << endl;
    cout << *a << endl;
    cout << a[0] << endl;

    // Incrementing...
    cout << "\nThey all will print address 12 bytes incremented...\n";
    cout << a + 1 << endl; // a+1 points to next 1D array in two D array
    cout << &a[1] << endl;
    cout << *(a + 1) << endl;

    cout << "\nNow we are printing other elements\n";
    cout << *(a + 1) + 2 << endl;    // prints address of 3
    cout << *(*(a + 1) + 2) << endl; // prints 3

    cout << "\nFind 4\n";
    cout << "There are two methods to find a specific value\n";
    cout << a[2][0] << endl;
    cout << *(*(a + 2) + 0) << endl; // a[i][j]=*(*(a+i)+j)

    return 0;
}
