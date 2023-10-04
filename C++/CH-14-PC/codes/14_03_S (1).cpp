#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class DayOfYear
{
private:
    int day;
    int month;
    static string MonthName[12];
    static int MonthDays[12];

public:
    // Consturctor
    DayOfYear()
    {
    }
    DayOfYear(int day = 0)
    {
        this->day = day;
    }
    DayOfYear(string Month = getMonthName(0), int date = 0)
    {
        int d = 0;

        // Adding Days respected date
        d += date;

        // Adding The Total Days Respective to Month
        for (int i = 0; i < 12; i++)
        {
            if (Month == MonthName[i])
            {
                for (int x = 0; x < i; x++)
                    d += MonthDays[x];
                break;
            }
        }

        day = d;
    }

    // Static Funtion
    static string getMonthName(int i)
    {
        return MonthName[i];
    }

    // Utility Function
    void print()
    {
        cout << "Day " << day << " would be " << convert()<<endl;
    }

    // Overloading Converting Function
    string convert(void)
    {
        // Month_Day
        int d = 0;

        for (int i = 0; i < 12; i++)
        {
            if (day <= (d += MonthDays[i]))
            {
                return (MonthName[i] + " " + to_string(day - (d - MonthDays[i])));
            }
        }
        return "Invalid Entry ";
    }
     string convert(int n)
    {
        // Month_Day
        int d = 0;

        for (int i = 0; i < 12; i++)
        {
            if (n <= (d += MonthDays[i]))
            {
                return ("Day "+ to_string(n) + " Would be " +  MonthName[i] + " " + to_string(n - (d - MonthDays[i])) + "\n");
            }
        }
        return "Invalid Entry ";
    }

    // Overloading Operators 
    void operator ++ (void)
    {
        day++;
    }
    void operator -- (void)
    {
        day--;
    }

};

string DayOfYear::MonthName[12] = {"January", "Febuary", "March", "April", "May", "June", "July", "Agust", "September", "October", "Novemeber", "December"};
int DayOfYear::MonthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int date;
    string month, checkMonth;
    bool flag = true;

    do
    {
        cout << "Enter The Month : ";
        cin >> month;
        for (int i = 0; i < 12; i++)
        {
            if (month == DayOfYear::getMonthName(i))
            {
                flag = true;
                break;
            }
        }
    } while (!flag);

    cout << "Enter the Date  : ";
    cin >> date;
    while (date < 0 || date > 31)
    {
        cout << "Invalid Day ,Please Enter Day Between ( 0-31 ) ";
        cin >> date;
    }

    DayOfYear Day(month, date);
    Day.print();
    
    cout<<"The Day After Incrementing : "<<endl;
    ++Day;
    Day.print();

    cout<<"The Day After Decrementing : "<<endl;
    --Day;
    Day.print();

    // Casually testing the Class Functions
    cout<<Day.convert(399);
    cout<<Day.convert(51);


    _getch();
}