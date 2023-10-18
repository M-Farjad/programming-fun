#include<iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int top;        //index of last array
        int size;
    public: 
        Stack(){
            cout<<"Enter the size of stack: ";
            cin>>size;
            arr = new int[size];
            for (int i = 0; i < size; i++)
                arr[i]=0;
            top=-1;
        }
        bool isFull(){
            return top==size-1;
        }
        bool isEmpty(){
            return top==-1;
        }
        int pop(){
            if(!isEmpty())
                arr[top--];
            top--;
        }
        void push(int val){
            if (!isFull())
                arr[top++]=val;
            
        }
};
int main(){

}