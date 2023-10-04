#include<iostream>
#include<string>
#include<cstring>
#include"ContactInfo.h"
using namespace std;

//Example 13-11
int main()
{
	/*char* name;
	char* phonenumber;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter Phone number: ";
	cin >> phonenumber;*/
	
	char name[] = "Kristen Lee";
	char phone[] = "12345";
	Contactinfo entry(name, phone);
	cout << "Name" << entry.getName() << endl;
	cout << "Phone number: " << entry.getPhoneNumber();
	/*entry.~Contactinfo();*/
	return 0;
}