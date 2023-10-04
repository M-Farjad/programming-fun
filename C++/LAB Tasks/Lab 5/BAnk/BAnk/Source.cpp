#include<iostream>
using namespace std;
class bankAccount {
	double balance;
public:
	bankAccount(double b) {
		balance = b;
	}
	bankAccount(bankAccount& acc) {
		balance = acc.balance;
	}
	void setbal(double b) {
		balance = b;
	}
	/*double getbal() const {
		return balance;
	}*/
	void display() {
		cout << "balance is:" << balance;
	}
};
int main() {
	bankAccount A1(10);
	cout << "the default \n";
	A1.display();
	double b;
	cout << "\nenter balance: ";
	cin >> b;
	A1.setbal(b);
	cout << "New balnace in first object is\n ";
	A1.display();
	cout << endl;
	/*bankAccount A2(A1);*/
	 bankAccount A2 = A1;
	cout << "New balnace in 2nd object is\n ";
	A2.display();
	return 0;
}