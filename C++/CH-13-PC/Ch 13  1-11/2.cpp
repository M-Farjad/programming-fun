#include<iostream>
#include<string>
using namespace std;

class Employee{
    string name;
    int idNumber ;
    string department;
    string position;
public:
    Employee(string n, int id, string d, string p){
        name = n;
        idNumber = id;
        department = d;
        position = p;
    }
    Employee(string n, int id){
        name = n;
        idNumber = id;
        department = "";
        position = "";
    }
    Employee(){
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }
    //Mutator functions
    void setName(string n){
        name = n;
    }
    void setId(int n){
        idNumber = n;
    }
    void setDepartment(string n){
        department = n;
    }
    void setPosition(string n){
        position = n;
    }
    void print(){
        cout<<name<<" "<<idNumber<<" "<<department<<" "<<position<<endl;
    }
};

int main(){
    Employee e1("Susan Meyers",47899 , "Accounting", "Vice President");
    Employee e2("Mark Jones",39119 , "IT", "Programmer");
    Employee e3("Joy Rogers",81774 , "Manufacturing", "Engineer");

    e1.print();
    e2.print();
    e3.print();
    return 0;
}