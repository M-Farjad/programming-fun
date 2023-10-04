#include<iostream>
using namespace std;
class rectangle {
private:
	float height;
	float width;
	float area;
public:
	
	float getarea(float h, float w) {
		area = h * w;
		return area;
	}
	void setHeight(float h) {
		height = h;
	}
	void setWidth(float w) {
		width = w;
	}
	void display() {
		cout << "area of rectangle is:" << area;
	}
};
int main() {
	rectangle box1, box2;
	float h,w;
	cout << "Enter height : ";
	cin >> h;
	box1.setHeight(h);
	cout << "Enter width : ";
	cin >> w;
	box1.setHeight(w);
	box1.getarea(h,w);
	cout << "first ";
	box1.display();
	cout << endl;
	cout << "second ";

	box2 = box1;
	box2.display();

	return 0;
}