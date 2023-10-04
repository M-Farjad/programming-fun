#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
    private:
        Node* next;
        int data;
    public:
        Node(){
            data=0;
            next=NULL;
        }
        friend class List;
};


#endif