#include<iostream>
#include<string>

using namespace std;

class Car{
    int yearModel;
    string make;
    int speed;
public:
    Car(int model, string MAKE){
        yearModel = model;
        make = MAKE;
        speed = 0;
    }    
    int getYearModel() const{
        return yearModel;
    }
    string getMake() const{
        return make;
    }
    int getSpeed() const{
        return speed;
    }
    void accelerate(){
        speed += 5;
    }
    void brake(){
        speed -= 5;
    }
    
};

int main()
{
    int model;
    string make;

    cout<<"Enter the model of the car: ";
    cin >> model;

    cout<<"Enter company f the car: ";
    cin >> make;
     
    Car grande(model ,make);
    cout<<"The speed of car is: "<<grande.getSpeed()<<endl;
    
    cout<<endl<<"Accelerating the car."<<endl;
    for(int i = 1 ; i<=5 ; i++ ){
        grande.accelerate();
        cout<<"The speed of car is: "<<grande.getSpeed()<<endl;
    }
        
    cout<<endl<<"Applyinng Brakes."<<endl;
    for(int i = 1 ; i<=5 ; i++ ){
        grande.brake();
        cout<<"The speed of car is: "<<grande.getSpeed()<<endl;
    }
    
    
    
    return 0;
}
