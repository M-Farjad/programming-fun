#include<iostream>
#include<string>
#include"Date.h"

using namespace std;

int main() {
	Date date;
	int day, year;
	int month;
	cout << "Enter day: ";
	cin >> day;
	date.setday(day);
	cout << "\nENter month: ";
	cin >> month;
	date.setmonth(month);
	cout << "\nenter year: ";
	cin >> year;
	date.setyear(year);
	date.getdate();
	return 0;
}