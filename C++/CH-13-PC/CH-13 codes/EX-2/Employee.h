//class declarations
#include<string>
using namespace std;
class Employee 
{
private:
	//member variables
	string name;
	int id;
	string department;
	string position;
public: 
	//member functions
	Employee(string, int, string, string);
	Employee(string, int);
	Employee();
	void setName(string);
	void setId(int);
	void setDept(string);
	void setPosition(string);

	//inline accessors
	string getName()const {
		return name;
	}
	string getDept()const {
		return department;
	}
	int getId()const {
		return id;
	}
	string getPosition()const {
		return position;
	}
};
