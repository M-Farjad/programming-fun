#include"TOOL.h"
#include <iostream>

using namespace std;

//PAPER class declarations

class PAPER :public TOOL
{
public:
	PAPER(int);
	~PAPER();
	bool fight(TOOL&);
private:

};

bool PAPER::fight(TOOL& obj) {
	cout << "HI Paper" << endl;
	return true;
}
PAPER::PAPER(int str)
{
	strength = str;
	Type = 'p';
}

PAPER::~PAPER()
{
}