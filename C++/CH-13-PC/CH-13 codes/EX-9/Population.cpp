#include<iostream>

using namespace std;

class Population {
    double population;
    double noOfDeath;
    double noOfBirth;

public:
    //Mutators
    void setPopulation(double r) {
        while (r < 1) {
            cout << "Please Enter a number greater than 1: ";
            cin >> r;
        }
        population = r;
    }
    void setNoOfBirth(double r) {
        while (r < 0) {
            cout << "Please Enter a number greater than 1: ";
            cin >> r;
        }
        noOfBirth = r;
    }
    void setNoOfDeath(double r) {
        while (r < 0) {
            cout << "Please Enter a number greater than 1: ";
            cin >> r;
        }
        noOfDeath = r;
    }
    //Accessors
    double getBirthRate() {
        return (noOfBirth / population);
    }
    double getBirthDeath() {
        return (noOfDeath / population);
    }
};

int main() {

    return 0;
}