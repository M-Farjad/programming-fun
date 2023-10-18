#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <windows.h> // for sleep(int)
#include <unistd.h>  // usleep(microseconds)
#include "Headers\\Pizza.h"
#include "Headers\\Burger.h"
#include "Headers\\Product.h"
#include "Headers\\Shawarma.h"
#include "Headers\\Extra.h"
#include "Headers\\Cart.h"
#include "Headers\\ClassFile.h"
#include "Headers\\Menu.h"
#include "Headers\\Login.h"
#include "Headers\\User.h"

using namespace std;

string MONTH[12] = {"January", "Feburary", "March", "April", "May", "June", "July", "Agust", "September", "October", "November", "December"};

int main()
{
    // Functionaltiies
    int monthIndex = 0;
    Cart cart;
    FileClass f;
    Product *A = f.fillFromPizza();
    Product *B = f.fillFromBurger();
    Product *C = f.fillFromShawarma();
    Product *E = f.fillFromExtra();

    Menu M(A, B, C, E, &cart);

    // User Menu Start
    bool userFlag = true;
    bool flag = true;
    bool flagQuit = true;
    bool re_login=false;

    do
    {
        int billCount=1;
        system("CLS");
        Login login;
        User user;
        
        re_login=login[user];
        if(!re_login){
            continue;
        }
        do
        {
            string choice;
            system("CLS");
            M.MenuLogo(MONTH[monthIndex]);
            M.MenuItem();
            M.MenuFooter();
            M.MenuChoice(choice);

            // Menu Functionlities Start
            if (choice[0] == 'q' || choice[0] == 'Q')
            {
                break;
            }
            // 2.View Cart Start
            if (choice == "VC")
            {
                system("CLS");
                M.MenuViewCartHeader("Cart");
                M.MenuViewCart(user.getUserName());
                cout << "Go To Menu (Press Enter )";
                _getch();
            }
            // 3.Remove Item from Cart Start
            else if (choice == "RI")
            {
                bool flag = true;
                do
                {
                    system("CLS");
                    M.MenuViewCart("Cart");
                    M.MenuRemoveItem(flag);
                } while (flag);
            }
            // 4.Place ORDER Start
            else if (choice == "PO" || choice == "po")
            {
                system("CLS");
                bool billcountAdd=true;
                string month = MONTH[monthIndex];
                M.MenuPlaceOrderHeading(user, cart, month,billCount++); // write this thing in this module
                M.MenuViewCart("Cart");
                M.MenuPlaceOrder(user, cart, month);
                if(!billcountAdd){
                    billCount--;
                }
                cout << "Go To Menu (Press Enter )";
                _getch();
            }
            // 5.View Old HISTORY Start
            else if (choice == "VOH" || choice == "voh")
            {
                system("CLS");
                M.MenuViewAllOrder(user);
                cout << "Go To Menu (Press Enter )";
                _getch();
            }
            // 1.Add Item in Cart Start
            else if (choice[0] == 'P' || choice[0] == 'B' || choice[0] == 'S' || choice[0] == 'E')
            {
                M.MenuAddToCart(choice);
                cout << " Added To Cart Succesfully .. \n";
                _getch();
            }
        } while (flag);
        flagQuit = login.loginAgain();
        cin.ignore();
        
    } while (flagQuit);

}