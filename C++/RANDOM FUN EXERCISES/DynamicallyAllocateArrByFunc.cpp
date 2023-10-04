#include<iostream>
using namespace std;
int *dArray(int);

int main(){
    int size = 0 ;

    cout<<"Enter size of the array: ";
    cin>>size;

    int *ptr =dArray(size);
    
    //use the array
    
    delete []ptr;
   
    return 0;
}
int *dArray(int size){
    int *p = nullptr;
    p = new int[size];
    return p;
}
