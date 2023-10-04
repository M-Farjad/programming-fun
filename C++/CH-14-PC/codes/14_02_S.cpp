#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class DayOfYear
{
private:
    int day;
    static string Month[12];
    static int MonthDays[12];

public:
    DayOfYear(int day = 0)
    {
        this->day = day;
    }
    void print()
    {
        cout << "Day " << day << " would be "<<convert();
    }
    string convert(void )
    {
        int d=0; 
       
        for ( int i=0; i<12 ; i++)
        {
            if(day<=(d+=MonthDays[i]))
            {
                return (Month[i] + to_string(day-(d-MonthDays[i])) ) ;
            }
        }
        return "Invalid Entry ";
    }
};

string DayOfYear::Month[12] = {"January ", "Febuary ", "March ", "April ", "May ", "June ", "July ", "Agust ", "September ", "October ", "Novemeber ", "December "};
int DayOfYear::MonthDays[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int day;
    cout << "Enter the Day  : ";
    cin >> day;
    while (day < 0 || day > 365)
    {
        cout << "Invalid Day ,Please Enter Day Between ( 0-365 ) ";
        cin >> day;
    }

    DayOfYear Day1(day);
    Day1.print();
    _getch();
}