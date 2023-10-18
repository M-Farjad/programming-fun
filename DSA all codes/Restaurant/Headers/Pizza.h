#ifndef PIZZAH
#define PIZZAH

#include<iostream>
#include<string>
#include<iomanip>
#include"Product.h"
using namespace std;

class Pizza : public Product
{
private:
    /* data */
public:
     static int count;
    Pizza(string,double);
    ~Pizza();
    static int getCount(){
        return count;
    }

   
};
int Pizza::count=0;
Pizza::Pizza(string name="",double price=0.0):Product(name,price,"P","Pizza")
{
     //id="B5";
    p_id="P"+to_string(count++);
}

Pizza::~Pizza()
{
}




#endif