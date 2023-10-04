#include <iostream>
#include"IntArray.h"
using namespace std;

int main()
{
	const int SIZE = 10;

	//define an inr array obj
	IntArray table(SIZE);
	
	//store values in table
	for (int i = 0; i < SIZE; i++)
		table[i] = (i * 2);

	//Display items in table array
	for (int i = 0; i < SIZE; i++)
		cout << table[i] << " ";
	cout << endl;

	//use the standard + operator to add items
	for (int i = 0; i < SIZE; i++)
		table[i] += 5;

	//Display items in table array
	for (int i = 0; i < SIZE; i++)
		cout << table[i] << " ";
	cout << endl;

	//Now Attempting to access element out of bound
	table[SIZE + 1] = 0;	//this will give an error

	return 0;
}