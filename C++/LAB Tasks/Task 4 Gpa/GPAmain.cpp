/*
by entering marks in private members calculate percantage
then calculate GPA by that numbers
*/


#include <iostream>
#include <string >
#include"Gpa.h"
using namespace std;


int main()
{
    /*GPA marks;
    ptr = &marks;*/

    int credit;
    float gpa;
    /*GPA* ptr = new GPA;*/
    unique_ptr<GPA>ptr(new GPA);
    cout << "Enter the total no of credit hours: ";
    cin >> credit;
    cout << "Enter the total added gpa of subjects: ";
    cin >> gpa;

    ptr->setGpa(gpa);
    ptr->setCredit(credit);
    cout << "==============================================" << endl;
    cout << "The total gpa is: " << ptr->getGpa();
    ptr->print();
    
}