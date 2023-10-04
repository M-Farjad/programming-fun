//#include <iostream>
//using namespace std;
//class Square {
//	int length;
//public:
//	void setLength(int i) {
//		length = i;
//	}
//	int getLength() {
//		return length;
//	}
//	Square operator + (Square& obj) {
//		Square sq;
//		sq.length = this->length + obj.length;
//		return sq;
//	}
//	friend Square operator - (Square& leftObj, Square& rightObj);
//	friend ostream& operator << (ostream& output, Square& obj);
//};
//
//Square operator - (Square& leftObj, Square& rightObj) {
//	Square sq;
//	sq.length = leftObj.length - rightObj.length;
//	return sq;
//}
//
//ostream& operator << (ostream& output, Square& obj) {
//	output << obj.length;
//	return output;
//}
//
//int main() {
//	Square sq1, sq2;
//
//	sq1.setLength(10);
//	sq2.setLength(15);
//
//	Square sq3;
//	sq3 = sq1 + sq2;
//
//	cout <<sq3<<endl;
//
//	Square sq4;
//	sq4 = sq2 - sq1;
//
//	cout << sq4 << endl;
//
//	return 0;
//}
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<conio.h>
using namespace std;

const int DEFAULT_SCORE = 0;
class StudentTestScores
{
public:
	StudentTestScores(string, int);
	~StudentTestScores();
	StudentTestScores(const StudentTestScores&);
	void setTestScore(float score, int index)
	{
		testScores[index] = score;
	}
	void setStudentName(string name)
	{
		std_name = name;
	}
	string getStudentName() const
	{
		return std_name;
	}
	int getNumTestScores() const
	{
		return numTestScores;
	}
	double getTestScore(int index) const
	{
		return testScores[index];
	}
	void printData() {
		cout << endl;
		for (int i = 0; i < numTestScores; i++)
		{
			cout << testScores[i];
			cout << endl;
		}
	}
	StudentTestScores() {

	}
	void operator=(const StudentTestScores& right)
	{
		//delete[] testScores;
		std_name = right.std_name;
		numTestScores = right.numTestScores;
		testScores = new float[numTestScores];
		for (int i = 0; i < numTestScores; i++)
		{
			testScores[i] = right.testScores[i];
		}
	}
private:
	string std_name;
	float* testScores;
	int numTestScores;
	static int objCount;
	void createTestScoresArray(int size)
	{
		numTestScores = size;
		testScores = new float[size];
		for (int i = 0; i < size; i++)
		{
			testScores[i] = DEFAULT_SCORE;
		}
	}

};
int StudentTestScores::objCount = 1;
StudentTestScores::StudentTestScores(string name, int scores)
{
	std_name = name;
	createTestScoresArray(scores);
}

StudentTestScores::StudentTestScores(const StudentTestScores& obj) {
	std_name = obj.std_name;
	numTestScores = obj.numTestScores;
	testScores = new float[numTestScores];
	for (int i = 0; i < numTestScores; i++)
		testScores[i] = obj.testScores[i];
}
StudentTestScores::~StudentTestScores()
{
	delete[] testScores;
}
int main() {
	string name; int num_tests; float score;
	cout << "Enter the name of student : ";
	cin >> name;
	cout << "Enter the no of tests : ";
	cin >> num_tests;
	StudentTestScores obj1(name, num_tests);
	for (int i = 0; i < num_tests; i++)
	{
		cout << "Enter the score " << i + 1 << " for std: ";
		cin >> score;
		obj1.setTestScore(score, i);
	}
	cout << "\nPrinting obj1's data before copying\n";
	obj1.printData();
	StudentTestScores obj2;
	obj2 = obj1;
	cout << "\nPrinting obj2's data\n";
	obj2.printData();

	obj1.setTestScore(90, 0);
	cout << "\nPrinting obj1's data after changing\n";
	obj1.printData();
	cout << "\nPrinting obj2's data after changing\n";
	obj2.printData();
	return 0;
}
