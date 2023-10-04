//#include<iostream>
//using namespace std;
//
//class Box {
//private:
//	int length, width, height, volume;
//public:
//	Box(int i = 0, int j = 0, int k = 0) {
//		length = i;
//		width = j;
//		height = k;
//	}
//	Box& fun1() {
//		cout << "function 1";
//		return *this;
//	}
//	void fun2() {
//		cout << "function 2";
//	}
//};
//int main() {
//	Box box1;
//	box1.fun1().fun2();
//}
//
//
//#include<iostream>
//using namespace std;
//class BankAccount {
//	int balance;
//public:
//	BankAccount(int i = 0) {
//		balance = i;
//	}
//	BankAccount& deposit(int balance) {
//		this->balance = this->balance + balance;
//		return *this;
//	}
//	void printBalance() {
//		cout << "the balance is: " << balance << endl;
//	}
//};
//
//int main() {
//	BankAccount myAccount;
//	myAccount.deposit(10).deposit(100).deposit(150).deposit(10000);
//
//	/*	myAccount.deposit(10);
//		myAccount.deposit(100);
//		myAccount.deposit(150);
//		myAccount.deposit(10000);
//		*/
//	myAccount.printBalance();
//}

//
//#include<iostream>
//#include <string>
//
//using namespace std;
//
//class Student {
//	//private
//	int age;
//	int* marks;			
//	string name;
//public:
//	Student() {
//		cout << "Hello";
//	}
//	Student(int a, string n) {
//		age = a;
//		name = n;
//	}
//	int getage()const
//	{
//		return age;
//	}
//	~Student() {
//		cout << "The End";
//	}
//};
//int main() {
//	Student std1(23, "Numan");
//	Student std2(std1);
//	cout << std2.getage();
//	return 0;
//}

//#include<iostream>
//#include <string>
//
//using namespace std;
//
//class Student {
//	//private
//	int age;
//	int* marks;
//	string name;
//public:
//	Student() {
//		cout << "Hello";
//	}
//	Student(int a, string n) {
//		age = a;
//		name = n;
//	}
//	int getage()const
//	{
//		return age;
//	}
//	~Student() {
//		cout << "The End";
//	}
//};
//int main() {
//	Student std1(23, "Numan");
//	Student std2(std1);
//	cout << std2.getage();
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Student {
//	int age;
//	int* rollNumber;
//public:
//	Student() {
//		rollNumber = new int();		
//	}
//
//	Student(const Student& obj)			
//	{
//		rollNumber = new int();
//		age = obj.age;
//		*rollNumber = *(obj.rollNumber);
//	}
//	void setAge(int a) {
//		age = a;
//	}
//	void setRollNumber(int r) {
//		*rollNumber = r;
//	}
//	void printData() {
//		cout << "age: " << age << " Roll Number: " << *rollNumber << endl;
//	}
//
//};
//
//int main() {
//	Student std1;
//	std1.setAge(18);
//	std1.setRollNumber(101);
//
//	//shallow copy
//	//Student std2 = std1;	 copy constructor
//	Student std2;
//	std2 = std1;			//assignment
//	std2.setRollNumber(580);
//
//	/*Student std2(std1);*/
//	//std2.printData();
//	std1.printData();
//	std2.printData();
//
//	return 0;
//}


