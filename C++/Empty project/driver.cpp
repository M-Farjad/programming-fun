#include<iostream>
#include"polynomial.h"
using namespace std;



int main() {
	Polynomial obj1,obj2,obj3;
    cout<<"set terms in array 1\n";
    obj1.setArray();
    cout<<"set terms in array 2\n";
    obj2.setArray();

    cout<<"Now showing the terms entered\n";

    obj1.print();
    obj2.print();

    obj3=obj1+obj2;

    cout<<"Now showing addition\n";
    obj3.print();



	return 0;
}



