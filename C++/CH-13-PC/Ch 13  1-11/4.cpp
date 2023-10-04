#include <iostream>
#include <string>
using namespace std;

class Data
{
    string name;
    string address;
    int age;
    string phoneNo;

public:
    //mutator functions
    void setName(string n){
        name = n;
    }
    void setAddress(string n){
        address = n;
    }
    void setAge(int a){
        age = a;
    }
    void setPhoneNo(string n){
        phoneNo = n;
    }
};

int main()
{
    Data d1, d2, d3;

    d1.setName("abc");
    d1.setAddress("xyz");
    d1.setAge(25);
    d1.setPhoneNo("030000000");
    
    d2.setName("ABC");
    d2.setAddress("XYZ");
    d2.setAge(45);
    d2.setPhoneNo("032000000");

    d3.setName("Abc");
    d3.setAddress("Xyz");
    d3.setAge(35);
    d3.setPhoneNo("031000000");

    d1.print();
    d2.print();
    d3.print();
    // cout<<d1.getName()<<" "<<d1.getAddress()<<" "<<d1.getAge()<<" "<<d1.getPhoneNo()<<endl;
    // cout<<d2.getName()<<" "<<d2.getAddress()<<" "<<d2.getAge()<<" "<<d2.getPhoneNo()<<endl;
    // cout<<d3.getName()<<" "<<d3.getAddress()<<" "<<d3.getAge()<<" "<<d3.getPhoneNo()<<endl;



    return 0;
}