#include <iostream>
#include <string>

using namespace std;

class RetailItem {
    string description ;
    int unitsOnHand;
    double price;
public:
    RetailItem(string d , int u, double p ){
        description = d;
        unitsOnHand = u;
        price = p; 
    }
    void setDesciption (string d){
        description = d;
    }
    void setUnitsOnHand (int u){
        unitsOnHand = u;
    }
    void setPrice(double p){
        price = p;
    }
    string getDescription(){
        return description;
    }
    int getUnitsOnHand(){
        return unitsOnHand;
    }
    double getPrice(){
        return price;
    }

};
int main(){
    RetailItem item1("Jacket", 12 , 59.95);
    RetailItem item2("Designer Jeans", 40 , 34.95);
    RetailItem item3("Shirt", 20 , 24.95);

    cout<<"Item #1  "<<item1.getDescription()<<" "<<item1.getUnitsOnHand()<<" "<<item1.getPrice()<<endl;
    cout<<"Item #1  "<<item2.getDescription()<<" "<<item2.getUnitsOnHand()<<" "<<item2.getPrice()<<endl;
    cout<<"Item #1  "<<item3.getDescription()<<" "<<item3.getUnitsOnHand()<<" "<<item3.getPrice()<<endl;

    return 0;
}