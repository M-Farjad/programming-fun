#ifndef MENUH
#define MENUH

#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include "Product.h"
#include "Pizza.h"
#include "Burger.h"
#include "Shawarma.h"
#include "Extra.h"
#include "Cart.h"
#include "User.h"
#include <windows.h> // for Sleep(milliSeconds)
using namespace std;

const int ASCII = 48;
class Product;
class Menu
{
private:
   Product *Pizza;
   Product *Burger;
   Product *Shawarma;
   Product *Extra;
   Cart *cart;
    void printMenuItemDouble(Product *ptr1, Product *ptr2, int size1, int size2, string message1, string message2);
public:
    Menu(Product*,Product*,Product*,Product*,Cart*); //cart
    ~Menu();

    void MenuLogo(string);
    void MenuItem();
    void MenuFooter();
    void MenuChoice(string &);
    void MenuAddToCart(string);   // void operator +  () //cart
    void MenuRemoveItem(bool &);
    void MenuViewCartHeader(string);
    void MenuTimer(int);
    bool verifyMenuCondition(string c);
    
    void MenuViewCart(string);   // To view Recent Cart
    void MenuViewCart(Cart & ,string);  // to view All Carts
    
    void MenuPlaceOrderHeading(User& user, Cart & cart, string month,int);
    bool MenuPlaceOrder(User& user, Cart & cart, string month);
    void MenuViewAllOrder(User& user);


};

    void Menu::MenuViewAllOrder(User& user){
            char fileName[80];
            string month;
            int totalOrders=0;
            int totalProducts;
            int billCount=1;
            Cart *tempCart;
            ifstream in;

            strcpy(fileName, "Database\\OrderHistory\\");       //converting string into array + coping to fileName 
            strcat(fileName, user.getUserName().c_str());       //converting string into array + coping to fileName 
            strcat(fileName,"_order.txt");           			//strcat combine two character array or join one end to first charcter of other other array 
            
            // Fillind Data Start
            in.open(fileName, ios::app);
            string unused;
	        while (getline(in, unused))
		        ++totalOrders;
	        in.close();
            tempCart = new Cart[totalOrders];
            
            in.open(fileName, ios::app);
            for(int i =0; i<totalOrders; i++){
            in>>month;
            in>>totalProducts;
            tempCart[i].setCount(totalProducts);  //set the array size; 
            for(int j=0;j<totalProducts;j++){
                in>>tempCart[i].cartArr[j];
            }
            }
            in.close();
            // Fillind Data End
            //Printing Data
            system("CLS");
            for(int i=0;i<totalOrders;i++){
            MenuPlaceOrderHeading(user,tempCart[i],month,billCount++);
            MenuViewCart(tempCart[i],"Cart"); 
            }
    }
    bool Menu::MenuPlaceOrder(User& user, Cart & cart, string month){
            string choice;
            char fileName[80];
            cout << "Do you Want to Place Order (Y/N)\n";
            cout << "Choice-> ";
            cin  >> choice;
            if(choice[0]=='Y' || choice[0]=='y' ){
                cout<<"| Request Added \n";
                // Writting Data On File Start
                strcpy(fileName, "Database\\OrderHistory\\");       //converting string into array + coping to fileName 
                strcat(fileName, user.getUserName().c_str());       //converting string into array + coping to fileName 
			    strcat(fileName,"_order.txt");           			//strcat combine two character array or join one end to first charcter of other other array 
                int num_lines=0;
                ifstream in(fileName);
                if(in){
                    string unused;
	                while (getline(in, unused))
		            ++num_lines;
                }
                in.close();           
                ofstream out;                
                out.open(fileName, ios::app);
                if(num_lines>0){                 
                      out<<"\n";
                }
                out<<month<<" ";
                out<<cart.getCount()<<" ";
                for(int i=0;i<cart.getCount();i++){
                    out<<cart.cartArr[i]<<" ";
                }
                out.close();
                // Writting Data On File End
                cart.setCount(0);
                return true;
            }
            else{
                cout<<"Request Cancel";
                return false;
            }
    }
    void Menu::MenuPlaceOrderHeading(User& user, Cart & cart, string month,int billCount=1){
        
        cout <<endl;
            cout << "+=====================================+" << endl;
            cout<<  "| Name       : "<<setw(23)<<left<<user.getUserName()<<"|"<<endl;
            cout<<  "| Email      : "<<setw(23)<<left<<user.getEmail()<<"|"<<endl;
            cout<<  "| Address    : "<<setw(23)<<left<<user.getLocation()<<"|"<<endl;
            cout<<  "| Month      : "<<setw(23)<<left<<month<<"|"<<endl;
            cout<<  "| Total Item : "<<setw(23)<<left<<cart.getCount()<<"|"<<endl;
            cout<<  "| Bill No    : "<<setw(23)<<left<<billCount<<"|"<<endl;
            cout<<  "+=====================================+" << endl;
    }

Menu::Menu(Product *P,Product *B,Product *S,Product *E,Cart *C) {
      Pizza=P;
      Burger=B;
      Shawarma=S;
      Extra=E;
      cart=C;
    }
    Menu::~Menu(){
        delete []Pizza;
        delete []Burger;
        delete []Shawarma;
        delete []Extra;
        delete cart;
    }
void Menu::MenuLogo(string m="January")
{
    // system("CLS");
    cout << "===================================================================" << endl;
    cout << "                        Welcome to Menu         "<<m<<"\n";
    cout << "===================================================================" << endl;
}
void Menu::MenuItem()
{
    printMenuItemDouble(Pizza, Burger, Pizza::getCount(), Burger::getCount(), "Pizza", "Burger");
    printMenuItemDouble(Shawarma, Extra, Shawarma::getCount(), Extra::getCount(), "Shawarma", "Extras");
}
void Menu::MenuFooter()
{
    cout << "==========================   Functionalites   =====================" << endl;
    cout << " 1.Add-Item = (Enter ID)                     2.View Cart = VC      " <<endl;
    cout << " 3.Remove-Item = RI                          4.Place-Order = PO    " << endl;
    cout << " 5.View Order History = VOH                  6.Log-Out = Q         " << endl;
    cout << "===================================================================" << endl;
}
void Menu::MenuChoice(string &c)
{
    bool flag = true;
    do
    {
        cout << "Chose -> ";
        cin >> c;
        // Repeat Until Entry is correct
        flag = verifyMenuCondition(c);
    } while (flag);
}
void Menu::MenuTimer(int x)
{
    for (int i = x; i >= 0; i--)
    {
        cout << i;
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".";
        Sleep(250);
    }
}
void Menu::MenuAddToCart(string choice)
{
    if (choice[0] == 'P')
    {
        int index = choice[1] - ASCII;  
       // Pizza[index].addToCart(cart);   //cart + Pizza[index];
        *cart+Pizza[index];  //cart + Pizza[index];
    }
    else if (choice[0] == 'B')
    {
        int index = choice[1] - ASCII;
        *cart+Burger[index];
    }
    else if (choice[0] == 'S')
    {
        int index = choice[1] - ASCII;
        *cart+Shawarma[index];
    }
    else if (choice[0] == 'E')
    {
        int index = choice[1] - ASCII;
        *cart+Extra[index];
    }

}
void Menu::MenuViewCartHeader(string message="Jester"){
      // Header
    cout << "+=====================================+" << endl;
    cout << "|          "<<setw(27)<<left<<message       <<"|" << endl;
    cout << "+-------------------------------------+" << endl;
}
void Menu::MenuViewCart(string message="Cart")
{
  
    int size = cart->getCount();
    double totalPrize = 0;
    for (int i = 0; i < size; i++)
    {
        string temp = cart->cartArr[i];
        int index = 0;
        cout << "| " << i + 1 << " | ";
        if (temp[0] == 'P')
        {
            index = temp[1] - ASCII;
            cout<<Pizza[index];
            totalPrize += Pizza[index].get_p_price();
        }
        else if (temp[0] == 'B')
        {

            index = temp[1] - ASCII;
            cout<<Burger[temp[1]];
            totalPrize += Burger[index].get_p_price();
        }
        else if (temp[0] == 'S')
        {
            index = temp[1] - ASCII;
            cout<<Shawarma[index];
            totalPrize += Shawarma[index].get_p_price();
        }
        else if (temp[0] == 'E')
        {

            index = temp[1] - ASCII;
            cout<<Extra[index];
            totalPrize += Extra[index].get_p_price();
        }
        cout << " |" << endl;
        cout << "+-------------------------------------+" << endl;
    }
    cout << "+-------------------------------------+" << endl;
    cout << "| TotalPrize =   " << setw(19)<<fixed<< setprecision(2) << totalPrize << "$"
         << " |" << endl;
    cout << "+-------------------------------------+" << endl;
    cout<<endl;
}
void Menu::MenuViewCart(Cart & tempCart ,string message="Cart")
{
  

    int size = tempCart.getCount();
    double totalPrize = 0;
    for (int i = 0; i < size; i++)
    {
        string temp = tempCart.cartArr[i];
        int index = 0;
        cout << "| " << i + 1 << " | ";
        if (temp[0] == 'P')
        {
            index = temp[1] - ASCII;
            cout<<Pizza[index];
            totalPrize += Pizza[index].get_p_price();
        }
        else if (temp[0] == 'B')
        {

            index = temp[1] - ASCII;
            cout<<Burger[temp[1]];
            totalPrize += Burger[index].get_p_price();
        }
        else if (temp[0] == 'S')
        {
            index = temp[1] - ASCII;
            cout<<Shawarma[index];
            totalPrize += Shawarma[index].get_p_price();
        }
        else if (temp[0] == 'E')
        {

            index = temp[1] - ASCII;
            cout<<Extra[index];
            totalPrize += Extra[index].get_p_price();
        }
        cout << " |" << endl;
        cout << "+-------------------------------------+" << endl;
    }
    cout << "+-------------------------------------+" << endl;
    cout << "| TotalPrize =   " << setw(19) << totalPrize << "$"
         << " |" << endl;
    cout << "+-------------------------------------+" << endl;
}
void Menu::MenuRemoveItem(bool & flagMenu)
{
    string c;
    int removingIndex=-1;
    cout << "+-------------------------------------+" << endl;
    cout << "| Enter Item You Want To Remove       |" << endl;
    bool flag = true;
    do
    {
        cout << "Chose -> ";
        cin >> c;

        // If user dont want to remove it will simply move to menu
        if(c[0]=='Q' || c[0]=='q'){
            flagMenu=false;
            flag=false;
            break;
        }

        // Choice Validator
        int size = cart->getCount();
        for (int i = 0; i < size; i++)
        {
            if (cart->cartArr[i] == c)
            {
                //Cart Index to remove 
                removingIndex=i;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Incorrect Entry - Product Not Found \nAgain "; // print if enter dont match id in cart
        }
    } while (flag);

    // Perofrmin Action according to the situation
    if(c[0]=='Q' || c[0]=='q'){
        flagMenu=false;
    }
    else{
    // Remove the Item from Cart; 
        int size = cart->getCount();    // operator - (string) // operator - ( Product)
        for (int i = removingIndex; i < size; i++)
        {
            cart->cartArr[i]=cart->cartArr[i+1];
        }
        cart->cartArr[size-1]="00";
        cart->subCount();
        flagMenu=true;
    }

}
bool Menu::verifyMenuCondition(string c)
{
    if (c[0] == 'Q' || c[0] == 'q')
    {
        return false;
    }
    if (c == "VC" || c == "vc")
    {
        return false;
    }
    else if (c == "PO" || c == "po")
    {
        return false;
    }
    else if (c == "RI" || c == "ri")
    {
        return false;
    }
    else if (c == "VOH" || c == "voh")
    {
        return false;
    }
    else if (c[0] == 'P')
    {       
        if (int(c[1]) - ASCII >= 0 && int(c[1]) - ASCII < Pizza::count)
        {
            return false;
        }
        else
        {
            cout << "Not-Avaliable \n Agian ";
            return true;
        }
    }
    else if (c[0] == 'B')
    {
        if (int(c[1]) - ASCII >= 0 && int(c[1]) - ASCII < Burger::count)
        {
            return false;
        }
        else
        {
            cout << "Not-Avaliable \n Agian ";
            return true;
        }
    }
    else if (c[0] == 'S')
    {
        if (int(c[1]) - ASCII >= 0 && int(c[1]) - ASCII < Shawarma::count)
        {
            return false;
        }
        else
        {
            cout << "Not-Avaliable \n Agian ";
            return true;
        }
    }
    else if (c[0] == 'E')
    {
        if (int(c[1]) - ASCII >= 0 && int(c[1]) - ASCII < Extra::count)
        {
            return false;
        }
        else
        {
            cout << "Not-Avaliable \n Agian ";
            return true;
        }
    }
    else
    {
        cout << "Incorrect Choice \n Agian ";
        return true;
    }
}
void Menu::printMenuItemDouble(Product *ptr1, Product *ptr2, int size1, int size2, string message1, string message2)
{
    cout << setw(12) << " " << setw(10) << right << message1 << setw(9) << "";
    cout << " | ";
    cout << setw(12) << " " << setw(10) << right << message2 << setw(9) << " ";
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    // For First
    cout << setw(5) << left << "ID";              
    cout << setw(20) << left << "Name";
    cout << setw(6) << right << "Price";
    cout << " | ";
    // For Second
    cout << setw(5) << left << "ID";
    cout << setw(20) << left << "Name";
    cout << setw(6) << right << "Price";
    cout << endl;

    cout << "-------------------------------------------------------------------" << endl;

    // detmering size
    int size = 0;
    if (size1 <= size2) // size1 = 5  size2 = 3  size =5    pizza 5  burger 3
    {
        size = size2;
    }
    else
    {
        size = size1;
    }
    // displaying Values
    for (int i = 0; i < size; i++)
    {
        if (i < size1)
        {
            cout<<ptr1[i];
            cout << " | ";
        }
        else
        {
            cout << "                                | ";
        }
        if (i < size2)
        {
            cout<<ptr2[i];
            cout << " ";
        }
        cout << endl;
    }
    cout << "===================================================================" << endl;
}

#endif
