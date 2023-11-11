// code for merge sort
#include <iostream>
using namespace std;

class Merge
{
    int *arr;
    int size;

public:
    Merge();
    int getSize() { return size; }
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void displayArray();
};

Merge::Merge()
{
    cout << "Enter the size: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i << ": ";
        cin >> arr[i];
    }
}
void Merge::merge(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2]; // temp arrays
    for (int i = 0; i < n1; i++)
        a[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];
    int i = 0;    // will traverse the a array
    int j = 0;    // will traverse the b array
    int k = left; // will traverse whole array

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        j++;
        k++;
    }
}
void Merge::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}
void Merge::displayArray()
{
    cout << "The Elements are: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
int main()
{
    Merge obj;
    obj.displayArray();

    obj.mergeSort(0, obj.getSize());
    obj.displayArray();
    return 0;
}