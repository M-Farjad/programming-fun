//#include<iostream>
//using namespace std;
//
//class Box {
//private:
//	int length, width, height, volume;
//public:
//	Box(int i = 0, int j = 0, int k = 0) {
//		length = i;
//		width = j;
//		height = k;
//	}
//	Box& fun1() {
//		cout << "function 1";
//		return *this;
//	}
//	void fun2() {
//		cout << "function 2";
//	}
//};
//int main() {
//	Box box1(44, 4, 5);
//	box1.fun1().fun1().fun1().fun2();
//}


#include <iostream>
#include<string>
using namespace std;

class Package {
	int value;
public:
	Package()
	{
		value = 7; cout << value << endl;
	}
	Package(int v) {
		value = v; cout << value<<endl;
	}
	~Package() {
		cout << value << endl;
	}
};

int main() {
	Package obj1(5);
	Package obj2();
	Package obj3(2);
	return 0;
}
