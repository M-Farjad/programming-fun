#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2-1; i >= 1; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);
        heapify(arr, i, 1);
    }
}

// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 1; i < N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = {-1, 12, 11, 7, 32, 13, 5, 6};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    heapSort(arr, N);
    cout << "Sorted array is\n";
    printArray(arr, N);
}