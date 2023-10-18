#ifndef USERH
#define USERH

#include<iostream>
#include<string>
#include<iomanip>
#include"Product.h"
#include"Cart.h"
using namespace std;


class User
{
private:
    string userName;
    string email;
    string location;
    bool person;
    int order_no;
public:
    User();
    ~User();
    bool getPerson(){
        return person;
    }
    string getUserName(){
        return userName;
    }
    string getEmail(){
        return email;
    }
    string getLocation(){
        return location;
    }

    friend class Login;
    friend class cart;
    friend class Menu;

    
};

User::User(){
    userName="";
    email="";
    location="";
    person=true;
}
User::~User(){

}


#endif