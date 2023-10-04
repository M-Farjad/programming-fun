////#include <iostream.> 
////using namespace std;
////class First
////{
////protected:
////	int a;
////public:
////	First(int x = 1)
////	{
////		a = x;
////	}
////	virtual int getVal()
////	{
////		return a;
////	}
////};
////class Second : public First
////{
////private:
////	int b;
////public:
////	Second(int y = 5)
////	{
////		b = y;
////	}
////	int getVal()
////	{
////		return b;
////	}
////};
////int main()
////{
////	First object1;
////	Second object2;
////
////	First* ptr = new Second;
////
////	cout << object1.getVal() << endl;
////	cout << object2.getVal() << endl;
////
////	cout<<ptr->getVal();
////
////	return 0;
////}
//
////#include <iostream> 
////using namespace std;
////class First
////{
////protected:
////	int a;
////public:
////	First(int x = 1)
////	{
////		a = x;
////	}
////	void twist()
////	{
////		a *= 2;
////	}
////	int getVal()
////	{
////		twist(); return a;
////	}
////};
////class Second : public First
////{
////private:
////	int b;
////public:
////	Second(int y = 5)
////	{
////		b = y;
////	}
////	void twist()
////	{
////		b *= 10;
////	}
////};
////int main()
////{
////	First object1;
////	Second object2;
////	cout << object1.getVal() << endl;
////	cout << object2.getVal() << endl;
////	return 0;
////}
//
////#include <iostream> 
////using namespace std;
////class First
////{
////protected:
////	int a;
////public:
////	First(int x = 1)
////	{
////		a = x;
////	}
////	virtual void twist()
////	{
////		a *= 2;
////	}
////	int getVal()
////	{
////		twist(); return a;
////	}
////};
////class Second : public First
////{
////private:
////	int b;
////public:
////	Second(int y = 5)
////	{
////		b = y;
////	}
////	virtual void twist()
////	{
////		b *= 10;
////	}
////};
////int main()
////{
////	First object1;
////	Second object2;
////	cout << object1.getVal() << endl;
////	cout << object2.getVal() << endl;
////	return 0;
////}
//
////#include <iostream> 
////using namespace std;
////class Base
////{
////protected:
////	int baseVar;
////public:
////	Base(int val = 2)
////	{
////		baseVar = val;
////	}
////	virtual int getVar()
////	{
////		return baseVar;
////	}
////};
////class Derived : public Base
////{
////private:
////	int derivedVar;
////public:
////	Derived(int val = 100)
////	{
////		derivedVar = val;
////	}
////	int getVar()
////	{
////		return derivedVar;
////	}
////};
////int main()
////{
////	Base* optr = nullptr;
////	Derived object;
////	optr = &object;
////	cout << optr->getVar() << endl;
////	return 0;
////}
//
//
//#include <iostream> 
//using namespace std;
//class First
//{
//protected:
//	int a;
//public:
//	First(int x = 1)
//	{
//		a = x;
//	}
//	void twist()
//	{
//		a *= 2;
//	}
//	int getVal()
//	{
//		twist(); return a;
//	}
//};
//class Second : public First
//{
//private:
//	int b;
//public:
//	Second(int y = 5)
//	{
//		b = y;
//	}
//	void twist()
//	{
//		b *= 10;
//	}
//};
//int main()
//{
//	First object1;
//	Second object2;
//	cout << object1.getVal() << endl;
//	cout << object2.getVal() << endl;
//	return 0;
//}

#include<iostream>
using namespace std;

class ClassA
{
public:
	ClassA();
	~ClassA();

private:
	int newint;
public:
	ClassA() {
		cout << "Class A's constructor"<<endl;
	}
	ClassA(const ClassA& obj) {
		cout << "ClassA's copy constructor\n";
	}
	ClassA& operator=(const ClassA& obj) {
		cout << "ClassA's assignment operator \n";
		return *this;
	}
	~ClassA() {
		cout << "ClassA's destructor\n";
	}

};

ClassA::ClassA()
{
}

ClassA::~ClassA()
{
}