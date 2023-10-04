#include<iostream>
#include<math.h>
#include<ctime>
#include<cstdlib>
using namespace std;
class fishing
{
	string fish_name;
	int side;
public:
	fishing()                   //Default Constructors
	{
		side = 0;
		srand(time(0));	
	}
	

	void findFish() {   
		side = rand() % 6 + 1;
		if (side == 1)
		{
			fish_name = "Star Fish";
		}
		else if (side == 2)
		{
			fish_name = "Dolphin";
		}
		else if (side == 3)
		{
			fish_name = "GoldFish";
		}
		else if (side == 4)
		{
			fish_name = "Zebra Fish";
		}
		else if (side == 5)
		{
			fish_name = "Bluefish";
		}
		else if (side == 6)
		{
			fish_name = "Turbot Fish";
		}
	}

	//Accessor Functions
	int getSide() {
		return side;
	}
	string getName()
	{
		return fish_name;
	}
};
int main()
{
	float score = 0;
	fishing fish1;
	int temp;								//for storing the side of dice
	char choice;							//for yes no choice to continue
	do {
		fish1.findFish();
		cout << "You caught " << fish1.getName() << " fish." << endl;
		temp = fish1.getSide();             // return the side of dice 
		if (temp == 1)
		{
			score = score + 2;				//star fish score 
		}
		else if (temp == 2)
		{
			score = score + 0.25;        //dolphin score
		}
		else if (temp == 3)
		{
			score = score + 1;				//goldfish score
		}
		else if (temp == 4)
		{
			score = score + 0.75;			//zebra fish score
		}
		else if (temp == 5)
		{
			score = score + 0.5;			//bluefish score
		}
		else if (temp == 6)
		{
			score = score + 0.25;			//turbot fish score
		}

		cout << "Enter 'Y' to continue Fishing and 'N' to stop: ";
		cin >> choice;

	} while (choice == 'y' || choice == 'Y');

	cout << "Congratulations! You earned " << score << "  points." << endl;

	return 0;
}