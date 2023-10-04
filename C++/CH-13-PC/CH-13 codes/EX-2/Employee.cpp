#include <iostream>
#include"Employee.h"
#include <string>

using namespace std;

Employee::Employee(string Name, int Id, string Dept, string Pos) {
	name = Name;
	id = Id;
	department = Dept;
	position = Pos;
}
Employee::Employee(string Name, int Id) {
	name = Name;
	id = Id;
	department = "";
	position = "";
}
Employee::Employee() {
	name = "";
	department = "";
	id = 0;
	position = "";
}
void Employee::setName(string s) {
	name = s;
}
void Employee::setId(int s) {
	id = s;
}
void Employee::setDept(string s) {
	department = s;
}
void Employee::setPosition(string s) {
	position = s;
}