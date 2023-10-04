#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main(){
    fstream file;
    file.open("data.txt",ios_base::app);
    // string fields[5]={"ID","FirstName","LastName","Age","Gender"};
    // for (int  i = 0; i < 5; i++)
    // {
    //     file<<fields[i]<<"\t";
    // }
    // file<<"\n";
    int id[3]{1,2,3};
    string firstName[3]={
        "Ali","Ahmad","Ayesha"
    };
    string lastName[3]={
        "Akram","Khan","Batool",
    };
    int age[3]={24,22,21};
    string gender[3]={
        "Male","Male","Female"
    };

    for(int i=0;i<3;i++){
        file<<id[i]<<"\t"<<firstName[i]<<"\t"<<lastName[i]<<"\t"<<age[i]<<"\t"<<gender[i]<<"\n";
    }
    file.close();
    file.open("data.txt",ios_base::in);
    for (int i = 0; i < 3; i++)
    {
        file>>id[i]>>firstName[i]>>lastName[i]>>age[i]>>gender[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cout<<id[i]<<"\t"<<firstName[i]<<"\t"<<lastName[i]<<"\t"<<age[i]<<"\t"<<gender[i]<<endl;
    }
    
    return 0;
}