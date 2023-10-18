#include <iostream>
using namespace std;

class StNode
{
private:
    int data;
    StNode *next;
public:
    StNode(int val=0) : data(val){
        next = NULL;
    }
    ~StNode() {}
    friend class StackLL;
};
class StackLL
{
private:
    StNode *head;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    StackLL(){
        head = NULL;
    }
    int top()
    {
        return head->data;
    }
    int pop()
    {
        if (isEmpty())
            cout << "Stack Already Empty ... !";
        else
        {
            StNode *tempN = head;
            int temp = head->data;
            head = head->next;
            delete tempN;
            return temp;
        }
        return 0;
    }
    void push(int val){
        StNode* node = new StNode(val);
        node->next=head;
        head=node;
    }
    void display(){
        StNode* temp = head;
        cout<<"List : ";
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main()
{
    StackLL L;
    int data;
    data=L.pop();
    L.push(5);
    L.push(6);
    L.push(7);
    L.push(8);
    L.display();
    data=L.pop();
    L.display();
    return 0;
}