//class declarations
#include<string>
#include<iostream>
using namespace std;
class PersonalInfo
{
private:
	//member variables
	string name;
	string address;
	int Age;
	long phoneNo;
public:
	//member functions
	//mutators
	void setdata(string, string, int, long);

	//accessors
	void getdata();
	
};