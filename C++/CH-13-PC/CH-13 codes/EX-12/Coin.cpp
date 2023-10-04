#include<iostream>
#include<string>
#include<ctime>    //to store the time
#include<cstdlib>  //for rand() and srand()
using namespace std;

class Coin     //coin class
{
private:
	string sideup;     // string to store the side of the coin that is facing up
	int value;
public:
	Coin();   //default constructor
	void toss();    //toss member fuction to determine upper side of coin
	string getsideup()const   //member function to return the sideup
	{
		return sideup;
	}
};

Coin::Coin()     //default constructor's defination
{
	unsigned seed = time(0);
	// Seed the random number generator. 
	srand(seed);
	//calling the toss function to determine the value of sideup
	toss();
}

void Coin::toss()
{
	int max, min;
	max = 1;
	min = 0;

	value = (rand() % (max - min + 1)) + min;

	if (value == 1)
	{
		sideup = "head";
	}
	else
		sideup = "tail";

}

int main() {
	int no_of_toss = 20;
	int count = 0;	//head count
	int tail;		//tail count
	Coin cointoss;

	cout << "The side that is initially up is " << cointoss.getsideup() << endl;

	for (int i = 0; i < no_of_toss; i++)
	{
		cointoss.toss();
		cout << "The side that is up is [" << cointoss.getsideup() << "]" << endl;

		if (cointoss.getsideup() == "head")
			count++;
	}

	tail = no_of_toss - count;

	cout << "\n\nThe number of heads are: " << count << endl;
	cout << "The number of tails are: " << tail << endl;

	return 0;
}