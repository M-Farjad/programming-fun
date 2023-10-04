#include <iostream>
#include <string>
using namespace std;

//class declarations
class Time {
	int hours;
	int minutes;
	int seconds;
public:
	Time() 
	{
		setTime();
	}
	void setTime() {
		int h, m, s;
		cout << "Enter hours ,minutes,seconds comma separated: ";
		cin >> h >> m >> s;
		setHours(h);
		setMinutes(m);
		setSec(s);
	}
	void setHours(int h) {
		if (h < 24 && h >= 0)
			hours = h;
		else
		{
			do
			{
			cout << "Enter valid hours: ";
			cin >> h;
			} while (h>0&&h<24);
			hours = h;

		}
	}
	void setMinutes(int h) {
		if (h < 60 && h >= 0)
			minutes = h;
		else
		{
			do
			{
				cout << "Enter valid minutes: ";
				cin >> h;
			} while (h>0 && h<60);
			minutes = h;
		}
}
	void setSec(int h) {
		if (h < 60 && h >= 0)
			seconds = h;
		else
		{
			do
			{
				cout << "Enter valid hours: ";
				cin >> h;
			} while (h > 0 && h<60);
			seconds = h;
		}
}
	int gethours()const {
		return hours;
	}
	int getminutes()const {
		return minutes;
	}
	int getseconds()const {
		return seconds;
	}
};
int main() {
	Time t;
	cout << "The time u entered is : ";
	cout << t.gethours() << ":" << t.getminutes() << ":" << t.getseconds();
	return 0;

}