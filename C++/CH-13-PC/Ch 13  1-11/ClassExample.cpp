#include<iostream>
using namespace std;
class Student{
	int *rollNumber;
public:
	Student(int i=0){
		rollNumber = new int();
		*rollNumber = i;
	}
	Student(const Student &obj){
		rollNumber = new int();
		*rollNumber = *(obj.rollNumber);
	}
	~Student(){
		delete rollNumber;
	}
	void setRollNumber(int i){
		*rollNumber = i;
	}
	int getRollNumber(){
		return *rollNumber;
	}
	void operator = (Student &ob){
		
		*rollNumber = *(ob.rollNumber);
	}
};

int main(){
	{
		Student std1(5);
		Student std2;
		Student std3(std1);
		cout << std1.getRollNumber() << endl;
		cout << std3.getRollNumber() << endl;

		std1.setRollNumber(10);

		cout << std1.getRollNumber() << endl;
		cout << std3.getRollNumber() << endl;

		std3 = std2;
        
		cout << std3.getRollNumber() << endl;
	}
	
	return 0;
}