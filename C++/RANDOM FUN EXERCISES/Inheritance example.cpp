#include<iostream>
using namespace std;

//class Base
//{
//    int data1; // private by default and is not inheritable
//    int data2;
//public:
//    void setData();
//    int getData1();
//    int getData2();
//};
//
//void Base::setData(void)
//{
//    data1 = 10;
//    data2 = 20;
//}
//
//int Base::getData1()
//{
//    return data1;
//}
//
//int Base::getData2()
//{
//    return data2;
//}

//class Base {
//	int d1;
//public:
//	Base() {
//		d1 = 0;
//		cout << "Hello i'm the constructor of base\n";
//	}
//	void setd1(int d1) {
//		this->d1 = d1;
//	}
//	int getd1() const {
//		return d1;
//	}
//	void printD1() {
//		cout << "The data in base class is: ";
//		cout << d1;
//	}
//	~Base()
//	{
//		cout << "\ni'm the destructor of base\n";
//	}
//};
//class Derived:public Base
//{
//public:
//	Derived() {
//		cout << "Hello i'm the consteructor of derived\n";
//		d2 = 0;
//		d3 = 0;
//	}
//	~Derived() {
//		cout << "\nI'm the destructor of derived \n";
//	}
//	void setd2(int d1) {
//		this->d2 = d1;
//	}
//	int getd2() const {
//		return d2;
//	}
//	void setd3(int d1) {
//		this->d3 = d1;
//	}
//	int getd3() const {
//		return d3;
//	}
//	void PrintDer() {
//		cout << "The data in derived class is : \n";
//		cout << d2 << " " << d3 << endl;
//	}
//private:
//	int d2, d3;
//};
//
//int main() {
//	Base b1;
//	cout << "Hello how are u...!" << endl;
//	Derived d1;
//	int a = 10;
//	d1.PrintDer();
//	cout << sizeof(d1);
//	return 0;
//}






//#include <iostream>
//#include <string>
//using namespace std;
//
//class ParentClass {
//public:
//	virtual void print() {
//		cout << "I am parent print" << endl;
//	}
//};
//class ChildClass : public ParentClass {
//public:
//
//	void print() { // this is called function overriding.
//		cout << "I am child print" << endl;
//
//	}
//};
//
//int main() {
//	ChildClass childObj;
//	ParentClass* parentPtr;
//	parentPtr = &childObj;
//
//	parentPtr->print();
//	ParentClass parentObj;
//	parentObj.print();
//
//	return 0;
//}









//#include <iostream>
//using namespace std;
//class Fan {
//public:
//	Fan() {
//		cout << "Hi I am fan!" << endl;
//	}
//	~Fan() {
//		cout << "Bye I was fan!" << endl;
//	}
//};
//class Room {
//public:
//	Room() {
//		cout << "Hi I am a room!" << endl;
//	}
//	~Room() {
//		cout << "Bye I was a room" << endl;
//	}
//};
//
//class House {
//	Room room1;
//	Fan* fan;
//public:
//	House(Fan* fanPtr) {
//		fan = fanPtr;
//	}
//	~House() {
//		cout << "Bye from house!" << endl;
//	}
//
//};
//
//int main() {
//	{
//		Fan* fan = new Fan();
//		House house(fan);
//		//delete fan; if you want destroy, you can do it yourself. it will not be done automatically.
//	}
//	cout << "I am outside the scope";
//	return 0;
//}




//#include <iostream>
//#include <string>
//using namespace std;
//class Animal {
//private:
//	string name;
//public:
//	Animal() {
//		cout << "I am default constructor of Animal";
//	}
//	Animal(string n) {
//		cout << "I am parametrized constructor of Animal";
//		name = n;
//	}
//	void setName(string n) {
//		name = n;
//	}
//	string getName() {
//		return name;
//	}
//	void sleep() {
//		cout << "I can sleep" << endl;
//	}
//	void eat() {
//		cout << "I can eat" << endl;
//	}
//};
//class Dog : public Animal {
//	string breed;
//public:
//	Dog() {
//		cout << "I am default constructor of Dog";
//	}
//	Dog(string b) {
//		cout << "I am parametrized (one) constructor of Dog";
//		breed = b;
//	}
//	Dog(string a, string b) :Animal(a) {
//		cout << "I am parametrized (two) constructor of Dog";
//		breed = b;
//	}
//	void setBreed(string b) {
//		breed = b;
//	}
//	string getBreed() {
//		return breed;
//	}
//	void bark() {
//		cout << "I can bark" << endl;
//	}
//};
//int main() {
//	Dog dog1("Tommy", "German Shephard"), dog2, dog3("labrador");
//	dog1.setName("Tommy");
//	cout << dog1.getName() << endl;
//	string s = "test";
//
//	//cout << s;
//	cout << dog1.getBreed() << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//class RECTANGLE
//{
//public:
//	RECTANGLE();
//	RECTANGLE(float, float);
//	~RECTANGLE();
//	float virtual calcArea()=0;
//	void virtual print();
//private:
//	float length, width,area;
//};
//
//RECTANGLE::RECTANGLE()
//{
//	length = 0; width = 0;
//}
//RECTANGLE::RECTANGLE(float l, float w) {
//	length = l;
//	width = w;
//
//}
//float RECTANGLE::calcArea(){
//	area = length * width;
//	return area;
//}
//void RECTANGLE::print() {
//	cout << "The length of the rectangle is " << length << endl;
//	cout << "The width of the rectangle is " << width << endl;
//	cout << "the area of rectangle is" << area << endl;
//}
//RECTANGLE::~RECTANGLE()
//{
//	cout << "\nHi from parent class\n";
//
//	print();
//}
//class SQUARE
//{
//public:
//	SQUARE();
//	SQUARE(float);
//	~SQUARE();
//
//private:
//
//};
//
//SQUARE::SQUARE()
//{
//}
//
//SQUARE::~SQUARE()
//{
//}
//Square::Square(float l) {
//right
//}
//int main() {
//	Square obj;
//}

#include<iostream>
using namespace std;
class MyClass
{
public:
	MyClass();
	~MyClass();

private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}