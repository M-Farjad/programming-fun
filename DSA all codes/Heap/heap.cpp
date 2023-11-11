#include<iostream>
using namespace std;

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
			array[i] = 31;
		}
		heapify(array, 1);
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
		if ( (2 * k) < Size && array[k] < array[2 * k + 1] && array[2 * k] < array[2 * k + 1] )
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
	heap obj(7);
	cout << "Left child of 2 index element: " << obj.left(2) << endl;;
	cout << "Right child of 2 index element: " << obj.right(2);
}