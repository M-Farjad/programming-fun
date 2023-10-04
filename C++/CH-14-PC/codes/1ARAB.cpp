#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class Number
{
private:
    int num;
    string lessThan20[19] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eigth", "Nine", 
                              "Ten", "Eleven", "Twelve", "Thirthen", "Fourteen", "Fifteen", "Sixteen",
                              "seventeen", "Eigtheen", "Nineteen" };
    string teen[8] = { "Twenty", "Thirthy", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    string hundred = "Hundred";
    string thousand = "Thousand";

public:
    Number(int num)
    {
        this->num = num;
    }
    void print()
    {
        string Num = to_string(num);
        int r = 0;
        int d = Num.length();

        switch (Num.length())
        {
        case 9:
        {   convertTwoDigit(Num.at(0), Num.at(1));
        cout << " Crores ";
        convertTwoDigit(Num.at(2), Num.at(3));
        cout << " Lacks ";
        convertTwoDigit(Num.at(4), Num.at(5));
        cout << " Thousands , ";
        convertOneDigit(Num.at(5));
        cout << " Hundreds ";
        cout << " and ";
        convertTwoDigit(Num.at(6), Num.at(7));
        break;
        }
        case 8:
        {
            convertOneDigit(Num.at(0));
            cout << " Crores ";
            convertTwoDigit(Num.at(1), Num.at(2));
            cout << " Lacks ";
            convertTwoDigit(Num.at(3), Num.at(4));
            cout << " Thousands , ";
            convertOneDigit(Num.at(5));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(6), Num.at(7));
            break;
        }
        case 7:
        {
            convertTwoDigit(Num.at(0), Num.at(1));
            cout << " Lacks ";
            convertTwoDigit(Num.at(2), Num.at(3));
            cout << " Thousands , ";
            convertOneDigit(Num.at(4));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(5), Num.at(6));
            break;
        }
        case 6:
        {
            convertOneDigit(Num.at(0));
            cout << " Lacks ";
            convertTwoDigit(Num.at(1), Num.at(2));
            cout << " Thousands , ";
            convertOneDigit(Num.at(3));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(4), Num.at(5));
            break;
        }
        case 5:
        {
            convertTwoDigit(Num.at(0), Num.at(1));
            cout << " Thousands , ";
            convertOneDigit(Num.at(2));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(3), Num.at(4));
            break;
        }
        case 4:
        {
            convertOneDigit(Num.at(0));
            cout << " Thousands , ";
            convertOneDigit(Num.at(1));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(2), Num.at(3));
            break;
        }
        case 3:
        {
            convertOneDigit(Num.at(0));
            cout << " Hundreds ";
            cout << " and ";
            convertTwoDigit(Num.at(1), Num.at(2));
            break;
        }
        case 2:
        {
            cout << " and ";
            convertTwoDigit(Num.at(0), Num.at(1));
            break;
        }
        case 1:
        {
            cout << " and ";
            convertOneDigit(Num.at(0));
            break;
        }
        }
    }
    void convertOneDigit(char a)
    {
        int x = a - 48;
        cout << lessThan20[x - 1] << " ";
    }
    void convertTwoDigit(char a, char b)
    {
        int x = a - 48;
        int y = b - 48;

        int check = 10 * x + y;
        if (check < 20)
        {
            cout << lessThan20[check - 1];
        }
        else
        {
            cout << teen[x - 2] << " " << lessThan20[y - 1] << " ";
        }
    }
};

int main()
{
    int n;
    char decision;

    do
    {
        // Input Validator
        do
        {
            cout << "Enter a Number between ( 0-99999999) or( less than 1 Arab) : ";
            cin >> n;
        } while (n < 0 || n > 999999999);

        // Main Program
        Number word(n);
        word.print();

        // Asking for the Replay
        cout << "\n Do You want to Do it Again ( Y/N ) ";
        cin >> decision;

    } while (decision == 'y' || decision == 'Y');

    _getch();
    return 0;
}