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
	string getsideup()const   //member fuction to store return the sideup
	{
		return sideup;
	}
};

Coin::Coin()     //default constructor's defination
{
	srand(time(0));
	toss();          //calling the toss fuction to determine the value of sideup
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

int main(){
    float balance = 0.0;
	int count = 0;
	int tail = 0;
	Coin quarter , dime , nickel;

    while( balance < 1.0 ){               //when balance reach $1.0 loop will break
        quarter.toss(); 
        if( quarter.getsideup() == "head"){
            balance += 0.25;
        }
        dime.toss();
        if( quarter.getsideup() == "head"){
            balance += 0.25;
        }
        nickel.toss();
        if( quarter.getsideup() == "head"){
            balance += 0.25;
        }
    }
	if(balance > 1.0){
        cout << endl <<"You loss. your balance is: " << balance;
    }
    else{
        cout<<"Congratulatons....You win the game. ";
    }

    return 0;
}