#include<iostream>
#include<string>
#include"Car.h"

using namespace std;


int main()
{
    Car grande("Civic",2022);
    int model;
    string make;

    model = grande.getYearModel();
    make = grande.getMake();
    cout << model << "\t\t" << make << endl;
    cout << "The speed of car is: " << grande.getSpeed() << endl;

    cout << endl << "Accelerating the car." << endl;
    for (int i = 1; i <= 5; i++) {
        grande.accelerate();
        cout << "The speed of car is: " << grande.getSpeed() << endl;
    }

    cout << endl << "Applying Brakes." << endl;
    for (int i = 1; i <= 5; i++) {
        grande.brake();
        cout << "The speed of car is: " << grande.getSpeed() << endl;
    }



    return 0;
}