#include <iostream>
using namespace std;

char b,
    arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row, col,
    user_1, user_2,
    choice_start, choice_game = 0;
bool win = false,
     flag_start = false,
     flag_game = true;

void confirm(char);
void new_array(void);
void ask_to_rematch(void);
void fill_box(int user, char b);

int main()
{
    new_array();

    while (flag_start)
    {
        for (int i = 1; i <= 9; i++)
        {
            // this will used to display the array ( or tic tak toe format)

            if (i % 2 == 1)
            {
                cout << endl
                     << "=======================================";
                cout << endl
                     << " User-1  \" X \":  Enter no : ";
                cin >> user_1;
                b = 'X';
                fill_box(user_1, b);
            }
            else
            {
                cout << endl
                     << "=======================================";
                cout << endl
                     << " User-2 Enter box to fill \" O \"  : ";
                cin >> user_2;
                b = 'O';
                fill_box(user_2, b);
            }
            // now it will print the array after changing the value
            for (row = 0; row < 3; row++) // for rows
            {
                for (col = 0; col < 3; col++) // for columns
                {

                    cout << arr[row][col];
                    if (col == 2)
                        cout << endl;
                    else
                        cout << "|";
                }
                if (row == 2)
                {
                }
                else
                {
                    cout << "-----" << endl;
                }
            }
            if (i % 2 == 1)
            {
                confirm('X');
                if (win)
                {
                    cout << endl
                         << "=======================================" << endl;
                    cout << endl
                         << "=======================================" << endl;
                    cout << " user-1 has win the match \n";
                    cout << endl
                         << "=======================================" << endl;
                    break;
                }
            }
            else
            {
                confirm('O');
                if (win)
                {
                    cout << endl
                         << "=======================================" << endl;
                    cout << endl
                         << "=======================================" << endl;
                    cout << " user-2 has win the match \n";
                    cout << endl
                         << "=======================================" << endl;
                    break;
                }
            }
            // if all the turns happen and still no one wins then tie display
            if (i == 9)
            {
                cout << "The match has tie good team work";
                break;
            }
        }
        ask_to_rematch();
    }

    cout << endl
         << "Thanks hope to see you again ";
    return 0;
}

void confirm(char d)
{
    if (arr[0][0] == d && arr[0][1] == d && arr[0][2] == d)
    {
        win = true;
    }
    else if (arr[1][0] == d && arr[1][1] == d && arr[1][2] == d)
    {
        win = true;
    }
    else if (arr[2][0] == d && arr[2][1] == d && arr[2][2] == d)
    {
        win = true;
    }
    else if (arr[0][0] == d && arr[1][0] == d && arr[2][0] == d)
    {
        win = true;
    }
    else if (arr[0][1] == d && arr[1][1] == d && arr[2][1] == d)
    {
        win = true;
    }
    else if (arr[0][2] == d && arr[1][2] == d && arr[2][2] == d)
    {
        win = true;
    }
    else if (arr[0][0] == d && arr[1][1] == d && arr[2][2] == d)
    {
        win = true;
    }
    else if (arr[0][2] == d && arr[1][1] == d && arr[2][0] == d)
    {
        win = true;
    }
    else
    {
        win = false;
    }
}

void new_array()
{
    char d = '0';
    cout << endl
         << "=======================================" << endl;
    for (int x = 0; x < 3; x++) // for rows
    {
        for (int y = 0; y < 3; y++) // for columns
        {
            d++;
            arr[x][y] = d;
            cout << arr[x][y];
            if (y == 2)
                cout << endl;
            else
                cout << "|";
        }
        if (x != 2)
            cout << "-----";
        if (x == 0)
            cout << "\t\tWELCOME TO TIC TAC TOE";
        if (x == 1)
            cout << "\t\tOWNER \" FW KI GAMES ! \" ";
        cout << endl;
    }
    cout << " USER-1 = X | USER-2 = O ";
    cout << "\n 1-GAME START \n 0-GAME END \n Enter YOUR CHOICE : ";
    cin >> choice_start;
    if (choice_start == 1)
        flag_start = true;
    cout << "=======================================" << endl;
}

void fill_box(int user, char b)
{

    switch (user)
    {
    case 1:
        arr[0][0] = b;
        break;
    case 2:
        arr[0][1] = b;
        break;
    case 3:
        arr[0][2] = b;
        break;
    case 4:
        arr[1][0] = b;
        break;
    case 5:
        arr[1][1] = b;
        break;
    case 6:
        arr[1][2] = b;
        break;
    case 7:
        arr[2][0] = b;
        break;
    case 8:
        arr[2][1] = b;
        break;
    case 9:
        arr[2][2] = b;
        break;
    }
}

void ask_to_rematch()
{
    cout << endl
         << "=======================================" << endl;
    do
    {
        cout << "Do you want to play again \n 0-NO, 1-YES \n YOUR CHOICE (1,0) :";
        cin >> choice_start;
    } while (choice_start < 0 || choice_start > 1);
    if (choice_start == 0)
        flag_start = false;
    else
        new_array();
    cout << endl
         << "=======================================" << endl;
}
