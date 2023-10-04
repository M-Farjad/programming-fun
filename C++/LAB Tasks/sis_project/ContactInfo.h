
#include <cstring>			//for strcpy() and strlen() functions
#include<string>
using namespace std;
class Contactinfo
{
	char* name;
	char* phone;
public:
	Contactinfo(char* n, char* p)
	{
		cout << "called constructer";
		name = new char[strlen(n) + 1];
		cout << "\nworking";
		phone = new char[strlen(p) + 1];


		//we cannot copy an array of char directly just by writing
		//name = n;
		//phone = p;
		//just like we cannot assign an array the contents of 
		// an other array.
		//example 
		//array1=array2;

		//for doing this we use a special function named strcpy is used

		strcpy(name, n);
		strcpy(phone, p);
	}
	~Contactinfo()
	{
		delete[] name;
		delete[] phone;
	}
	const char* getName() const
	{
		return name;
	}
	const char* getPhoneNumber() const
	{
		return phone;
	}
};
