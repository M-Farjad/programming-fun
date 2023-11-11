#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a 4 digit number: ";
    cin>>num;
    int sum = 0;
    while(num!=0){
        sum = sum + num%10;
        num=num/10;
    }
    cout<<"The sum is: "<<sum;
    return 0;
}