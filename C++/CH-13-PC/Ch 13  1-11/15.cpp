#include<iostream>
#include<cmath>
using namespace std;

class HomeMortgage{
    double loan;
    float interestRate;
    int years;
public:
    //Mutators
    void setLoanAmount(double l){
        while( l<0 ){
            cout<<"Enter a valid loan amount: ";
            cin>>l;
        } 
        loan = l;
    }
    void setInterestRate(float i){
        while( i<0 ){
            cout<<"Enter a valid interest rate: ";
            cin>>i;
        } 
        interestRate = i;
    }
    void setNoOfYears(int n){
        while( n<0 ){
            cout<<"Enter valid no of years: ";
            cin>>n;
        } 
        years = n;
    }
    //Accessors
    float getMonthlyPayment(){
        float payment = 0;
        float term = pow(( 1 + (interestRate/12.0)), (12*years) );

        payment = ( loan*(interestRate/12.0)*term ) / ( term-1 );
        return payment;
    }
    float getTotalAmount(){
        return ( (getMonthlyPayment())*12*years );
    }
};
int main(){
    HomeMortgage h1;
    double loan;
    float interestRate;
    int years;

    cout<<"Enter the amount of loan: ";
    cin >> loan;
    h1.setLoanAmount(loan);

    cout<<"Enter the interest rate: ";
    cin>>interestRate;
    h1.setInterestRate(interestRate);

    cout<<"Enter the No of years: ";
    cin>>years;
    h1.setNoOfYears(years);

    cout<<endl<<"The monthly payment is: "<<h1.getMonthlyPayment()<<endl;
    cout<<endl<<"The total amount is: "<<h1.getTotalAmount()<<endl;

    return 0;
}