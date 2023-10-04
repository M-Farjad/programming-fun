#include <string> 
#include <iostream>

using namespace std; 

class InventoryItem{ 
    string name;                                         // The item description 
    double cost;                                         // The item cost 
    int units;                                           // Number of units on hand 
public: 
    // Constructor #1 
    InventoryItem(){
        name = "";
        cost = 0.0; 
        units = 0; 
    } 
 
    // Constructor #2 
    InventoryItem(string n){                            // Assign the value to name. 
        name = n;
        cost = 0.0; 
        units = 0; 
    } 
 
    // Constructor #3 
    InventoryItem(string n, double c, int u){            // Assign values to name, cost, and units. 
        name = n; 
        cost = c; 
        units = u; 
    } 
 
    // Mutator functions 
    void setName(string n) { 
        name = n; 
    }
 
    void setCost(double c) {
        cost = c; 
    } 
 
    void setUnits(int u){
        units = u;
    } 
    void minusQ(int u){
        units -= u;
    }
 
    // Accessor functions 
    string getName() const {
        return name; 
    } 
 
    double getCost() const{
        return cost; 
    } 
 
    int getUnits() const {
        return units; 
    } 
    
 }; 
class CashRegister{
    string itemName ;
    int quantityPurchased;
    double cost;
    float salesTaxRate;

public:
    //Default Constructor
    CashRegister(){
        itemName = "";
        quantityPurchased = 0;
        cost = 0.0;
        salesTaxRate = 6.0;
    }
    bool purchase(InventoryItem &obj , int q){
        itemName = obj.getName();
        if (obj.getUnits() < q){
            cout<<"Quantity: "<<obj.getUnits();
            cout<<"Quantity not available. "<<endl;
            return false;
        }
        else{
            obj.minusQ(q);
            quantityPurchased = q;
            cost = obj.getCost();
            return true;
        }
    }

    void setSalesTaxRate(float r){
        salesTaxRate = r;
    }
    string getItemName(){
        return itemName;
    }
    int getQuantityPurchased(){
        return quantityPurchased;
    }
    float getSalesTaxRate(){
        return salesTaxRate;
    }
    double getsubtotal(){
        return ( quantityPurchased * cost );
    } 
    double gettax(){
        return ( ( getsubtotal() * salesTaxRate ) / 100.0 );
    }
    double gettotal(){
        return ( getsubtotal() + gettax() );
    }
};

int main(){
    InventoryItem in[4] = {InventoryItem("Mouse", 400.0 , 50),
                        InventoryItem("Keyboard", 200.0 , 25),
                        InventoryItem("Mouse Pad", 250.0 , 15),
                        InventoryItem("Speaker", 1000.0 , 8)};
    
    CashRegister r1;
    
    int choice;
    int quantity = 0;

    do{

        for(int i = 0; i<4 ; i++){
            cout << i+1 <<"- "<< in[i].getName()<<endl;
        }
        cout<<"Enter choice ...";
        cin>>choice;
        if(choice < 1 || choice > 4 ){
            cout<<"Please Enter valid choice. "<<endl;
        }
        else {
            do {
                cout << "Enter quantity: ";
                cin >> quantity;
                if(quantity < 0){
                    cout<<"Please Enter valid quantity: "<<endl;
                }
            }while(quantity < 0);
            break;
        }
        
    }while(true);

    if(r1.purchase(in[choice-1] , quantity)){
        cout<<" ****************************** "<<endl;
        cout<<"Item: "<<r1.getItemName()<<endl;
        cout<<"Quantity: "<<r1.getQuantityPurchased()<<endl;
        cout<<"Subtotal: "<<r1.getsubtotal() << endl;
        cout<<"Tax: "<<r1.gettax()<<endl;
        cout<<"Total: "<< r1.gettotal()<<endl;
    }
    
    return 0;
}