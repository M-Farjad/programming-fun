#include <iostream>
using namespace std;

class heap
{
    int Size;
    int *array;
public:
    heap(int s = 30):Size(s)
    {
        array = new int[Size];
        cout << "Enter heap elements exactly "<<Size-1<<" elements: ";
        array[0] = -1;
        for (int i = 1; i < Size; i++)
        {
            cin >> array[i];
        }
        heapify(Size, 1);
        cout<<"The normal heap is: ";
        for (int i = 1; i < Size; i++)
        {
            cout << array[i] << "  ";
        }
    }
    int left(int k)
    {
        return 2 * k;
    }
    int right(int k)
    {
        return 2 * k + 1;
    }
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void heapify(int N, int i)
    {
        int largest = i;
        if (left(i) < N && array[left(i)] > array[largest])
            largest = left(i);
        if (right(i) < N && array[right(i)] > array[largest])
            largest = right(i);
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(N, largest);
        }
    }
    void heapSort()
    {
        for (int i = Size / 2 - 1; i >= 1; i--)
            heapify(Size, i);
        for (int i = Size - 1; i >= 1; i--)
        {
            swap(&array[1], &array[i]);
            heapify(i, 1);
        }
    }
    void display()
    {
        for (int i = 0; i < Size; i++)
            cout << array[i] << " ";
        cout << "\n";
    }
};

int main()
{
    cout<<"Enter the Size of Array: ";
    int size;cin>>size;
    heap obj(size);
    obj.heapSort();
    cout << "\nSorted array is: ";
    obj.display();
}