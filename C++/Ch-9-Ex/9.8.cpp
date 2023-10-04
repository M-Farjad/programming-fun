#include <iostream>
using namespace std;

int findMode(int [],const int); 

int main()
{
    const int SIZE = 10;
    int numbers[SIZE] = { 1, 2, 3, 4, 5, 7, 19, 8 ,90, 10};

    int mode = findMode(numbers, SIZE);
    if(mode != -1 ){
        cout << "\nMode = " << mode << endl;
    }
    else
        cout << "No value exists more thann one time: ";
    return 0;
}
int findMode(int array[], const int SIZE)
{
    int maxValue = 0,
        maxCount = 0,
        i, j;
    
    for (i = 0; i < SIZE; i++)
    {
        int count = 0;

        for (j = 0; j < SIZE; j++)
        {
            if (*(array + j) == *(array + i))        //comparinng array[i] with array[j] and
                count++;                             // count++ when match
        }

        if (count > maxCount)
        {
            maxCount = count;
            maxValue = *(array + i);
        }
        else if (maxCount == 1)
            maxValue = -1;
    }

    return maxValue;
}
