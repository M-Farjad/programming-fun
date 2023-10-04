#include <iostream>
#include "Coin.h"
#include <string>
using namespace std;

int main() {
	unsigned seed = time(0);
	// Seed the random number generator. 
	srand(seed);
	//calling the toss fuction to determine the value of sideup
	Coin quarter, dime, nickel;
	float Q=0,
		D=0,
		N=0;
		int count = 1;
		cout << "initial balances are\n";
		cout << Q << "$" << endl << D << "$" << endl << N << "$" << endl;
	for (bool i = true; i != false;) {
		quarter.toss();
		dime.toss();
		nickel.toss();
		if (quarter.getsideup() == "head")
			Q += 0.25;
		if (dime.getsideup() == "head")
			D += 0.25;
		if (nickel.getsideup() == "head")
			N += 0.25;

		cout << "After " << count << " no of tosses balances are\n";
		cout << Q <<"$" << endl << D <<"$" << endl << N <<"$" << endl;
		count++;
		cout << endl << endl;

		if (Q >= 1)
		{
			if (Q > 1 && D <= 1 && N <= 1) {
				cout << "1st object lost";
				i = false;
				continue;
			}

			else if (Q = 1 && D < 1 && N < 1) {
				cout << "\n1st object won"; i = false;
				continue;
			}
		}
		if (D >= 1)
		{
			if (D > 1 && Q <= 1 && N <= 1) {
				cout << "2nd object lost"; i = false;
				continue;
			}

			else if (D = 1 && Q < 1 && N < 1) {
				cout << "\n2nd object won"; i = false; continue;
			}
		}
		if (N >= 1)
		{
			if (N > 1 && D <= 1 && Q <= 1) {
				cout << "3rd object lost"; i = false; continue;
			}

			else if (N = 1 && D < 1 && Q < 1) {
				cout << "\n3rd object won";
				i = false;
				continue;
			}
		}
	}
	return 0;
}