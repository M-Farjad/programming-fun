#include<iostream>
#include <conio.h>
#include"intArray.h"
using namespace std;

char menu();

int main(){
   char choice;
    bool display_menu = true; 
    int dummy_arr[] = {1,1};
    int dummy_size = sizeof(dummy_arr)/sizeof(int);
    
    IntArray arr(dummy_arr,dummy_size);

    while (display_menu)
    {
    system("CLS");
    arr.display();
    choice = menu();
    switch (choice)
    {
    case '0':
        display_menu=false;
        break;
    case '1':
        arr.insert(true);
        break;
    case '2':
        arr.insert(false);
        break;
    case '3':
        arr.remove();
        break;
    case '4':
        arr.update();
        break;
    case '5':
        arr.search();
        break;
    
    default:
        break;
    };
    }
    cout<<"You Quit the Program "<<endl;
    return  0;
}

char menu(){
    int choice;
    cout<<"Menu"<<endl;
    cout<<"1. Insert at Begning"<<endl;
    cout<<"2. Insert at End"<<endl;
    cout<<"3. Remove Element"<<endl;
    cout<<"4. Update Element"<<endl;
    cout<<"5. Search Element"<<endl;
    cout<<"0. Quit"<<endl;
    // Taking Input
    cout<<"Choice =>";
    choice = getche();
    cout<<endl;
    // In case of wrong input
    while(choice < '0' || choice >'5'){
        cout<<"Invalid Choice !"<<endl;
        cout<<"Choice =>";
        choice = getche();
        cout<<endl; 
    }  
    return choice;
}