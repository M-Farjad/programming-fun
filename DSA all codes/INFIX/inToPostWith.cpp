#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;

class Node
{
private:
    Node *next;
    char data;

public:
    Node()
    {
        next = NULL;
        data = 0;
    }
    friend class Stack;
};

class Stack{
    private:
        Node *head;
    public:
     Stack(int s = 10)
    {
        Node *node = new Node;
        head = node;
    }
    bool isempty()
    {
        return (head->next == NULL);
    }
    void push(int d)
    {
            Node *node = new Node;
            node->data = d;
            node->next = head;
            head = node;
    }
    int pop()
    {
            Node *temp = head;
            int d = head->data;
            head = head->next;
            delete temp;
            return d;
    }
    int top()
    {
        return head->data;
    }
};

bool pres(char a, char b){
    int num1 , num2 ;
    if( a=='+' ||  a=='-'){
        num1 = 1;
    }
    else if( a=='*' || a=='/'){
        num1 = 2;

    }
    else if( a=='('||a==')'){
        num1 = 3;
    }

    if( b=='+' ||  b=='-'){
        num2 = 1;
    }
    else if( b=='*' || b=='/'){
        num2 = 2;

    }
    else if( b=='('||b==')'){
        num2 = 3;
    }

    return num1<num2;
}

int main(){
    Stack s;
    string infix;
    // cout<<" Enter Value to Convert into postfix : ";
    // cin>>infix;
    infix="8*2+(2*(3+9)*3)-8";
    string ans="";

    for(int i=0 ; i<infix.length(); i++){
        if(infix[i]>= '0' && infix[i] <= '9'){
            ans+=infix[i];
        }
        else{
            if(s.isempty()){
                s.push(infix[i]);
            }
            else{
                if(infix[i]==')'){
                    while(s.top()!='('){
                        ans+=s.pop();
                    }
                    s.pop(); // to pop (
                }
                else if(pres(s.top(),infix[i])){
                    s.push(infix[i]);
                }
                else{
                    while( !pres(s.top(),infix[i]) && s.top()!='(' && !s.isempty()){
                        ans+=s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while(!s.isempty()){
        ans+=s.pop();
    }

    cout<<ans<<endl;


}