#include <iostream>
using namespace std;

const int ROW = 3;
const int COL = 4;

class Gauss_LAW
{
public:
	Gauss_LAW();
	~Gauss_LAW();
	void EnterVal();
	void SWAP1();
	void findHighest(int, int,int);
private:
	int matrix[ROW][COL];
	int highest;
};
void Gauss_LAW::EnterVal() {
	cout << "******************Gauss Elimination Law**********************" << endl;
	for (int i = 0; i < ROW; i++) 
	{
		for (int j = 0; j < COL; j++) {
			cout << "\nEnter the value in [" << ROW << "][" << COL << "] : ";
			cin >> matrix[i][j];
		}
	}
}
void Gauss_LAW::SWAP1() {
	int a, b, c;
	a = matrix[0][0];
	b = matrix[1][0];
	c = matrix[2][0];
	findHighest(a,b,c);
}
Gauss_LAW::Gauss_LAW()
{
	EnterVal();
}
void Gauss_LAW::findHighest(int a,int b,int c) {
	if (a > b) {
		if (a < c)
			highest = c;
		else
			highest = a;
	}
	else
	{
		if (b > c)
			highest = b;
		else
			highest = c;
	}
}
Gauss_LAW::~Gauss_LAW()
{
}