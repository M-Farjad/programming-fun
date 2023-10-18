//#include <iostream>
//using namespace std;
//class Node
//{
//public:
//    Node* next;
//    int data;
//    // Node* prev;
//    Node(int value = 0)
//    {
//        data = value;
//        next = NULL;
//        // prev=NULL;
//    }
//};
//class link
//{
//    Node* head, * last;
//    int length;
//public:
//    link()
//    {
//        head = last = NULL;
//        int length = 0;
//    }
//    bool isEmpty()
//    {
//        if (head == NULL)
//            return true;
//        return false;
//    }
//
//    //################## insert Front #####################
//    void addFront(int val)
//    {
//        Node* node = new Node(val);
//        if (isEmpty())
//        {
//            head = node;
//            last = node;
//        }
//        else
//        {
//            node->next = head;
//            head = node;
//        }
//        length++;
//    }
//
//    //################## ascending sort #####################
//    void ascSortList()
//    {
//        Node* i, * j; int temp;
//        for (i = head; i->next != NULL; i = i->next)
//        {
//            for (j = i->next; j != NULL; j = j->next)
//            {
//                if (i->data > j->data)
//                {
//                    temp = i->data;
//                    i->data = j->data;
//                    j->data = temp;
//                }
//            }
//
//        }
//    }
//    //######### Display ##########
//    void display()
//    {
//        Node* temp;
//        temp = head;
//        while (temp != NULL)
//        {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        if (temp == NULL)
//        {
//            cout << "NULL";
//        }
//        cout << "\n";
//        delete temp;
//    }
//    void insertSorted(int val) {
//        addFront(val);
//        ascSortList();
//
//        length++;
//    }
//    void append(int num) {
//
//        if (num > length) {
//            cout << "\nnot possible";
//            return;
//        }
//
//
//        Node* temp = head;
//        Node* thead = NULL;
//        Node* tTail = NULL;
//
//
//
//        for (int i = 1; i < (length - num - 1); i++) {
//            temp = temp->next;
//        }
//
//        tTail = temp;
//        thead = temp->next;
//
//        while (temp->next != NULL) {
//            temp = temp->next;
//        }
//
//        temp->next = head;
//
//        head = thead;
//
//        tTail->next = NULL;
//
//    }
//};
//int main()
//{
//    link L;
//    L.addFront(3);
//    L.addFront(7);
//    L.addFront(6);
//    L.addFront(5);
//    L.display();
//    L.ascSortList();
//    L.display();
//    L.insertSorted(4);
//    L.display();
//    cout << endl << "Appended: ";
//    L.append(2);
//    L.display();
//    return 0;
//}



#include <iostream>
using namespace std;

class StNode
{
private:
    int data;
    StNode* next;
public:
    StNode(int val = 0) : data(val) {
        next = NULL;
    }
    ~StNode() {}
    friend class StackLL;
};
class StackLL
{
private:
    StNode* head;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    StackLL() {
        head = NULL;
    }
    int top()
    {
        return head->data;
    }
    int pop()
    {
        if (isEmpty())
            cout << "Stack Already Empty ... !\n";
        else
        {
            StNode* tempN = head;
            int temp = head->data;
            head = head->next;
            delete tempN;
            return temp;
        }
        return 0;
    }
    void push(int val) {
        StNode* node = new StNode(val);
        node->next = head;
        head = node;
    }
    void display() {
        StNode* temp = head;
        cout << "List : ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

float evaluatePostfix(string str) {
    StackLL L;
    int num1, num2;float res=0.0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            num2 = L.pop();
            num1 = L.pop();
            switch (str[i])
            {
            case '+':
                res = (num1 + num2);
                break;
            case '-':
                res = (num1 - num2);
                break;
            case '*':
                res = (num1 * num2);
                break;
            case '/':
                res = (num1 / num2);
                break;
            }
            L.push(res);
        }
        else
        {
            L.push(int(str[i] - '0'));
        }
    }
    return (L.pop());
}
int main()
{
    StackLL L;
    cout<<evaluatePostfix("678*+");
    return 0;
}


