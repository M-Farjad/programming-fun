#include <iostream>
using namespace std;

const int s=3;
class Student {
	float *Marks;
	static int number_std;
public:
	Student() {
		number_std++;
		Marks = new float[s];
		for (int i = 0; i < s; i++) {
			cout << "\nEnter marks " << i + 1 << " of student # "<<number_std<<": ";
			cin >> *(Marks + i);
		}
	}
	float findHighest() {
		float highest = *(Marks+0);
		for (int i = 1; i < s; i++) {
			if (highest<= *(Marks+i))
				highest = *(Marks + i);
			else
				continue;
		}
		return highest;
	}
	float findAverage() {
		float avg,total=0;
		for (int i = 0; i < s; i++) {
			total += *(Marks + i);
		}
		avg = total / s;
		return avg;
	}
	~Student() {
		delete [] Marks;
	}
};
int Student:: number_std = 0;
int main() {
	int size;
	cout << "How many students you want to enter :";
	cin >> size;
	float avg,highest;

	Student *std = new Student[size];
	cout << "Enter any key to calculate highest and average: ";
	cout << "\n\n=========================================\n\n";
	for (int i = 0; i < size; i++) { 
		highest = (std + i)->findHighest();
		avg = (std+i)->findAverage();
		cout << "average for student " << i + 1 <<" is : \t " << avg << endl;
		cout << "highest for student " << i + 1 << " is:\t " << highest << endl;
		cout << "\n\n=========================================\n\n";
	}

	delete []std;
	std = nullptr;

	return 0;
}