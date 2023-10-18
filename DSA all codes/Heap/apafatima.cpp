#include <iostream>
using namespace std;

// class heap
// {
// 	int Size;
// 	int *array;

// public:
// 	heap(int s = 30)
// 	{
// 		Size = s;
// 		array = new int[Size];
// 		cout << "Enter heap elements: ";
// 		array[0] = -1;
// 		for (int i = 1; i < Size; i++)
// 		{
// 			cin >> array[i];
// 		}
// 		heapify(array, 1);
// 		for (int i = 1; i < Size; i++)
// 		{
// 			cout << array[i] << "  ";
// 		}
// 	}
// 	int left(int k)
// 	{
// 		return array[2 * k];
// 	}
// 	int right(int k)
// 	{
// 		return array[2 * k + 1];
// 	}
// 	int parent(int k)
// 	{
// 		return array[(k - 1) / 2];
// 	}
// 	void heapify(int arr[], int k)
// 	{
// 		int temp;
// 		if (k >= Size) return;
// 		if (array[k] < array[2 * k] && array[2 * k + 1] < array[2 * k] && (2 * k) < Size)
// 		{
// 			temp = array[k];
// 			array[k] = array[2 * k];
// 			array[2 * k] = temp;
// 		}
// 		if (array[k] < array[2 * k + 1] && array[2 * k] < array[2 * k + 1] && (2 * k+1) < Size)
// 		{
// 			temp = array[k];
// 			array[k] = array[2 * k + 1];
// 			array[2 * k + 1] = temp;
// 		}
// 		heapify(array, 2 * k);
// 		heapify(array, 2 * k + 1);
// 	}
// };
// int main()
// {
// 	heap obj(7);
// 	cout << "Left child of 2 index element: " << obj.left(2) << endl;
// 	;
// 	cout << "Right child of 2 index element: " << obj.right(2);
// }




// void swap(int a, int b)
// {
// 	int temp=0;
// 	temp = a;
// 	a = b;
// 	b = temp;
// }

// void max_heapify(int arr[], int i, int N)
// {
// 	int left = 2 * i;
// 	int right = 2 * i + 1;
// 	int largest;
// 	if (arr[left] > arr[i] && left <= N)
// 	{
// 		largest = left;
// 	}
// 	else
// 		largest = i;
// 	if (arr[right] > arr[largest] && right <= N)
// 	{
// 		largest = right;
// 	}
// 	if (largest != i)
// 	{
// 		swap(arr[largest], arr[i]);
// 		max_heapify(arr, largest, N);
// 	}
// }
// void build_maxheap(int Arr[], int Size)
// {
// 	for (int i = Size / 2; i >= 1; i--)
// 	{
// 		max_heapify(Arr, i, Size);
// 	}
// }

// int main()
// {
// 	const int SIZE = 8;

// 	//build_maxheap heapifies the whole tree
// 	int array[SIZE] = { -1, 4, 7, 8, 3, 9, 6, 5 };              // -1 due to 1-based indexing
// 	cout << "build_maxheap on Array:  {4, 7, 8, 3, 9, 6, 5}." << endl;
// 	build_maxheap(array, SIZE - 1);

// 	//display the array
// 	cout << "Array after heapification: ";
// 	for (int i = 1; i < SIZE; i++)
// 		cout << array[i] << "  ";
// 	return 0;
// }











class heap
{
	int Size;
	int* array;

public:
	heap(int s = 30)
	{
		Size = s;
		array = new int[Size];
		cout << "Enter heap elements: ";
		for (int i = 1; i < Size; i++)
		{
			cin >> array[i];
		}

		for (int i = Size/2-1; i >= 1; i--)
		{
			heapify(array, i);
		}
		
		// heapify(array,1);
		for (int i = 1; i < Size; i++)
		{
			cout << array[i] << "  ";
		}
	}
	int left(int k)
	{
		return array[2 * k];
	}
	int right(int k)
	{
		return array[2 * k + 1];
	}
	int parent(int k)
	{
		return array[(k - 1) / 2];
	}
	void heapify(int arr[], int k)
	{
		if (k >= Size) return;
		int temp;
		if ((2 * k) < Size && array[k] < array[2 * k] && array[2 * k + 1] < array[2 * k])
		{
			temp = array[k];
			array[k] = array[2 * k];
			array[2 * k] = temp;
		}
		if ((2 * k) < Size && array[k] < array[2 * k + 1] && array[2 * k] < array[2 * k + 1])
		{
			temp = array[k];
			array[k] = array[2 * k + 1];
			array[2 * k + 1] = temp;
		}
		heapify(array, 2 * k);
		heapify(array, 2 * k + 1);
	}
};
int main()
{
	heap obj(8);
	cout << "Left child of 2 index element: " << obj.left(2) << endl;;
	cout << "Right child of 2 index element: " << obj.right(2);
}