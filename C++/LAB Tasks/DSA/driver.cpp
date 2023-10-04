#include<iostream>
#include"list.h"

using namespace std;

int main(){
    List l;
   
    cout<<"Inserting 10, 7,4,5,5,2,1"<<endl;
    l.insertHead(5);
    l.insertHead(7);
    l.insertHead(4);
    l.insertHead(5);
    l.insertHead(5);
    l.insertHead(2);
    l.insertHead(1);
    l.display();

    cout<<"Using Insert Sort 8 is Added "<<endl;
    l.InserSort(8); // Data WIll Sorted Automatically before added
    l.display();
    
    cout<<"Using Insert Sort 5 is Added Again"<<endl;
    l.InserSort(3);
    l.display();

    cout<<"Appened 2 "<<endl;
    l.Append(2);
    l.display();

  


}