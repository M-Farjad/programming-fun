#ifndef CLASSFILEH
#define CLASSFILEH

#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>
#include<fstream>
#include "Product.h"
#include "Pizza.h"
#include "Burger.h"
#include "Shawarma.h"
#include "Extra.h"
#include "Cart.h"
using namespace std;

class FileClass  {
public:
Product *fillFromPizza();
Product *fillFromBurger();
Product *fillFromShawarma();
Product *fillFromExtra();

};
Product* FileClass::fillFromPizza(){
    int num_lines = 0;
	//for pizza
	ifstream in("Database\\Menu\\Pizza.txt");
	string unused;
	while (getline(in, unused))
		++num_lines;
	in.close();
    Product* ptr=new Pizza[num_lines];
    in.open("Database\\Menu\\Pizza.txt");
    for (int i = 0; i < num_lines; i++) {
        in >> ptr[i].p_name;
        in >> ptr[i].p_price;
        
    }
    in.close();
    return ptr;
}
Product* FileClass::fillFromBurger(){
    int num_lines = 0;
	//for burger
	ifstream in("Database\\Menu\\burger.txt");

	string unused;
	while (getline(in, unused))
		++num_lines;
	in.close();
    Product* ptr=new Burger[num_lines];
    in.open("Database\\Menu\\burger.txt");
    for (int i = 0; i < num_lines; i++) {
        in >> ptr[i].p_name;
        in >> ptr[i].p_price;
        
    }
    in.close();
    return ptr;
}
Product* FileClass::fillFromShawarma(){
    int num_lines = 0;
	//for pizza
	ifstream in("Database\\Menu\\shawarma.txt");
	string unused;
	while (getline(in, unused))
		++num_lines;
	in.close();
    Product* ptr=new Shawarma[num_lines];
    in.open("Database\\Menu\\shawarma.txt");
    for (int i = 0; i < num_lines; i++) {
        in >> ptr[i].p_name;
        in >> ptr[i].p_price;
        
    }
    in.close();
    return ptr;
}
Product* FileClass::fillFromExtra(){
    int num_lines = 0;
	//for pizza
	ifstream in("Database\\Menu\\Extras.txt");

	string unused;
	while (getline(in, unused))
		++num_lines;
	in.close();
    Product* ptr=new Extra[num_lines];
    in.open("Database\\Menu\\Extras.txt");
    for (int i = 0; i < num_lines; i++) {
        in >> ptr[i].p_name;
        in >> ptr[i].p_price;
    }
    in.close();
    return ptr;
}


#endif