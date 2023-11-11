#include <iostream>
#include<climits>
using namespace std;

class Node
{
    int data;
    Node *right;
    Node *left;
    Node *parent;

public:
    Node(int val=INT_MIN):data(val)
    {
        right = left = parent = NULL;
    }
};

class LinkedTree{
    Node* root = NULL;
};
int main(){
    LinkedTree T;
    return 0;
}