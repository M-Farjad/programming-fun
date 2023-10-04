
#include <iostream>
using namespace std;

const int s = 3;           //it will be the number of subjects
class Student {
	float* Marks;			//for storing the subjects marks
	static int num;		//for calculating no of objects created
public:
	Student() {			//constructor
		num++;
		Marks = new float[s];	//it will declare array for subjects marks
		for (int i = 0; i < s; i++) {
			cout << "\nEnter marks of subject " << i + 1 << " of student " << num << ": ";
			cin >> *(Marks + i);
		}
	}
	float getMarks(int i) {
		return *(Marks + i);		//to return particular indexes marks
	}
	~Student() {
		delete[] Marks;
		Marks = nullptr;
	}
};
int Student::num = 0;
int main() {

	int size,		//for storing no of student objects
		index;		//for calculating particular subjects highest and average
	cout << "How many students you want to enter :";
	cin >> size;
	float sum = 0.0,
		avg = 0.0,
		highest = 0.0;

	Student* std = new Student[size];
	
	cout << "For which subject you want to calculate highest and average enter less than 3:  ";
	cin >> index;
	
	
	highest = std->getMarks(index);
	for (int i = 0; i < size; i++) {

		sum += (std + i)->getMarks(index);

		if (highest < (std + i)->getMarks(index)) {
			highest = (std + i)->getMarks(index);
		}
	}
	avg = sum / size;

	cout << "Highest marks in subject " << index << " are: " << highest << endl;
	cout << "Average marks in subject " << index << " are: " << avg << endl;



	delete[]std;
	std = nullptr;

	return 0;
}