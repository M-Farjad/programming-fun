// Implementation file for the Rectangle class.
#include "Rectangle.h" // Needed for the Rectangle class
#include <iostream>    // Needed for cout
#include <cstdlib>     // Needed for the exit function
using namespace std;

//***********************************************************
// setWidth sets the value of the member variable width. *
//***********************************************************
void Rectangle::setWidth(double w)
{
    if (w >= 0)
        width = w;
    else
    {
        cout << "Invalid width\n";
        exit(EXIT_FAILURE);
        /*the exit() function in C++ causes the respective program
          to terminate as soon as the function is encountered, no
          matter where it appears in the program listing.
          The function has been defined under the stdlib.h header
          file, which must be included while using the exit()
          function.*/
    }
}

//***********************************************************
// setLength sets the value of the member variable length. *
//***********************************************************

void Rectangle::setLength(double len)
{
    if (len >= 0)
        length = len;
    else
    {
        cout << "Invalid length\n";
        exit(EXIT_FAILURE);
        /*the exit() function in C++ causes the respective program
          to terminate as soon as the function is encountered, no
          matter where it appears in the program listing.
          The function has been defined under the stdlib.h header
          file, which must be included while using the exit()
          function.*/
    }
}

//************************************************************
// getWidth returns the value in the member variable width. *
//************************************************************

double Rectangle::getWidth() const
{
    return width;
}

//**************************************************************
// getLength returns the value in the member variable length. *
//**************************************************************

double Rectangle::getLength() const
{
    return length;
}

//************************************************************
// getArea returns the product of width times length. *
//************************************************************

double Rectangle::getArea() const
{
    return width * length;
}