#ifndef LOGINNH
#define LOGINNH

#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <windows.h>
#include "User.h"

using namespace std;

class Login
{
protected:
    string *username;
    string *email;
    string *location;
    string *password;
    string *adminUsername;
    string *adminPassword;
    string *adminEmail;
    string *adminLocation;
    int no_of_users;
    int no_of_admins;

public:
    Login()
    {
        allocateArrays();
        fillArrays();
    }
    ~Login(){
        delete []username;
        delete []email;
        delete []location;
        delete []password;
        delete []adminUsername;
        delete []adminPassword;
    }

    bool login(User &user);

    void fillArrays();

    void allocateArrays();

    void loginWelcome()
    {
        cout << "Welcome Brother  ->   ";
        for (int i = 3; i >= 0; i--)
        {
            cout << "\b \b" << i << "    ";
            Sleep(1000);
            cout << "\b\b\b\b";
        }
    }
    bool operator[](User &user)
    {
       return login(user);
    }
    bool loginAgain();
    void signUp();
};
void Login::signUp(){
    string tempUS ,tempPass, tempEmail, tempLoc;
    bool usernameExist = false;
    cout<<" Enter username: ";
    cin>>tempUS;
    for (int i = 0 ; i < no_of_users ; i++){
        if(username[i] == tempUS){
            usernameExist = true;
        }
    }
    if(usernameExist == false ){
        cout<<" Enter email: ";
        cin>>tempEmail;
        cout<<" Enter Location: ";
        cin>>tempLoc;  
        cout<<" Enter password: ";
        cin>>tempPass; 

        //writing new account details to file
        ofstream out;
        out.open("Database\\Accounts\\userAccounts.txt", ios::app);
        out<<endl; 
        out<<tempUS<<" "; 
        out<<tempPass<<" "; 
        out<<tempEmail<<" "; 
        out<<tempLoc<<" "; 
        out.close();
    }
    else {
        cout<<" Username already login instead.";
    }


}
bool Login::loginAgain()
{
    string loginAgain;
    cout << "Login Again : ( Y/N) ";
    cin >> loginAgain;
    if (loginAgain[0] == 'Y' || loginAgain[0] == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Login::login(User &user)
{
    char choice;
    cout << "    1- Sign Up " << endl;
    cout << "    2- Login "<<endl;
    cout << "    Enter Choice -> " ;
    cin >> choice;
    cin.ignore();
    if (choice == '1')
    {
        system("CLS");
        signUp();
        return false;
    }
    else
    {

        int index = 0;
        
        system("CLS");
        cout << "In Login\n";
        bool found = false;
        string uName = "";
        string pass = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0',
                       '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
        do
        {
            cout << "Enter username: ";
            getline(cin, uName);

            for (int i = 0; i < no_of_users; i++)
            {
                if (uName == username[i])
                {
                    do
                    {
                        char ch;
                        cout << "\nEnter password:  ";
                        for (int i = 0; i <= 20; i++)
                        {
                            ch = _getch();
                            if (ch == 13)
                            {
                                break;
                            }
                            if (ch == 8)
                            {
                                cout << "\b \b";
                                i = i - 2;
                                if (i < 0)
                                {
                                    i = -1;
                                }
                                continue;
                            }
                            pass[i] = ch;
                            ch = '*';
                            cout << ch;
                        }
                        if (strcmp(pass.c_str(), (password[i]).c_str()))
                        {
                            cout << "Incorrect Password Entered! Try Again " << endl;
                        }
                        else
                        {
                            cout << "\nUser Login Success " << endl;
                            found = true;
                            user.userName = username[i];
                            user.email = email[i];
                            user.location = location[i];
                            user.person = true;
                        }

                    } while (strcmp(pass.c_str(), (password[i]).c_str()));
                }
            }

            for (int i = 0; i < no_of_admins && (found == false); i++)
            {
                if (uName == adminUsername[i])
                {
                    do
                    {
                        char ch;
                        cout << "\nEnter password:  ";
                        for (int i = 0; i <= 20; i++)
                        {
                            ch = _getch();
                            if (ch == 13)
                            {
                                break;
                            }
                            if (ch == 8)
                            {
                                cout << "\b \b";
                                i = i - 2;
                                if (i < 0)
                                {
                                    i = -1;
                                }
                                continue;
                            }
                            pass[i] = ch;
                            ch = '*';
                            cout << ch;
                        }
                        if (strcmp(pass.c_str(), (adminPassword[i]).c_str()))
                        {
                            cout << "Incorrect Password Entered! Try Again " << endl;
                        }
                        else
                        {
                            // username=username
                            cout << "\nAdmin Login Success " << endl;
                            found = true;
                            user.userName = adminUsername[i];
                            user.email = adminEmail[i];
                            user.location = adminLocation[i];
                            user.person = false;
                        }
                    } while (strcmp(pass.c_str(), (adminPassword[i]).c_str()));
                }
            }
            if (found == false)
            {
                cout << "\n Username does not exist." << endl;
            }
        } while (found == false); // if login succes loop will break
        return true;
    }
    loginWelcome();
}
void Login::fillArrays()
{
    ifstream in;
    in.open("Database\\Accounts\\userAccounts.txt");
    for (int i = 0; i < no_of_users; i++)
    {
        in >> username[i];
        in >> password[i];
        in >> email[i];
        in >> location[i];
        // cout<<username[i]<<"  "<<password[i]<<endl;  //for testing
    }
    in.close();

    in.open("Database\\Accounts\\adminAccounts.txt");
    for (int i = 0; i < no_of_admins; i++)
    {
        in >> adminUsername[i];
        in >> adminPassword[i];
        in >> adminEmail[i];
        in >> adminLocation[i];
        // cout<<adminUsername[i]<<"  "<<adminPassword[i]<<endl;    //for testing
    }
    in.close();
}
void Login::allocateArrays()
{
    no_of_users = 0;
    string unused;

    ifstream in;
    in.open("Database\\Accounts\\userAccounts.txt");
    while (getline(in, unused))
        ++no_of_users;
    in.close();
    if (no_of_users > 0)
    {
        username = new string[no_of_users];
        password = new string[no_of_users];
        email = new string[no_of_users];
        location = new string[no_of_users];
    }
    else
    {
        username = nullptr;
        password = nullptr;
        email = nullptr;
        location = nullptr;
    }

    no_of_admins = 0;
    in.open("Database\\Accounts\\adminAccounts.txt");
    while (getline(in, unused))
        ++no_of_admins;
    in.close();

    if (no_of_admins > 0)
    {
        adminUsername = new string[no_of_admins];
        adminPassword = new string[no_of_admins];
        adminEmail = new string[no_of_users];
        adminLocation = new string[no_of_users];
    }
    else
    {
        adminUsername = nullptr;
        adminPassword = nullptr;
        email = nullptr;
        location = nullptr;
    }

}

#endif