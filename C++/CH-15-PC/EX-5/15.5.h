//class declarations
#include"Time.h"
//class Time
//{
// protected:
//	 int hour;
//	 int min;
//	 int sec;
// public:
//	 // Default constructor 
//		Time()
//		{ hour = 0; min = 0; sec = 0; }
//	
//		 // Constructor 
//		Time(int h, int m, int s)
//		{ hour = h; min = m; sec = s; }
//	
//		 // Accessor functions 
//		int getHour() const
//		 { return hour; }
//
//		int getMin() const
//		{ return min; }
//	
//		int getSec() const
//		{ return sec; }
//};

class MilTime:public Time
{
public:
	MilTime();
	~MilTime();

private:
	float milhrs,	/*Contains the hour in 24 - hour format.For example,
					  1 : 00 pm would be stored as 1300 hours and 4:30pm
					  as 1630hrs */
		  milsec;	//contains the seconds in standard format
public:
	MilTime(int,int);
};
class TimeClock:public MilTime
{
public:
	TimeClock();
	~TimeClock();

private:

};