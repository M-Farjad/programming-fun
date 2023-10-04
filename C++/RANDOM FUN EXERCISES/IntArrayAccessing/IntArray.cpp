#include"IntArray.h"
#include <iostream>
#include<cstdlib>		//for the exit function
using namespace std;



//******************************************************** 
// Constructor for IntArray class. Sets the size of the  * 
// array and allocates memory for it.				     * 
//********************************************************
IntArray::IntArray(int s)
{
	size_arr = s;
	aptr = new int[s];
	for (int i = 0; i < s; i++) {
		*(aptr + i) = 0;
	}
}

//****************************************************** 
// Copy Constructor for IntArray class.				   * 
//****************************************************** 

IntArray::IntArray(const IntArray& obj) {
	size_arr = obj.size_arr;
	aptr = new int[size_arr];
	for (int i = 0; i < size_arr; i++)
		*(aptr + i) = *(obj.aptr + i);
}

//****************************************************** 
// Destructor for IntArray class. * 
//****************************************************** 

IntArray::~IntArray()
{
	if(size_arr>0)
		delete [] aptr;
}

//************************************************************ 
// subscriptError function. Displays an error message and * 
// terminates the program when a subscript is out of range. * 
//************************************************************ 
void IntArray::SubscriptError()
{
	 cout << "ERROR: Subscript out of range.\n";
	 exit(0);
}

//******************************************************* 
// Overloaded [] operator. The argument is a subscript. * 
// This function returns a reference to the element * 
// in the array indexed by the subscript. * 
//******************************************************* 
int& IntArray::operator[](const int& ndx)
{
	 if (ndx < 0 || ndx >= size_arr)
		SubscriptError();
	 return aptr[ndx];
}

