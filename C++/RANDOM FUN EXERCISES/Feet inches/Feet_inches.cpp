#include<cstdlib>
#include"Feet_inches.h"
using namespace std;

//simplify() definition
void FeetInches::simplify()
{
	if (inches >= 12)
	{
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0)
	{
		feet -= ((abs(inches) / 12) + 1);
		inches = 12 - (abs(inches) % 12);
	}
}
//Addition
FeetInches operator+(FeetInches& lobj, FeetInches& robj)
{
	FeetInches temp;
	temp.inches = lobj.inches + robj.inches;
	temp.feet = lobj.feet + robj.feet;
	temp.simplify();
	return temp;		//here we return temp not this
}

//subtraction
FeetInches operator-(FeetInches& lobj, FeetInches& robj)
{
	FeetInches temp;
	temp.inches = lobj.inches - robj.inches;
	temp.feet = lobj.feet - robj.feet;
	temp.simplify();
	return temp;
}