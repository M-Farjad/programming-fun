#include"Gpa.h"
#include<iostream>
using namespace std;

//class definitions

GPA::GPA()
{
    cout << "Enter Marks (?/100)  English : ";
    cin >> english;
    cout << "Enter Marks (?/100)  Urdu : ";
    cin >> urdu;
    cout << "Enter Marks (?/100)   Islamiyat : ";
    cin >> islamiyat;
    cout << "Enter Marks (?/100)  Math : ";
    cin >> math;
    cout << "Enter Marks (?/100)  PakStudies : ";
    cin >> pakStudies;
    cout << "Enter Marks (?/100)  Physics : ";
    cin >> physics;
}

float GPA:: getPercentage(void)
{
    return ((english + urdu + islamiyat + math + pakStudies + physics) / 600) * 100;
}
GPA::~GPA() {
    cout << "\n destructor called";

}
void GPA::setGpa(float Gpa) {
    gpa = Gpa;
}
void GPA::setCredit(int C) {
    T_credit_hours = C;
}
float GPA::getGpa() {
    return gpa / T_credit_hours;
}
void GPA::print()
{
    cout << "The Percentage is : " << getPercentage() << "% " << endl;
    cout << "THe Gpa is: " << getGpa() << endl;
}