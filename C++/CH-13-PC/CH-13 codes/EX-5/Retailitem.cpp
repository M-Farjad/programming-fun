#include "Retailitem.h"
#include<string>
using namespace std;

    //member functions
    RetailItem::RetailItem(string d, int u, double p) {
        description = d;
        unitsOnHand = u;
        price = p;
    }
    void RetailItem::setDesciption(string d) {
        description = d;
    }
    void RetailItem:: setUnitsOnHand(int u) {
        unitsOnHand = u;
    }
    void RetailItem::setPrice(double p) {
        price = p;
    }
    string RetailItem::getDescription() {
        return description;
    }
    int RetailItem:: getUnitsOnHand() {
        return unitsOnHand;
    }
    double RetailItem::getPrice() {
        return price;
    }

