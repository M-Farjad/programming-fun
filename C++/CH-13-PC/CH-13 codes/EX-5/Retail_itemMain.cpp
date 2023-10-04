#include<iostream>
#include"Retailitem.h"
#include<string>
using namespace std;

int main() {
    RetailItem item1("Hoodie", 6, 25.43);
    RetailItem item2("pent coat", 3, 70.22);
    RetailItem item3("sherwani", 5, 66.43);

    cout << "Item #1  " << item1.getDescription() << " " << item1.getUnitsOnHand() << " " << item1.getPrice() << endl;
    cout << "Item #1  " << item2.getDescription() << " " << item2.getUnitsOnHand() << " " << item2.getPrice() << endl;
    cout << "Item #1  " << item3.getDescription() << " " << item3.getUnitsOnHand() << " " << item3.getPrice() << endl;

    return 0;
}