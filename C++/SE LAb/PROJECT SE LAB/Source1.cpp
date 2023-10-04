#include<iostream>
#include<string>

using namespace std;

///////////////////////////////////////////////////


//Class declarations
class TOOL {
public:
	TOOL(int, char);
	TOOL(int);
	void setStrength(int);
	virtual bool fight(TOOL&);
protected:
	int strength;
	char Type;
};
TOOL::TOOL(int a = 0, char c = 0) {
	strength = a;
	Type = c;
}

TOOL::TOOL(int str) {
	strength = str;
	cout << "\nTOOL 1 para constructor...!\n";
	Type = ' ';
}


void TOOL::setStrength(int str) {
	strength = str;
}
bool TOOL::fight(TOOL& obj) {
	float temp1 = 0, temp2 = 0;
	cout << "\nFIGHT STARTED\n";
	if (Type == 'r' && obj.Type == 's') {
		cout << "\nRock -> scissors\n";
		temp2 = obj.strength;
		temp1 = (float)this->strength * 2;
	}
	else if (Type == 'r' && obj.Type == 'p') {
		cout << "\nRock -> papers\n";
		temp2 = obj.strength;
		temp1 = (float)this->strength / 2;
	}
	else if (Type == 's' && obj.Type == 'r') {
		cout << "\nscissors -> rock\n";
		temp2 = obj.strength;
		temp1 = this->strength / 2;
	}
	else if (Type == 's' && obj.Type == 'p') {
		cout << "\nscissors -> paper\n";
		temp2 = obj.strength;
		temp1 = this->strength * 2;
	}
	else if (Type == 'p' && obj.Type == 'r') {
		cout << "\nPaperss -> Rock\n";
		temp2 = obj.strength;
		temp1 = this->strength * 2;
	}
	else if (Type == 'p' && obj.Type == 's') {
		cout << "\nPApers -> scissors\n";
		temp2 = obj.strength;
		temp1 = this->strength / 2;
	}
	//else
	//{
	//	cout << "There is an error ...!";
	//	cout << " ENDING the program...!";
	//	exit(EXIT_SUCCESS);
	//}
	if (temp1 > temp2)
		return true;
	else if (temp1 < temp2)
		return false;
	else
	{
		cout << "ab to jaan chor de";
		cout << "oooh there is a tie";
	}
}


class ROCK : public TOOL
{
public:
	ROCK(int);
};

ROCK::ROCK(int str)
{
	strength = str;
	Type = 'r';
}

class PAPER :public TOOL
{
public:
	PAPER(int);
};
PAPER::PAPER(int str)
{
	strength = str;
	Type = 'p';
}

class SCISSORS :public TOOL
{
public:
	SCISSORS(int);
};
SCISSORS::SCISSORS(int str)
{
	strength = str;
	Type = 's';
}

///////////////////////////////////////////////////
using namespace std;

int main() {

	// Example main functionj
	// You may add your own testing code if you like

	SCISSORS s1(5);
	PAPER p1(7);
	ROCK r1(15);


	cout << s1.fight(p1) << p1.fight(s1) << endl;
	cout << p1.fight(r1) << r1.fight(p1) << endl;
	cout << r1.fight(s1) << s1.fight(r1) << endl;

	return 0;


}