#include"Personalinfo.h"
#include <string>
#include<iostream>
using namespace std;

void PersonalInfo::setdata(string Name, string Add, int age, long phone) {
	name = Name;
	address = Add;
	Age = age;
	phoneNo = phone;
}
void PersonalInfo::getdata() {
		cout << name << "\t\t" << address << "\t\t" << Age << "\t\t" << phoneNo << endl;
}
