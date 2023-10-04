#include <iostream>
#include"Car.h"
#include <string>

using namespace std;

Car::Car(string make, int model) {
	Make = make;
	yearModel = model;
	speed = 0;
}
string Car::getMake() {
	return Make;
}
int Car::getSpeed() {
	return speed;
}
int Car::getYearModel() {
	return yearModel;
}
int Car::accelerate() {
	speed += 5;
	return speed;
}
int Car::brake() {
	speed -= 5;
	return speed;
}