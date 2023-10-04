#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Time {
protected:
    int hour;			// 0-23
    int minute;			// 0-59
    int sec;
public:
    // dmh - always create a default construtor
    Time() : hour(0), minute(0), sec(0)
    {
    }

    bool setMilitary(unsigned h, unsigned m);

    string civilian();		// get time in civilian format
    string military();		// get time in military format

    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
};

bool Time::setMilitary(unsigned h, unsigned m)
{
    if (h > 23 || m > 59) return false;

    hour = h;
    minute = m;
    return true;
}


string Time::civilian()
{
    if (minute == 0) {
        if (hour == 0) return "midnight";
        if (hour == 12) return "noon";
    }
    ostringstream strm;
    if (hour < 13) {
        strm << hour;
    }
    else {
        strm << hour - 12;
    }
    strm << ':' << setw(2) << setfill('0') << minute;
    if (hour < 12) {
        strm << " AM";
    }
    else {
        strm << " PM";
    }
    return strm.str();
}

string Time::military()
{
    ostringstream strm;
    strm.fill('0');
    strm << setw(2) << hour << setw(2) << minute;
    return strm.str();
}

int
main()
{
    Time t;

    int h;
    int m;

    cout << "Welcome to my military time converter. " << endl;


    while (true) {
        cout << "\nPlease enter the hour hand. ";
        cin >> h;

        cout << endl;

        cout << "Now enter the minute hand. ";
        cin >> m;

        cout << endl;

        if (t.setMilitary(h, m)) {
            break;
        }
        else {
            cerr << "\nError, that isn't in standard format. " << endl;
        }
    }

    cout << "Please wait a second. I'm converting it to the correct ";
    cout << "format. " << endl;

    cout << "\nPress any button to continue. " << endl;

    cin.ignore();
    cin.get();

    cout << "Done " << endl;

    cout << "Civilian time is " << t.civilian() << '\n';
    cout << "Military time is " << t.military() << '\n';
    return 0;
}