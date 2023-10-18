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
    for (int i = N / 2 - 1; i >= 1; i--)
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
    int arr[] = {-1, 2, 5, 16, 4, 10, 23, 39, 18, 26, 15};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "SIze: " << N << endl;
    for (int i = N / 2 - 1; i >= 1; i--)
        heapify(arr, N, i);
    printArray(arr, N);
    // Function call
    heapSort(arr, N);
    cout << "Sorted array is\n";
    printArray(arr, N);
}

// // Heap Sort in C

// #include <stdio.h>

// // Function to swap the position of two elements

// void swap(int* a, int* b)
// {

// 	int temp = *a;

// 	*a = *b;

// 	*b = temp;
// }

// // To heapify a subtree rooted with node i
// // which is an index in arr[].
// // n is size of heap
// void heapify(int arr[], int N, int i)
// {
// 	// Find largest among root, left child and right child

// 	// Initialize largest as root
// 	int largest = i;

// 	// left = 2*i + 1
// 	int left = 2 * i + 1;

// 	// right = 2*i + 2
// 	int right = 2 * i + 2;

// 	// If left child is larger than root
// 	if (left < N && arr[left] > arr[largest])

// 		largest = left;

// 	// If right child is larger than largest
// 	// so far
// 	if (right < N && arr[right] > arr[largest])

// 		largest = right;

// 	// Swap and continue heapifying if root is not largest
// 	// If largest is not root
// 	if (largest != i) {

// 		swap(&arr[i], &arr[largest]);

// 		// Recursively heapify the affected
// 		// sub-tree
// 		heapify(arr, N, largest);
// 	}
// }

// // Main function to do heap sort
// void heapSort(int arr[], int N)
// {

// 	// Build max heap
// 	for (int i = N / 2 - 1; i >= 0; i--)

// 		heapify(arr, N, i);

// 	// Heap sort
// 	for (int i = N - 1; i >= 0; i--) {

// 		swap(&arr[0], &arr[i]);

// 		// Heapify root element to get highest element at
// 		// root again
// 		heapify(arr, i, 0);
// 	}
// }

// // A utility function to print array of size n
// void printArray(int arr[], int N)
// {
// 	for (int i = 0; i < N; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

// // Driver's code
// int main()
// {
// 	int arr[] = { 12, 11, 13, 5, 6, 7 };
// 	int N = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	heapSort(arr, N);
// 	printf("Sorted array is\n");
// 	printArray(arr, N);
// }

// // This code is contributed by _i_plus_plus_.
