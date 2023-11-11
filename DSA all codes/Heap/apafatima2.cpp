void swap(int a, int b)
{
	int temp=0;
	temp = a;
	a = b;
	b = temp;
}

void max_heapify(int arr[], int i, int N)
{
	int left = 2 * i;
	int right = 2 * i + 1;
	int largest;
	if (arr[left] > arr[i] && left <= N)
	{
		largest = left;
	}
	else
		largest = i;
	if (arr[right] > arr[largest] && right <= N)
	{
		largest = right;
	}
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		max_heapify(arr, largest, N);
	}
}
void build_maxheap(int Arr[], int Size)
{
	for (int i = Size / 2; i >= 1; i--)
	{
		max_heapify(Arr, i, Size);
	}
}

int main()
{
	const int SIZE = 8;

	//build_maxheap heapifies the whole tree
	int array[SIZE] = { -1, 4, 7, 8, 3, 9, 6, 5 };              // -1 due to 1-based indexing
	cout << "build_maxheap on Array:  {4, 7, 8, 3, 9, 6, 5}." << endl;
	build_maxheap(array, SIZE - 1);

	//display the array
	cout << "Array after heapification: ";
	for (int i = 1; i < SIZE; i++)
		cout << array[i] << "  ";
	return 0;
}