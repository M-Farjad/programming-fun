#include<iostream>
using namespace std;

float multiply(float num1,float num2){
    if(num2<=0)
        return 0;
    else
        return (num1+multiply(num1,num2-1));
}
float power(float num1,float num2){
    if(num2<=0)
        return 1;
    else
        return (num1*multiply(num1,num2-1));
}
int factorial(int num){
    if(num<=0)
        return 1;
    else
        return (num*factorial(num-1));
}
int Fibonacci(int num){
    if(num<=1)
        return num;
    else
        return (Fibonacci(num-1)+Fibonacci(num-2));
}
int main(){

    return 0;
}