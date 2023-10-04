#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

char *ran_char(char *, const int);
void displayArray(char *, const int);

int main()
{
    const int SIZE = 5;
    char array[SIZE] = {'A', 'B', 'C', 'D', 'E'};
    cout << "the array before randomizing is: ";
    displayArray(array, SIZE);
    char *ptr = array;
    ptr = ran_char(ptr, SIZE);
    cout << "\nthe array when randomized is: ";
    displayArray(ptr, SIZE);
    delete[] ptr;
    ptr = nullptr;

    return 0;
}

char *ran_char(char *array, const int SIZE)
{
    char *ptr = new char[SIZE];
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890\\|,<.>/?;:'@#~[{]}=+)(*&^%$£\"!`¬";
    unsigned seed = time(0);
    srand(seed);
    for (int i = 0; i < SIZE; i++)
    {
        char x = letters[rand() % 94];
        *(ptr + i) = x;
    }
    return ptr;
}
void displayArray(char *array, const int SIZE)
{
    for (int i = 0; i < SIZE; i++)
        cout << *(array + i) << " ";
}
/*
OUTPUT : the array before randomizing is : A B C D E
         the array when randomized is : r x M z u
*/