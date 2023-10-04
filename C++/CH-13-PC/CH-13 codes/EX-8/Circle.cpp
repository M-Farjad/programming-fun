#include<iostream>

using namespace std;

class Circle {
    double radius;
    double pi = 3.14159;
public:
    //Constructors
    Circle() {
        radius = 0.0;
    }
    Circle(double r) {
        radius = r;
    }
    //Mutators
    void setRadius(double r) {
        radius = r;
    }
    //Accessors
    double getRadius() {
        return radius;
    }
    double getArea() {
        return (pi * radius * radius);
    }
    double getDiameter() {
        return (2 * radius);
    }
    double getCircumferenece() {
        return (2 * pi * radius);
    }
};

int main() {
    double r;
    cout << "Enter the radius of the circle: ";
    cin >> r;
    Circle c1(r);

    cout << "The Radius is: " << c1.getRadius() << endl;
    cout << "The Area is: " << c1.getArea() << endl;
    cout << "The Diameter is: " << c1.getDiameter() << endl;
    cout << "The Circumference is: " << c1.getCircumferenece() << endl;

    return 0;
}