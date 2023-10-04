#include<iostream>
#include<string>

using namespace std;

class Date{
    int day, month, year;
public:
    void print(){

    }
    void setDay(int a){
        while(a>31 || a<1){
            if(a>31 || a<1){
                cout<<"Please Enter a number between 1 and 31: ";
                cin>>a;
            }
        }
        day = a;
    }
    void setMonth(int a){
        while(a>12 || a<1){
            if(a>12 || a<1){
                cout<<"Please Enter a number between 1 and 12: ";
                cin>>a;
            }
        }
        month = a;
    }
    void setYear(int a ){
        year = a;
    }
    void print1(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
    void print2(){
        if(month == 1 ){
            cout<<"January "<<day<<", "<<year<<endl;
        }
        if(month == 2 ){
            cout<<"February "<<day<<", "<<year<<endl;
        }
        if(month == 3 ){
            cout<<"March "<<day<<", "<<year<<endl;
        }
        if(month == 4 ){
            cout<<"April "<<day<<", "<<year<<endl;
        }
        if(month == 5 ){
            cout<<"May "<<day<<", "<<year<<endl;
        }
        if(month == 6 ){
            cout<<"June "<<day<<", "<<year<<endl;
        }
        if(month == 7 ){
            cout<<"July "<<day<<", "<<year<<endl;
        }
        if(month == 8 ){
            cout<<"August "<<day<<", "<<year<<endl;
        }
        if(month == 9 ){
            cout<<"September "<<day<<", "<<year<<endl;
        }
        if(month == 10 ){
            cout<<"October "<<day<<", "<<year<<endl;
        }
        if(month == 11 ){
            cout<<"November "<<day<<", "<<year<<endl;
        }
        if(month == 12 ){
            cout<<"December "<<day<<", "<<year<<endl;
        }
    }
    void print3(){
        if(month == 1 ){
            cout<<day<<" "<<"January "<<year<<endl;
        }
        if(month == 2 ){
            cout<<day<<" "<<"February "<<year<<endl;
        }
        if(month == 3 ){
            cout<<day<<" "<<"March "<<year<<endl;
        }
        if(month == 4 ){
            cout<<day<<" "<<"April "<<year<<endl;
        }
        if(month == 5 ){
            cout<<day<<" "<<"May "<<year<<endl;
        }
        if(month == 6 ){
            cout<<day<<" "<<"June "<<year<<endl;
        }
        if(month == 7 ){
            cout<<day<<" "<<"July "<<year<<endl;
        }
        if(month == 8 ){
            cout<<day<<" "<<"August "<<year<<endl;
        }
        if(month == 9 ){
            cout<<day<<" "<<"September "<<year<<endl;
        }
        if(month == 10 ){
            cout<<day<<" "<<"October "<<year<<endl;
        }
        if(month == 11 ){
            cout<<day<<" "<<"November "<<year<<endl;
        }
        if(month == 12 ){
            cout<<day<<" "<<"December "<<year<<endl;
        }
    }

};

int main()
{
    Date d1;
    int val;

    cout<<"Enter Day: ";
    cin >> val;
    d1.setDay(val);
    
    cout<<"Enter Month: ";
    cin >> val;
    d1.setMonth(val);

    cout<<"Enter Year: ";
    cin >> val;
    d1.setYear(val);
    
    d1.print1();
    d1.print2();
    d1.print3();    
    
    return 0;
}
