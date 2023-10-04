#include <iostream>
#include "Date.h"
#include <string>
#include <conio.h>

using namespace std;

void Date::setday(int a) {
	bool flag = true;
	do
	{
		if (a >= 1 && a <= 31) 
		{
			day = a;
			flag = true;
		}
		else
		{
			cout << "Enter valid value for day: ";
			flag = false;
			cin >> a;
		}
	} while (!(flag));
}
void Date::setmonth(int mon) {
	bool flag = true;
	do
	{
		if (mon >= 0 && mon <= 12) {
			flag = true;
			month = mon;
		}
		else
		{
			cout << "Enter valid value for month: ";
			flag = false;
			cin >> mon;
		}
	} while (!flag);
}
void Date::setyear(int a) {
	bool flag = true;
	do
	{
		if (a >= 0) {
			year = a;
			flag = true;
		}
		else
		{
			cout << "Enter valid value for year: ";
			flag = false;
			cin >> a;
		}
	} while (!(flag));
}
void Date:: getdate()const {
	char c = ' ';
	bool flag = true;
	cout << "Enter a character in which date will be formatted\n ";
	cout << "1.   /\n2.    ' '\n3.     ','\n";
	cout << "Enter your value: ";
	cin.ignore();
	cin.get(c);
	do
	{
        if (c == '/')
        {
            cout << day << "/" << month << "/" << year << endl;
        }
        else if (c == ',')
            cout << month << " " << day << "," << year << endl;
        else if (c == ' ')
            cout << day << " " << month << " " << year << endl;
		else
			flag = false;
	} while (!flag);
}
//string Date:: inputMonth()     //to store month in specific format
//{
//        string tempMonth;
//        bool monthCheck = true;
//        do {
//            cout << "\nEnter the Month                  : ";
//            cin >> tempMonth;
//            if (tempMonth == "1" || tempMonth == "jan" || tempMonth == "Jan" || tempMonth == "JAN" || tempMonth == "January" || tempMonth == "january" || tempMonth == "JANUARY")
//            {
//                tempMonth = "January";
//                return tempMonth;
//            }
//            else if (tempMonth == "2" || tempMonth == "feb" || tempMonth == "Feb" || tempMonth == "FEB" || tempMonth == "February" || tempMonth == "february" || tempMonth == "FEBRUARY")
//            {
//                tempMonth = "February";
//                return tempMonth;
//            }
//            else if (tempMonth == "3" || tempMonth == "mar" || tempMonth == "Mar" || tempMonth == "MAR" || tempMonth == "March" || tempMonth == "march" || tempMonth == "MARCH")
//            {
//                tempMonth = "March";
//                return tempMonth;
//            }
//            else if (tempMonth == "4" || tempMonth == "apr" || tempMonth == "Apr" || tempMonth == "APR" || tempMonth == "April" || tempMonth == "april" || tempMonth == "APRIL")
//            {
//                tempMonth = "April";
//                return tempMonth;
//            }
//            else if (tempMonth == "5" || tempMonth == "may" || tempMonth == "May" || tempMonth == "MAY")
//            {
//                tempMonth = "May";
//                return tempMonth;
//            }
//            else if (tempMonth == "6" || tempMonth == "June" || tempMonth == "june" || tempMonth == "JUNE")
//            {
//                tempMonth = "June";
//                return tempMonth;
//            }
//            else if (tempMonth == "7" || tempMonth == "July" || tempMonth == "july" || tempMonth == "JULY")
//            {
//                tempMonth = "July";
//                return tempMonth;
//            }
//            else if (tempMonth == "8" || tempMonth == "aug" || tempMonth == "Aug" || tempMonth == "AUG" || tempMonth == "August" || tempMonth == "august" || tempMonth == "AUGUST")
//            {
//                tempMonth = "August";
//                return tempMonth;
//            }
//            else if (tempMonth == "9" || tempMonth == "sep" || tempMonth == "Sep" || tempMonth == "SEP" || tempMonth == "September" || tempMonth == "september" || tempMonth == "SEPTEMBER")
//            {
//                tempMonth = "September";
//                return tempMonth;
//            }
//            else if (tempMonth == "10" || tempMonth == "oct" || tempMonth == "Oct" || tempMonth == "OCT" || tempMonth == "October" || tempMonth == "october" || tempMonth == "OCTOBER")
//            {
//                tempMonth = "October";
//                return tempMonth;
//            }
//            else if (tempMonth == "11" || tempMonth == "nov" || tempMonth == "Nov" || tempMonth == "NOV" || tempMonth == "November" || tempMonth == "november" || tempMonth == "NOVEMBER")
//            {
//                tempMonth = "November";
//                return tempMonth;
//            }
//            else if (tempMonth == "12" || tempMonth == "dec" || tempMonth == "Dec" || tempMonth == "DEC" || tempMonth == "December" || tempMonth == "december" || tempMonth == "DECEMBER")
//            {
//                tempMonth = "December";
//                return tempMonth;
//            }
//            else {
//                cout << "\n///////////Invaid Input////////////\n";
//                monthCheck = false;       ////If it is true month will be asked again
//
//            }
//        } while (!monthCheck);
//        return tempMonth;
//    }                