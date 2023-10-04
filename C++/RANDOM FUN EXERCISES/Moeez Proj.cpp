#include<iostream>
using namespace std;

class Birth {
public:
	Birth() { cout << "Birth constructor\n"; }
	~Birth(){ cout << "Birth destructor\n"; }
};
class People {
private:
	Birth b;
public:
	People() { cout << "People constructor\n"; }
	~People() { cout << "People destructor\n"; }
};
int main(){
	{
		People p;
	}
	return 0;
}