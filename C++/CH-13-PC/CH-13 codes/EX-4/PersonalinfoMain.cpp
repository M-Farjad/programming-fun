#include <iostream>
#include"Personalinfo.h"
#include <string>

using namespace std;

int main()
{
	string name, adress;
	int age;
	long contact;
	cout << "Enter your Information" << endl;
	cout << "Enter the Name " << endl;
	cin >> name;
	cout << "Enter the Adress " << endl;
	cin >> adress;
	cout << "Enter the Age " << endl;
	cin >> age;
	cout << "Enter the Contact " << endl;
	cin >> contact;
	PersonalInfo a, b, c;
	cout << "NAME       ADRESS        AGE       CONTACT #" << endl;
	a.setdata(name, adress, age, contact);


	//for freind
	cout << "Enter your Freind's/RElative's Information" << endl;
	cout << "Enter the Name " << endl;
	cin >> name;
	cout << "Enter the Adress " << endl;
	cin >> adress;
	cout << "Enter the Age " << endl;
	cin >> age;
	cout << "Enter the Contact " << endl;
	cin >> contact;
	b.setdata(name, adress, age, contact);
	
	cout << "Enter your Freind's/RElative's Information" << endl;
	cout << "Enter the Name " << endl;
	cin >> name;
	cout << "Enter the Adress " << endl;
	cin >> adress;
	cout << "Enter the Age " << endl;
	cin >> age;
	cout << "Enter the Contact " << endl;
	cin >> contact;
	c.setdata(name, adress, age, contact);
	a.getdata();
	b.getdata();
	c.getdata();
	return 0;
}