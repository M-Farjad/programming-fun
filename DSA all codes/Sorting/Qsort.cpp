#include <iostream>
using namespace std;

const int SIZE = 5;
class Qsort
{
private:
    int *arr;

public:
    Qsort();
    int partition(int i, int j);
    void QuickSort(int left, int right);
    void display();
};

Qsort::Qsort()
{
    arr = new int[SIZE];
    cout << "Enter elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cin >> arr[i];
    }
}
int Qsort::partition(int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
void Qsort::QuickSort(int left, int right)
{
    if(left<right)
    {
        int pivot = partition(left, right);
        QuickSort(left,pivot-1);
        QuickSort(pivot+1,right);
    }
}
void Qsort::display()
{
    cout << "\nThe elements are: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    Qsort obj;
    cout << "Thea";
    obj.display();
    obj.QuickSort(0, 4);
    obj.display();
}