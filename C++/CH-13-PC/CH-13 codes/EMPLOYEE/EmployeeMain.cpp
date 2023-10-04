#include<iostream>
#include"Employee.h"
using namespace std;
int main() {
	const int SIZE = 3;
	Employee emp[SIZE];
	string name, dept, position;
	int ID;
	
	for (int i = 0; i < SIZE; i++) 
	{
		cout << "\nenter name of employee " << i + 1 << ": ";
		cin.ignore(NULL);
		getline(cin, name);
		cout << "\nEnter id: ";
		cin >> ID;
		cout << "\nEnter dept.: ";
		cin.ignore();
		getline(cin, dept);
		cout << "\nEnter position: ";
		cin.ignore(NULL);
		getline(cin, position);
		
		emp[i].setName(name);
		emp[i].setId(ID);
		emp[i].setDept(dept);
		emp[i].setPosition(position);

		name = emp[i].getName();
		ID = emp[i].getId();
		dept = emp[i].getDept();
		position = emp[i].getPosition();

		cout << name << "\t\t" << ID << "\t\t" << dept << "\t\t" << position << endl;
		
	}
	/*for (int i = 0; i < SIZE; i++) {
		cout << name << "\t\t" << ID << "\t\t" << dept << "\t\t" << position << endl;
	}*/
	return 0;
}