#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include<iostream>
using namespace std;

const int COE=0;
const int EXP=1;

class Polynomial
{
private:
	int* arr;
    static int COL;
    int ROW;
	int no_used;
    int Index(int r,int c){   // 
        return r*COL+c;
    }
    void simplify();
    
public:
	Polynomial();
	Polynomial(int);
    Polynomial(Polynomial & );
	~Polynomial();
    void setCoeficient(int,int);
    void setExponent(int,int);
    int getCoeficient(int);
    int getExponent(int);
    void print();
    void setArray();


    
	//overloading operators
    Polynomial& operator+(Polynomial& rightobj);
	
};
int Polynomial::COL =2;


Polynomial::Polynomial()
{
	// cout << "Hello from constructor"<<endl;s
	no_used = 0;
    ROW=2;
	arr= new int[ROW*COL];

	
    for(int r=0; r<ROW ; r++){
        for(int c=0; c<COL ; c++){
            arr[Index(r,c)]=0;
        }
    }
}
Polynomial::Polynomial(int row)
{
	// cout << "Hello from constructor"<<endl;
	no_used = 0;
    ROW=row;
	arr= new int[ROW*COL];

	
    for(int r=0; r<ROW ; r++){
        for(int c=0; c<COL ; c++){
            arr[Index(r,c)]=0;
        }
    }
}
Polynomial::Polynomial(Polynomial & rightObj)
{
	// cout << "Hello from Copy constructor";
    delete []arr;
	no_used = rightObj.no_used;
    ROW=rightObj.ROW;
	arr= new int[ROW*COL];
    for(int r=0; r<ROW ; r++){
        for(int c=0; c<COL ; c++){
            arr[Index(r,c)]=rightObj.arr[Index(r,c)];
        }
    }
}


Polynomial::~Polynomial()
{
	// cout << "Bye I was Destructor"<<endl;
	delete [] arr;
}

void Polynomial::setCoeficient(int index,int value){
    if(index<no_used && index>0){
        arr[Index(index,COE)]=value;
    }
}
void Polynomial::setExponent(int index,int value){
    if(index<no_used && index>0){
        arr[Index(index,EXP)]=value;
    }
}

int Polynomial::getExponent(int index){
    return arr[Index(index,EXP)];
}
int Polynomial::getCoeficient(int index){
    return arr[Index(index,COE)];
}

void Polynomial::print(){
    for(int r=0;r<ROW;r++){
        cout<<getCoeficient(r)<<"X^"<<getExponent(r)<<"    ";
    }
    cout<<endl;
}

void Polynomial::setArray(){
    for(int r=0; r<ROW;r++){
        cout<<"arr["<<r<<"] Enter Coeficient Value => ";
        cin>>arr[Index(r,COE)];
        cout<<"arr["<<r<<"] Enter Exponent Value => ";
        cin>>arr[Index(r,EXP)];
        no_used++;
    }

}

void Polynomial::simplify(){
    for(int i=0; i<ROW;i++){
        if(arr[Index(i,COE)==0]){
            arr[Index(i,COE)]==0;
            arr[Index(i,EXP)]==0;
        }
    }
    for(int i=0; i<ROW;i++){
    }
}

Polynomial& Polynomial::operator+(Polynomial& rightObj){

    int totalRows= ROW+rightObj.ROW;
    int commonRows = 0 ;
    // to calulate common rows 
    for(int i=0; i<ROW ;i++){
        for(int j=0 ; j<rightObj.ROW ; j++){
            if(arr[Index(i,EXP)]==rightObj.arr[Index(j,EXP)]){
                commonRows++;
            }
        }
    }
    int tempSize= totalRows-commonRows;
    Polynomial *temp = new Polynomial(tempSize);


    //for storing left at temp
    for(int i=0 ; i<no_used;i++){
        (*temp).arr[Index(i,EXP)]=arr[Index(i,EXP)];
        (*temp).arr[Index(i,COE)]=arr[Index(i,COE)];
        (*temp).no_used++;
    }
    // for storing right at temp
    for(int i=0 ;i<rightObj.no_used;i++){
        int index=-1;
        for(int j=0; j<(*temp).no_used;j++){
            if(rightObj.arr[Index(i,EXP)]==(*temp).arr[Index(j,EXP)])
            {
                index=j;
                break;
            }
        }
        if(index==-1){
            (*temp).arr[Index(no_used,EXP)]=rightObj.arr[Index(i,EXP)];
            (*temp).arr[Index(no_used,COE)]=rightObj.arr[Index(i,COE)];
            no_used++;
        }
        else{
            (*temp).arr[Index(index,COE)]+=rightObj.arr[Index(i,COE)];
        }
    }
    return *temp;

}




#endif