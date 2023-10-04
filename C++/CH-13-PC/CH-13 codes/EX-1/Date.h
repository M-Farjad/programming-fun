//class definitions
#include<string>
class Date
{
private:
	//member variables
	int day, year;
	int month;
public:
	//member functions
	void setday(int);
	void setmonth(int mon);
	void setyear(int);
	void getdate()const;
	/*string inputMonth();  */                  //to store month in specific format
};