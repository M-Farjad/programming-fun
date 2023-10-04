#include"TOOL.h"
#include<iostream>

using namespace std;

//class declarations for SCISSORS

class SCISSORS :public TOOL
{
public:
	SCISSORS(int);
	~SCISSORS();
	bool fight(TOOL&);
private:

};
bool SCISSORS::fight(TOOL& obj) {
	cout << "HI Paper" << endl;
	return true;
}
SCISSORS::SCISSORS(int str)
{
	strength = str;
	Type = 's';
}

SCISSORS::~SCISSORS()
{
}