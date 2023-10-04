//Lab 7 task 5

#include <iostream>
#include<iomanip>
using namespace std;
class Time {
private:
	int hours;
	int min;
	int sec;
public:
	Time operator + (const Time&);
	Time operator - (const Time&);

	Time(int h = 0, int m = 0, int s = 0) {
		if (h > 12 || h < 0)
			hours = 0;
		else
			hours = h;
		if (m > 60)
			min = 0;
		else
			min = m;
		if (s > 60 || s < 0)
			sec = 0;
		else
			sec = s;
	}
	void show();
	/*void simplify(); */
};

//ostream& operator << (ostream& strm, Time& obj) {
//	cout << "hours" << obj.hours << endl;
//	cout << "minutes" << obj.min << endl;
//	cout << "seconds" << obj.sec << endl;
//	return strm;
//}
Time Time :: operator + (const Time& right) {
	Time temp;
	temp.hours = hours + right.hours;
	temp.min = min + right.min;
	temp.sec = sec + right.sec;

	if (temp.min >= 60) {
		temp.min = temp.min % 60;
		temp.hours += 1;
	}
	if (temp.sec >= 60) {
		temp.sec = temp.sec % 60;
		temp.min += 1;
	}
	return temp;
}
Time Time :: operator - (const Time& right) {
	Time temp;
	temp.hours = hours - right.hours;
	temp.min = min - right.min;
	temp.sec = sec - right.sec;
	if (temp.hours < 0) {
		cout << "Hours in first time is less than in second time so the time will be\n" << endl;
		temp.hours = 0;
		temp.min = 0;
		temp.sec = 0;
	}
	else if (temp.min < 0 && temp.sec>0) {
		temp.hours -= 1;
		temp.min += 60;
	}
	else if (temp.sec < 0 && temp.min>0) {
		temp.min -= 1;
		temp.sec += 60;
	}
	else if (temp.min < 0 && temp.sec < 0) {
		temp.hours += 1;
		temp.min += 59;
		temp.sec += 60;
	}
	else
		cout << "Chutti kro ::::";
	return temp;
}
void Time::show() {
	cout << "The time will be:";
	cout << setw(2) << setfill('0');
	cout << hours << ":";
	cout << setw(2) << setfill('0');
	cout << min << ":";
	cout << setw(2) << setfill('0');
	cout << sec << endl;
}
//void Time::simplify() {
//	if (sec >= 60 && (min < 60 && min>0)) {
//		sec = sec % 60;
//		++min;
//		if (min == 60) {
//			min = 0;
//			++hours;
//		}
//	}
//}

int main()
{
	int h, m, s;
	Time t3;
	cout << "enter hours of first time:";
	cin >> h;
	cout << "enter min  of first time:";
	cin >> m;
	cout << "enter seconds of first time:";
	cin >> s;
	Time t1(h, m, s);
	cout << "enter hours of second time:";
	cin >> h;
	cout << "enter min  of second time:";
	cin >> m;
	cout << "enter seconds of second time:";
	cin >> s;
	Time t2(h, m, s);
	t3 = t1 + t2;
	t3.show();
	//t3 = t1 - t2;     some errors but it is not required in manual
	//t3.show();        some errors but it is not required in manual
	return 0;
}