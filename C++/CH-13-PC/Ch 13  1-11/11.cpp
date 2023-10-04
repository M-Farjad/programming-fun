#include <iostream>
using namespace std;

class PayRoll
{
    int noOfHoursWorked;
    double hourlyPayRate;
public:
    //Mutator
    void setNoOfHoursWorked(int a){
        while (a > 60){
            cout<<"Enter a value less than 60: ";
            cin >> a;
        }
        noOfHoursWorked = a;
    }
    void setHourlypayrate(double p){
        while (p < 0){
            cout<<"Enter a value greater than 0: ";
            cin >> p;
        }
        hourlyPayRate = p;
    }
    //Accessor
    double getTotalPay(){
        return hourlyPayRate * noOfHoursWorked;
    }
};
int main()
{
    PayRoll emp[7];
    int p;
    float n;
    for (int i = 0 ; i < 7 ; i++ ){
        cout<<"Enter pay rate for employee "<< (i+1) ;
        cin >> p;
        emp[i].setHourlypayrate(p);
        
        cout<<"Enter no of hours worked for employee "<< (i+1) ;
        cin >> n;
        emp[i].setNoOfHoursWorked(n);
    }
    for (int i = 0 ; i < 7 ; i++ ){
        cout<<"The total gross pay of employee "<<i+1 <<" is: "<<emp[i].getTotalPay()<<endl;
    }
    return 0;
}