#include <iostream>
using namespace std;
double findmedian(double[], const int);
int main()
{
    const int SIZE1 = 10;
    const int SIZE = 9;
    double numbers[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 10};
    double numbers1[SIZE1] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double median = findmedian(numbers, SIZE);
    double median1 = findmedian(numbers1, SIZE1);
    cout << "The median is: " << median << endl;
    ;
    cout << "The 2nd median is: " << median1;
    return 0;
}
double findmedian(double array[], const int SIZE)
{
    double median = 0.0;
    if ((SIZE % 2) != 0)
        median = *(array + (SIZE / 2));
    else
        median = (*(array + (SIZE - 1) / 2) + *(array + (SIZE / 2))) / 2.0;
    return median;
}