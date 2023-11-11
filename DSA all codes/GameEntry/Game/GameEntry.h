#pragma once
#include<iostream>
using namespace std;


class GameEntry { // a game score entry
public:
	GameEntry(const string& n = "", int s = 0); // constructor
	string getName() const;						// get player name
	int getScore() const;						// get score
private:
	string name;								// player’s name
	int score;									// player’s score
};
GameEntry::GameEntry(const string& n, int s) // constructor
	: name(n), score(s) { }
// accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }