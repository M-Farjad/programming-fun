#include<iostream>
using namespace std;
class Heap {
public:
	int size, count;
	int* arr;
	void Heap_Max(int child) {
		int parent = (child - 1) / 2;
		if (arr[child] > arr[parent]) {
			int temp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = temp;
			Heap_Max(parent);
		}
	}
	void Heap_Min(int root) {
		int last = count - 1;
		int leftChild = root * 2 + 1;
		int rightChild = root * 2 + 2;
		int bigBrother;
		if (leftChild <= last) {
			if (leftChild == last)
				bigBrother = leftChild;
			else {
				if (arr[leftChild] > arr[rightChild])
					bigBrother = leftChild;
				else
					bigBrother = rightChild;
			}

			if (arr[bigBrother] > arr[root]) {//swap
				int temp = arr[bigBrother];
				arr[bigBrother] = arr[root];
				arr[root] = temp;
				Heap_Min(bigBrother);
			}
		}
	}
public:
	Heap(int size) {
		this->size = size;
		arr = new int[size];
		count = 0;
	}
	void BuildHeap(int num) {
		if (count == size) {
			cout << "Not Enough Space!";
		}
		else {
			arr[count] = num;
			if (count > 0)
				Heap_Max(count);//Heap_Min(count) for minimun heap 
			count++;
		}
	}
	void simpleheap(int num)
	{
		if (count == size) 
		{
			return;
		}
		else {
			arr[count] = num;
			count++;
		}
	}
	int removeTop() {
		if (count == 0) {
			cout << "Not Enough Space!";
			return NULL;
		}
		else {
			int top = arr[0];
			arr[0] = arr[count - 1];
			count--;
			Heap_Min(0);
			return top;
		}
	}
	void heapify(int last)
	{
		if (last == 1)
		{
			return;
		}
		int parent = (last - 1) / 2;
		if (arr[parent] < arr[last])
		{
			int temp = arr[parent];
			arr[parent] = arr[last];
			arr[last] = temp;
		}
		heapify(last - 1);
	}
	void display() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}
};
int main()
{
	Heap myHeap(15);
	myHeap.BuildHeap(131);
	myHeap.BuildHeap(134);
	myHeap.BuildHeap(103);
	myHeap.BuildHeap(52);
	myHeap.BuildHeap(66);
	myHeap.BuildHeap(7);
	myHeap.display();
	return 0;
}