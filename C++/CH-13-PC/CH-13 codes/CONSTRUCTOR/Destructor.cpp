#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Person
{
private: 
	int id;
	string name;
	string address;
public: 
	Person();
	~Person();
	void setName();
	void setId();
	void setAddress();
	void print();
};

Person::Person()
{
	id = 1;
	name = "Salman";
	address = "Samanabad";
}

Person::~Person()
{
	cout << "Destructor is called " << endl;
}
void Person::print()
{
	cout << "ID IS : " << id << endl;
	cout << "NAME IS : " << name << endl;
	cout << "ADDRESS IS : " << address << endl;
}

int main()
{
	Person P;
	P.print();
	cout << "Mic testing mic testing 123 123 " << endl;
	

}