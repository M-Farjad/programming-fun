/*
4. Modify the program of Programming Challenge 2 to allow the user to enter name-score 
pairs. For each student taking a test, the user types the student’s name followed by the 
student’s integer test score. Modify the sorting function so it takes an array holding 
the student names and an array holding the student test scores. When the sorted list 
of scores is displayed, each student’s name should be displayed along with his or her 
score. In stepping through the arrays, use pointers rather than array subscripts. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int *, string *, int);
void selectionSort(int *,string * , int);
void displayArray(int *, string *, int);
double calculateAverage(int *, int);

int main()
{
    double average;
    int num;
    int *arr;
    string *name; 
    cout << "Enter Number of test scores you want to enter :";
    cin >> num;

    arr = new int[num];
    name = new string[num];

    cout << " Enter Test scores and names: " << endl;
    getInput(arr, name,  num);
    selectionSort(arr, name, num);

    average = calculateAverage( arr, num);  
    
    cout << " Array after sorting is : \n";
    displayArray(arr, name ,  num);
    cout << "Avereage is : " << average << endl;

    delete arr;
    return 0;
}

void getInput(int *a, string *n, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i + 1 << " Enter Name:  ";
        cin >> *(n + i);
        do
        {
            cout << setw(3) << i + 1 << " Test score : ";
            cin >> *(a + i);
            if(*(a + i) < 0){
                cout<<"Enter a valid Number. "<<endl;
            }
        } while (*(a + i) < 0);
    }
    cout << endl;
}

void selectionSort(int *a, string *n, int size)
{
    int startIndex, minValue, minIndex;
    string nameOfMin , startName;
    for (startIndex = 0; startIndex < size - 1; startIndex++)
    {
        minValue = a[startIndex];
        minIndex = startIndex;
        startName = n[startIndex];
        for (int i = startIndex + 1; i < size; i++)
        {
            if (minValue > a[i])
            {
                minIndex = i;
                minValue = a[i];
                nameOfMin = n[i];
            }
        }
        a[minIndex] = a[startIndex];
        a[startIndex] = minValue;
        n[startIndex] = nameOfMin;
        n[minIndex] = startName;
    }
}

void displayArray(int *a, string *n ,int size)
{
    for (int i = 0; i < size; i++){
        cout << n[i] <<"\t\t";
        cout << *(a + i) << " ";
    }
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
