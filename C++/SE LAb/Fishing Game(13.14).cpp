#include<iostream>
#include<cstdlib>   //For rand and srand 
#include<ctime>     //For time Function
#include<string>
using namespace std;

//Declaration of Class
class Die {
private:
	int sides;
	int value;
public:
	Die(int = 6);
	void roll();
	int getSides() { return sides; }
	int getValue() { return value; }
};

//Defining Class Functions
Die::Die(int numSides) {
	sides = numSides;
	//Get the system time
	unsigned seed = time(0);
	//Seed the random number generator
	srand(seed);
	roll();
}
void Die::roll() {
	const int MIN_VALUE = 1;
	//Get a random value for the die
	value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
}


//Globally creating Variable for class
const int SIDES = 6;
Die fishing(SIDES);

//Functions Prototype
string collectItems();
int countPoints();
void showResult(int);

int main() {
	char choice;
	int points = 0;
	int round = 1;
	do {
		cout << "Welcome to ROUND " << round << endl;
		points += countPoints();
		cout << "*******************" << endl;
		cout << "*******************" << endl;
		cout << "ROUND " << round << " completed successfully" << endl;
		round++;
		cout << "Press 'Y' to continue fishing.";
		cin >> choice;
		cout << endl << endl;
	} while (choice == 'Y' || choice == 'y');
	showResult(points);
}


//Functions Definition
string collectItems() {
	int value;
	string items;
	fishing.roll();
	value = fishing.getValue();
	//cout << "Value is: " << value << endl;
	switch (value) {
	case 1: items = "a huge fish";
		break;
	case 2: items = "an old shoe";
		break;
	case 3: items = "a small fish";
		break;
	case 4: items = "a shopping bag";
		break;
	case 5: items = "an older dress";
		break;
	case 6: items = "a doll";
		break;
	default:
		break;
	}
	return items;
}

void showResult(int points) {
	if (points > 90) {
		cout << "You got " << points << " points." << endl;
		cout << "Sara time game hi khelni hai kya?? books b khool lo" << endl;
	}
	else if (points > 60) {
		cout << "You got " << points << " points." << endl;
		cout << "SHABASH" << endl;
	}
	else {
		cout << "You got " << points << " points." << endl;
		cout << "Ab itny marks py tmhy kya comments du??" << endl;
	}
}


int countPoints() {
	string item = collectItems();
	cout << "Hey! You have caught " << item << endl;
	int points = 0;
	if (item == "a huge fish")
		points = 15;
	else if (item == "an old shoe")
		points = 10;
	else if (item == "a small fish")
		points = 8;
	else if (item == "a shopping bag")
		points = 6;
	else if (item == "an older dress")
		points = 5;
	else if (item == "a doll")
		points = 15;
	//cout << "You got points " << points << endl;

	return points;
}