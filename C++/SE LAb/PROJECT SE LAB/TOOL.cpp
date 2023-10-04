//class definitions
#include<iostream>
#include<string>

#include"TOOL.h"

using namespace std;

void TOOL::setStrength(int str) {
	strength = str;
}
bool TOOL::fight(TOOL &obj) {
	cout << "hi " << endl;
	return 0;
	/*if (Type == 'r' && obj.Type == 'p')
		obj.strength = strength * 2;
	else if (Type == 'r' && obj.Type == 's')
		strength = obj.strength * 2;
	else if (Type == 'p' && obj.Type == 's')
		obj.strength = strength * 2;
	else if (Type == 'p' && obj.Type == 'r')
		strength = obj.strength * 2;
	else if (Type == 's' && obj.Type == 'r')
		obj.strength = strength * 2;
	else if (Type == 's' && obj.Type == 'p')
		strength = obj.strength * 2;*/

	////int TemStrP, TemStrS, TemStrR;
	////if (Type == 'r' && obj.Type == 'p') {
	////	TemStrP = obj.strength;
	////	TemStrR = strength / 2;
	////	if (TemStrP < TemStrR)
	////		return true;
	////	else if(TemStrP>TemStrR)
	////		return false;
	////}
	////else if (Type == 'r' && obj.Type == 's') {
	////	TemStrS = obj.strength;
	////	TemStrR =strength * 2;
	////	if (TemStrS < TemStrR)
	////		return true;
	////	else if (TemStrS > TemStrR)
	////		return false;
	////}
	////else if (Type == 's' && obj.Type == 'p') {
	////	TemStrP = obj.strength;
	////	TemStrS = strength * 2;
	////	if (TemStrP < TemStrS)
	////		return true;
	////	else if (TemStrP > TemStrS)
	////		return false;
	////}
	////else if (Type == 's' && obj.Type == 'r') {
	////	TemStrR = obj.strength;
	////	TemStrS = strength / 2;
	////	if (TemStrS < TemStrR)
	////		return true;
	////	else if (TemStrS > TemStrR)
	////		return false;
	////}
}