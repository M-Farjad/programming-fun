#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Student {
	static int roll_num;
	string name;
	float marks;
public:
	Student() {
		name = "null";
		marks = 0.0;
		roll_num++;
	}
	void Setmarks(float m) {
		marks = m;
	}
	void setName(string n) {
		name = n;
	}
	string getName() {
		return name;
	}
	float getMarks() {
		return marks;
	}
	void display() {
		cout <<endl<<"ROll Number: "<<roll_num << "\n" << "Name: "<<name << "\n" <<"MArks: "<< marks << endl;
	}
};
int Student::  roll_num = 0;

int main() {
	Student S1;
	S1.setName("ali");
	S1.Setmarks(100);
	S1.display();

	Student S2;
	S2.setName("umar");
	S2.Setmarks(30);
	S2.display();

	Student S3;
	S3.Setmarks(80);
	S3.setName("yash");
	
	S3.display();

	Student S4;
	S4.Setmarks(67);
	S4.setName("hayat");
	S4.display();

	_getch();
	return 0;
}