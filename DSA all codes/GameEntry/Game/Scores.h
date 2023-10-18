#pragma once
#include"GameEntry.h"
#include<iostream>
using namespace std;
class Scores { // stores game high scores
public:
	Scores(int maxEnt = 10); // constructor
	~Scores(); // destructor
	void add(const GameEntry& e); // add a game entry
	GameEntry remove(int i) // remove the ith entry
		throw(out_of_range);
private:
	int maxEntries; // maximum number of entries
	int numEntries; // actual number of entries
	GameEntry* entries; // array of game entries
};
Scores::Scores(int maxEnt) { // constructor
	maxEntries = maxEnt; // save the max size
	entries = new GameEntry[maxEntries]; // allocate array storage
	numEntries = 0; // initially no elements
}
Scores::~Scores() { // destructor
	delete[] entries;
}
void Scores::add(const GameEntry& e) { // add a game entry
	int newScore = e.getScore(); // score to add
	if (numEntries == maxEntries) { // the array is full
		if (newScore <= entries[maxEntries-1].getScore())
			return; // not high enough - ignore
	}
	else numEntries++; // if not full, one more entry
	int i = numEntries-2; // start with the next to last
	while (i >= 0 && newScore > entries[i].getScore()) {
		entries[i + 1] = entries[i]; // shift right if smaller
		i--;
	}
	entries[i + 1] = e; // put e in the empty spot
}
GameEntry Scores::remove(int i) throw(out_of_range) {
	if ((i < 0) || (i >= numEntries)) // invalid index
		throw out_of_range("Invalid index");
	GameEntry e = entries[i]; // save the removed object
	for (int j = i + 1; j < numEntries; j++)
		entries[j-1] = entries[j]; // shift entries left
	numEntries--; // one fewer entry
	return e; // return the removed object
}
void insertionSort(char* A, int n) { // sort an array of n characters
	for (int i = 1; i < n; i++) { // insertion loop
		char cur = A[i]; // current character to insert
		int j = i - 1; // start at previous character
		while ((j >= 0) && (A[j] > cur)) { // while A[j] is out of order
			A[j + 1] = A[j]; // move A[j] right
			j--; // decrement j
		}
		A[j + 1] = cur; // this is the proper place for cur
	}
}
GameEntry Scores::remove(int i) throw(out_of_range) {
	if ((i < 0) || (i >= numEntries)) // invalid index
		throw out_of_range("Invalid index");
	GameEntry e = entries[i]; // save the removed object
	for (int j = i + 1; j < numEntries; j++)
		entries[j-1] = entries[j]; // shift entries left
	numEntries--; // one fewer entry
	return e; // return the removed object
}
void insertionSort(char* A, int n) { // sort an array of n characters
	for (int i = 1; i < n; i++) { // insertion loop
		char cur = A[i]; // current character to insert
		int j = i - 1; // start at previous character
		while ((j >= 0) && (A[j] > cur)) { // while A[j] is out of order
			A[j + 1] = A[j]; // move A[j] right
			j--; // decrement j
		}
		A[j + 1] = cur; // this is the proper place for cur
	}
}
