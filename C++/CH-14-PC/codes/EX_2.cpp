#include <iostream>
#include<string>

using namespace std;

class DayOfYear {
	int day;								//representing the particular day
	static string month[12];				//for storing the name of months
	static int daysInMonth[12];				//for storing the no of days in a specific month
public:
	DayOfYear(int day) {
		this->day = day;
	}
	void print() {

	}
};
string DayOfYear::month[] = { "January","Feburary","March","April",
							"May","June","July","August","September",
							"October","November","December" };
int DayOfYear::daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int main() {

}

