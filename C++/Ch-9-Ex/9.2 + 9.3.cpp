/*
2. Test Scores #1
Write a program that dynamically allocates an array large enough to hold a userdefined number of test scores.
 Once all the scores are entered,
 the array sorts in ascending order.
 function  calculates the average score.
  The program should display the sorted list of
scores and averages with appropriate headings.
 Use pointer notation rather than array
notation whenever possible.
Input Validation: Do not accept negative numbers for test scores.
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int *, int);
void selectionSort(int *, int);
void displayArray(int *, int);
double calculateAverage(int *, int);
double calculateAverageDropping(int *, int);

int main()
{
    double average;
    int num;
    int *arr;
    cout << "Enter Number of test scores you want to enter ";
    cin >> num;

    arr = new int[num];
    cout << " Enter Test scores" << endl;
    getInput(arr, num);
    selectionSort(arr, num);

    // average = calculateAverage( arr, num);  // calucate the avaerage without dropping least value
    average = calculateAverageDropping(arr, num); // calculate the average with droping the least value

    cout << " Array after sorting is : \n";
    displayArray(arr, num);
    cout << "Avereage is : " << average << endl;

    delete arr;
    return 0;
}

void getInput(int *a, int size)
{
    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << setw(3) << i + 1 << " Test score : ";
            cin >> *(a + i);
        } while (*(a + i) < 0);
    }
    cout << endl;
}

void selectionSort(int *a, int size)
{
    int startIndex, minValue, minIndex;
    for (startIndex = 0; startIndex < size - 1; startIndex++)
    {
        minValue = a[startIndex];
        minIndex = startIndex;
        for (int i = startIndex + 1; i < size; i++)
        {
            if (minValue > a[i])
            {
                minValue = a[i];
                minIndex = i;
            }
        }
        a[minIndex] = a[startIndex];
        a[startIndex] = minValue;
    }
}

void displayArray(int *a, int size)
{
    for (int i = 0; i < size; i++)
        cout << *(a + i) << " ";
    cout << endl;
}

double calculateAverage(int *a, int size)
{
    double avg;
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += *(a + i);
    }
    avg = sum / size;
    return avg;
}

//9.3
double calculateAverageDropping(int *a, int size)
{
    double avg;
    double sum = 0;
    for (int i = 1; i < size; i++)
    {
        sum += *(a + i);
    }
    avg = sum / (size - 1);
    return avg;
}