#include <iostream>
#include <string>

using namespace std;

class Inventory {
    int itemNumber,
        quantity;
    double cost,
        totalCost;

public:
    //constructors
    Inventory() {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
    }
    Inventory(int n, double c, int q) {
        itemNumber = n;
        quantity = q;
        cost = c;
        setTotalCost();
    }
    //Mutator functions
    void setItemumber(int n) {
        while (n < 0) {
            cout << "Please enter a positive Number: ";
            cin >> n;
        }
        itemNumber = n;
    }
    void setQuantity(int q) {
        while (q < 0) {
            cout << "Please enter a positive Number: ";
            cin >> q;
        }
        quantity = q;
    }
    void setCost(double c) {
        while (c < 0) {
            cout << "Please enter a positive Number: ";
            cin >> c;
        }
        cost = c;
    }
    void setTotalCost() {
        totalCost = (quantity * cost);
    }
    //accessor functions
    int getItemNumber() {
        return itemNumber;
    }
    int getQuantity() {
        return quantity;
    }
    double getCost() {
        return cost;
    }
    double getTotalCost() {
        return totalCost;
    }
};
int main() {

    Inventory a1;   // all values set to zero    

    Inventory a2(234, 25.7, 2);

    cout << "Details before parameterized constructor\n";
    cout << a1.getItemNumber() << " " << a1.getQuantity() << " " << a1.getCost() << " " << a1.getTotalCost() << endl;
   
    cout << "Details after parameterized constructor\n";
    cout << a2.getItemNumber() << " " << a2.getQuantity() << " " << a2.getCost() << " " << a2.getTotalCost() << endl;

    return 0;
}