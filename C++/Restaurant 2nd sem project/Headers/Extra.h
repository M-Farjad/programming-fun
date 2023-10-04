#ifndef ExtraH
#define ExtraH

#include<iostream>
#include<string>
#include<iomanip>
 #include<cctype>
 #include<cstring>

#include"Product.h"
using namespace std;

 class Extra : public Product
 {
 private:
     /* data */
 public:
     static int count;
     Extra(string,double);
     ~Extra();
     static int getCount(){
        return count;
    }
 };
 int Extra::count=0;
 Extra::Extra(string name="built-in",double price=0.0):Product(name,price,"E","Extra")
{
     //id="B5";
    p_id="E"+to_string(count++);
 }
 
 Extra::~Extra()
 {
 }

    

#endif