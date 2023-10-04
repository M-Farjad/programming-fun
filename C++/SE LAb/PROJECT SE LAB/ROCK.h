#include"TOOL.h"

//Rock class declarations

class ROCK : public TOOL
{
public:
	ROCK(int);
	bool fight(TOOL& obj);
private:

};

ROCK::ROCK(int str)
{
	strength = str;
	Type = 'r';
}
bool ROCK::fight(TOOL& obj) {
	cout << "HI Paper" << endl;
	return true;
}
//bool ROCK::fight(TOOL &obj){
//	int TemStrP, TemStrS, TemStrR;
//	if (Type == 'r' && obj.Type == 'p') {
//		TemStrP = obj.strength;
//		TemStrR = strength / 2;
//		if (TemStrP < TemStrR)
//			return true;
//		else if (TemStrP > TemStrR)
//			return false;
//	}
//	else if (Type == 'r' && obj.Type == 's') {
//		TemStrS = obj.strength;
//		TemStrR = strength * 2;
//		if (TemStrS < TemStrR)
//			return true;
//		else if (TemStrS > TemStrR)
//			return false;
//	}
//	else if (Type == 's' && obj.Type == 'p') {
//		TemStrP = obj.strength;
//		TemStrS = strength * 2;
//		if (TemStrP < TemStrS)
//			return true;
//		else if (TemStrP > TemStrS)
//			return false;
//	}
//	else if (Type == 's' && obj.Type == 'r') {
//		TemStrR = obj.strength;
//		TemStrS = strength / 2;
//		if (TemStrS < TemStrR)
//			return true;
//		else if (TemStrS > TemStrR)
//			return false;
//	}
//}
// 