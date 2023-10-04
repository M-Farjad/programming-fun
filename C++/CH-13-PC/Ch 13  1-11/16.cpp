#include<iostream>

using namespace std;

class Temperature{
    float temperature;
public:
    //Constructors
    Temperature(){
        temperature = 18.0;     //by default set to room temperature
    }
    Temperature(float t){
        temperature = t;
    }

    void setTemperature(float t){
        temperature = t;
    }
    float gettemperature(){
        return temperature;
    }

    bool isEthylFreezing(){
        if( temperature <= (-173) ){
            return true;
        }
        else 
            return false;
    }
    bool isEthylBoiling(){
        if( temperature >= 172 ){
            return true;
        }
        else 
            return false;
    }
    bool isOxygenFreezing(){
        if( temperature <= (-362) ){
            return true;
        }
        else 
            return false;
    }
    bool isOxygenBoiling(){
        if( temperature >= (-306) ){
            return true;
        }
        else 
            return false;
    }
    bool isWaterFreezing(){
        if( temperature <= 32 ){
            return true;
        }
        else 
            return false;
    }
    bool isWaterBoiling(){
        if( temperature >= 212 ){
            return true;
        }
        else 
            return false;
    }

};
int main(){
    float temp = 0.0;

    cout<<"Enter the temperature: ";
    cin>>temp;

    Temperature t1(temp);

    if( t1.isEthylBoiling() ){
        cout<<"The ethyle is boiling. " << endl;
    }
    if( t1.isEthylFreezing() ){
        cout<<"The ethyle is freezing. " << endl;
    }
    if( t1.isOxygenBoiling() ){
        cout<<"The oxygen is boiling. " << endl;
    }
    if( t1.isOxygenFreezing() ){
        cout<<"The oxygen is freezing. " << endl;
    }
    if( t1.isWaterBoiling() ){
        cout<<"The water is boiling. " << endl;
    }
    if( t1.isWaterFreezing() ){
        cout<<"The water is freezing. " << endl;
    }

    return 0;
}