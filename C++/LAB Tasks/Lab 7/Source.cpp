#include <iostream>
#include<string>
using namespace std;

class IDgenerater {
	static int Id;
	string name;
public:
	IDgenerater() {
		/*Id=setID();*/
		cout << "\nEnter the name : ";
		cin >> name;
	}
	static void getID() {
		Id++;
	}
	void print() {
		cout << "\t" << Id << "\t" << name << endl;
	}
};
int IDgenerater::Id = 0;
int main() {
	int N_Std;
	cout << "Enter the no of students to assign id: ";
	cin >> N_Std;
	IDgenerater* std = new IDgenerater[N_Std];
	cout << "=============================\n";
	cout << "\tID\tNAME\n";
	for (int i = 0; i < N_Std; i++) {
		std->getID();
		std[i].print();
	}
	delete [] std;
	std = nullptr;
}