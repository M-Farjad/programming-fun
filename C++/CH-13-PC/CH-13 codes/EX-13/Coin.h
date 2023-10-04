#include <iostream>
#include<string>
using namespace std;


class Coin     //coin class
{
private:
	string sideup;     // string to store the side of the coin that is facing up
	float balance;		//for object's balance
	int value;			//will be used for random number generator
public:
	Coin();   //default constructor
	void toss();    //toss member fuction to determine upper side of coin
	string getsideup()const   //member fuction to store return the sideup
	{
		return sideup;
	}
	float getbalance() const {
		return balance;
	}
};