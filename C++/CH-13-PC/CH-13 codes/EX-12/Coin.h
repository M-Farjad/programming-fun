//class declarations
#include<string>
using namespace std;

class Coin
{
private:
	//member variables
	string sideUp;		//holds either head or tails
	char* ptr;
public:
	//member functions
	Coin();
	~Coin();
	void toss(char *);
	string getsideUp();

};