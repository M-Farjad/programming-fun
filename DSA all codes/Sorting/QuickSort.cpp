#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;                      // Last element less than pivot
    for (int j = l; j < r; j++)         //{1, 6, 3, 5, 4}=>{4, 6, 3, 5, 1}=>{4, 6, 3, 5, 1}=>{4, 6, 3, 5, 1}=>{4, 6, 3, 5, 1}
    {                                                     //i
        if (arr[j] < pivot) 
        {
            i++; 
            swap(arr[i], arr[j]);               
        }
    }
    swap(arr[i+1], arr[r]);                 //=>{4, 1, 3, 5, 6}
    return (i + 1);
}
void QuickSort(int arr[], int l, int r)
{
    if (l < r)                  //this condition will match when there are no or 1 element left in the array
    {
        int pi = partition(arr, l, r); // pivot
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}
int main()
{
    int array[] = {1, 6, 3, 5, 4};
    QuickSort(array, 0, 4);
    for (int i = 0; i < 5; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}