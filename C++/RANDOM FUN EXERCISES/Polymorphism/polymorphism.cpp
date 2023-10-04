//#include <iostream>
//using namespace std;
//
//class Shape
//{
//public:
//    Shape() {
//
//    }
//    virtual void getArea() {
//        cout << "ab to jan chor dey error ";
//    }
//};
//class Rectangle : public Shape
//{
//private:
//    double len;
//    double wid;
//
//public:
//    Rectangle(double l = 0, double w = 0) :Shape()
//    {
//        len = l;
//        wid = w;
//    }
//    void getArea()
//    {
//        cout << "Rectangle Area is a : " << len * wid << endl;
//    }
//};
//class Square :public Shape
//{
//private:
//    double len;
//
//public:
//    Square(double l = 0) :Shape()
//    {
//        len = l;
//    }
//    void getArea()
//    {
//        cout << "Square Area is a : " << len * len << endl;
//    }
//};
//class Circle :public Shape
//{
//private:
//    double radius;
//
//public:
//    Circle(double r = 0) :Shape()
//    {
//        radius = r;
//    }
//    void getArea()
//    {
//        cout << "Circle Area is a : " << radius * radius * 3.142 << endl;
//    }
//};
//
//void fun1();
//void fun2();
//
//int main()
//{
//    fun1();
//    cout << endl << endl << endl;
//    fun2();
//
//}
//void fun1() {
//    const int arraySize = 6;
//
//    Square obj1(5.0);
//    Rectangle obj2(5.0, 5.0);
//    Circle obj3(5.0);
//
//    cout << "\n\nDisplay using Baser pointer : \n";
//    obj1.getArea();
//    obj2.getArea();
//    obj3.getArea();
//
//    // assining dervied class object addresses to base class pointer obj
//    Shape* shp1 = &obj1;
//    Shape* shp2 = &obj2;
//    Shape* shp3 = &obj3;
//
//    cout << "\n\nDisplay using Baser pointer : \n";
//    // Displaying output 
//    shp1->getArea();
//    shp2->getArea();
//    shp3->getArea();
//
//    // using pointers array .....
//    // storing diffrent drived classes address to one base class pointer array
//    Shape* shapes[arraySize] = {
//          new Rectangle(2,3),
//          new Square(2),
//          new Circle(3),
//          &obj1,
//          &obj2,
//          &obj3
//    };
//    // displaying its values
//    cout << "\n\nDisplay using  pointer  Array : \n";
//    for (int count = 0; count < arraySize; count++) {
//        shapes[count]->getArea();
//    }
//}
//void fun2()
//{
//    int choice;
//    int l, w, r;
//
//    // base class pointer 
//    Shape* obj;
//
//
//    // it will decide which Object have to be created 
//    cout << "Enter Object Type \n";
//    cout << "Rectangle : press 1 \n";
//    cout << "Square    : press 2 \n";
//    cout << "Circle    : press 3 \n";
//    cout << "Choice -> ";
//    cin >> choice;
//
//    // It will create the decide object . and assigned it address to base class
//    switch (choice)
//    {
//    case 1:
//        cout << "Making Rectangle OBj \n";
//
//        cout << "Enter Length of Rectangle: ";
//        cin >> l;
//        cout << "Enter Width of Rectangle : ";
//        cin >> w;
//        // dont do it like this due to Scope it will be destroyed;
//        //Shape *obj = new Rectangle(len,wid);
//        obj = new Rectangle(l, w);
//        break;
//    case 2:
//        cout << "Making Square OBj \n";
//        int l;
//        cout << "Enter Length of Square: ";
//        cin >> l;
//        obj = new Square(l);
//        break;
//
//    case 3:
//        cout << "Making Circle  OBj \n";
//        cout << "Enter Radius of Circle: ";
//        cin >> r;
//        obj = new Circle(r);
//        break;
//
//    default:
//        break;
//    }
//
//    // It will display the value of desired obj area
//    obj->getArea();
//
//}


//#include <iostream>
//using namespace std;
//
//class Shape
//{
//public:
//    Shape() {
//
//    }
//    virtual void getArea() {
//        cout << "ab to jan chor dey error ";
//    }
//};
//class Rectangle : public Shape
//{
//private:
//    double len;
//    double wid;
//
//public:
//    Rectangle(double l = 0, double w = 0) :Shape()
//    {
//        len = l;
//        wid = w;
//    }
//    void getArea()
//    {
//        cout << "Rectangle Area is a : " << len * wid << endl;
//    }
//};
//class Square :public Shape
//{
//private:
//    double len;
//
//public:
//    Square(double l = 0) :Shape()
//    {
//        len = l;
//    }
//    void getArea()
//    {
//        cout << "Square Area is a : " << len * len << endl;
//    }
//};
//class Circle :public Shape
//{
//private:
//    double radius;
//
//public:
//    Circle(double r = 0) :Shape()
//    {
//        radius = r;
//    }
//    void getArea()
//    {
//        cout << "Circle Area is a : " << radius * radius * 3.142 << endl;
//    }
//};
//
//void fun1();
//void fun2();
//
//int main()
//{
//    fun1();
//    cout << endl << endl << endl;
//    fun2();
//
//}
//void fun1() {
//    const int arraySize = 6;
//
//    Square obj1(5.0);
//    Rectangle obj2(5.0, 5.0);
//    Circle obj3(5.0);
//
//    cout << "\n\nDisplay using Baser pointer : \n";
//    obj1.getArea();
//    obj2.getArea();
//    obj3.getArea();
//
//    // assining dervied class object addresses to base class pointer obj
//    Shape* shp1 = &obj1;
//    Shape* shp2 = &obj2;
//    Shape* shp3 = &obj3;
//
//    cout << "\n\nDisplay using Baser pointer : \n";
//    // Displaying output 
//    shp1->getArea();
//    shp2->getArea();
//    shp3->getArea();
//
//    // using pointers array .....
//    // storing diffrent drived classes address to one base class pointer array
//    Shape* shapes[arraySize] = {
//          new Rectangle(2,3),
//          new Square(2),
//          new Circle(3),
//          &obj1,
//          &obj2,
//          &obj3
//    };
//    // displaying its values
//    cout << "\n\nDisplay using  pointer  Array : \n";
//    for (int count = 0; count < arraySize; count++) {
//        shapes[count]->getArea();
//    }
//}
//void fun2()
//{
//    int choice;
//    int l, w, r;
//
//    // base class pointer 
//    Shape* obj;
//
//
//    // it will decide which Object have to be created 
//    cout << "Enter Object Type \n";
//    cout << "Rectangle : press 1 \n";
//    cout << "Square    : press 2 \n";
//    cout << "Circle    : press 3 \n";
//    cout << "Choice -> ";
//    cin >> choice;
//
//    // It will create the decide object . and assigned it address to base class
//    switch (choice)
//    {
//    case 1:
//        cout << "Making Rectangle OBj \n";
//
//        cout << "Enter Length of Rectangle: ";
//        cin >> l;
//        cout << "Enter Width of Rectangle : ";
//        cin >> w;
//        // dont do it like this due to Scope it will be destroyed;
//        //Shape *obj = new Rectangle(len,wid);
//        obj = new Rectangle(l, w);
//        break;
//    case 2:
//        cout << "Making Square OBj \n";
//        int l;
//        cout << "Enter Length of Square: ";
//        cin >> l;
//        obj = new Square(l);
//        break;
//
//    case 3:
//        cout << "Making Circle  OBj \n";
//        cout << "Enter Radius of Circle: ";
//        cin >> r;
//        obj = new Circle(r);
//        break;
//
//    default:
//        break;
//    }
//
//    // It will display the value of desired obj area
//    obj->getArea();
//
//}


#include <iostream>
#include <iomanip>
#include "PassFailActivity.h"
using namespace std;

void displayGrade(const GradedActivity&);       //if we provide & then we will be use
                                                //using polymorphism otherwise polymorphism
//void displayGrade(const GradedActivity);      //will not work...
int main() {
    PassFailActivity test1p(70);
    test1p.setScore(72);
    GradedActivity test2g(72);
    displayGrade(test1p);
    cout << "*************************************\n";
    displayGrade(test2g);
    return 0;
}

void displayGrade(const GradedActivity& activity) {
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
        << activity.getScore() << endl;
    cout << "The activity's letter grade is "
        << activity.getLetterGrade() << endl;
}
