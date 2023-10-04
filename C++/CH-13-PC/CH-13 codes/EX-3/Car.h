#include <string>
using namespace std;

class Car
{
private: 
//member variables 
	int yearModel;
	string Make;
	int speed;

public:
//member functions
	//mutators
	int accelerate();
	int brake();

	//constructor
	Car(string, int);
	
	//accessors
	string getMake();
	int getSpeed();
	int getYearModel();

};
