#ifndef CARTH
#define CARTH

#include<iostream>
#include<string>
#include<iomanip>
#include"Product.h"
using namespace std;
const int CARTSIZE=10;


class Cart
{
private:
    int count;
public:
    string cartArr[10];
    Cart();
    ~Cart();

    void setCount(int c){
        count=c;
    }
    int getCount(){
        return count;
    }
    void addCount(){
        count++;
    }
    void subCount(){
        count--;
    }

    friend class Product;
    friend class Menu;

    void operator + (Product&);
    void operator - (string);
};

void Cart::operator + (Product & rightObj){
    int index=getCount();
    cartArr[index]=rightObj.get_p_id();
    addCount();

}

Cart::Cart()
{
    // this will store the cart of 10 elements 
    for(int i=0;i<10 ;i++){
        cartArr[i]="00";
    }
    count=0;
}

Cart::~Cart()
{
    count=0;
}

#endif