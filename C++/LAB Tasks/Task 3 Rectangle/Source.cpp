#include <iostream>
#include<string>
using namespace std;
class Rectangle {
	double length;
	double width;
	double height;
public:
	Rectangle(double l,double w,double h) {
		length = l;
		width = w;
		height = h;
	}
	double getLength() {
		return length;
	}
	double getWidth() {
		return width;
	}
	double getHieght() {
		return height;
	}
	double getVolume() {
		return height * width * length;
	}
};
int main() {
	double len, wid, h;
	cout << "Enter length,width,height comma separated:  ";
	cin >> len >> wid >> h;
	Rectangle r(len, wid, h);
	cout << "Length is :"<<r.getLength() << endl;
	cout << "width is: " << r.getWidth() << endl;
	cout << "Height is: " << r.getHieght() << endl;
	cout << "Volume is : " << r.getVolume() << endl;
	return 0;
}