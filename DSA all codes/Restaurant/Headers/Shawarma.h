#ifndef SHAWARMAHH
#define SHAWARMAHH

#include<iostream>
#include<string>
#include<iomanip>
#include"Product.h"
using namespace std;

 class Shawarma : public Product
 {
 private:
     /* data */
 public:
     static int count;
     Shawarma(string,double);
     ~Shawarma();
     static int getCount(){
        return count;
    }
 };
 int Shawarma::count=0;
 Shawarma::Shawarma(string name="",double price=0.0):Product(name,price,"S","Shawarma")
{
     //id="B5";
    p_id="S"+to_string(count++);
 }
 
 Shawarma::~Shawarma()
 {
 }
 

#endif