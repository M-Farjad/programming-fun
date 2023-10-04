//class declarations
#include <string>
using namespace std;

class RetailItem
{
    string description;
    int unitsOnHand;
    double price;

public:
    //member functions
    RetailItem(string, int, double);
    void setDesciption(string);
    void setUnitsOnHand(int);
    void setPrice(double);
    string getDescription();
    int getUnitsOnHand();
    double getPrice();


};