#ifndef BURGERH
#define BURGERH

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Burger : public Product
{
private:
    /* data */
public:
    static int count;
    Burger(string,double);
    ~Burger();
    static int getCount(){
        return count;
    }
   
};

int Burger::count=0;

Burger::Burger(string name="",double price=0.0):Product(name,price,"B","Burger")
{
    //id="B5";
    p_id="B"+to_string(count++);
}

Burger::~Burger()
{

}




#endif