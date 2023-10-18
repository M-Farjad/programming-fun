#ifndef PRODUCTH
#define PRODUCTH

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
//Forwar Declaration
class FileClass;
class Menu;
class Product{
protected:
        string p_id;
        string p_type;
        string p_name;
        double p_price;
public:
    Product(string,double,string,string);
    ~Product();

    string get_p_id(){
        return p_id;
    }
    string get_p_type(){
        return p_type;
    }
    double get_p_price(){
        return p_price;
    }

    void  printItem();
    friend ostream& operator << (ostream &out,Product& rightObj) ;

    friend class FileClass;
    friend class Menu;    
    friend class Cart;

};

Product::Product(string name="",double price=0.0,string id="",string type="")
{
    p_id=id;
    p_type=type;
    p_name=name;
    p_price=price;
}
Product::~Product()
{
}
ostream& operator << (ostream &out,Product& rightObj) 
{
    out<<setw(5)<<left<<rightObj.p_id;
    out<<setw(20)<<left<<rightObj.p_name;
    out<<setw(5)<<right<<rightObj.p_price<<"$";
    return out;
}




#endif