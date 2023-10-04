#include "Coin.h"
#include <string>
#include <iostream>
using namespace std;

//function definitions

Coin::Coin()     //default constructor's defination
{
	balance = 0.0;	
	value = 0;					// they will not be used
	sideup = "null";			// they will not be used
}

void Coin::toss()
{
	int max, min;
	max = 1;
	min = 0;

	value = (rand() % (max - min + 1)) + min;

	if (value == 1)
		sideup = "head";	
	else 
		sideup = "tail";
}
