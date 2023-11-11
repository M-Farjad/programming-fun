//#include <iostream>
//using namespace std;
//class Node
//{
//public:
//    Node* next;
//    int data;
//    // Node* prev;
//    Node(int value):data(value)
//    {
//        next = NULL;
//        // prev=NULL;
//    }
//};
//class link
//{
//public:
//    Node* head, * last;
//    link()
//    {
//        head  = last = nullptr;
//    }
//    bool isEmpty()
//    {
//        if (head == NULL)
//            return true;
//        return false;
//    }
//    //################## insert Rear Normal #####################
//    void addRear(int val)
//    {
//        Node* node = new Node(val);
//        if (isEmpty())
//        {
//            head = node;
//            last = node;
//        }
//        else
//        {
//            last->next = node;
//            last = node;
//        }
//    }
//    //################## insert Front #####################
//    void addFront(int val)
//    {
//        Node* node = new Node(val);
//        // if (isEmpty())
//        // {
//        //     head = node;
//        //     last = node;
//        // }
//        // else
//        // {
//        node->next = head;
//        head = node;
//        // }
//    }
//    //########## Search #############
//    void search(int value) {
//        int count = 0;
//        Node* runner_ptr;
//        runner_ptr = head;
//        if (runner_ptr == NULL)
//        {
//            cout << "\nEmpty List.\n";
//        }
//        cout << "The value is at position ";
//        while (runner_ptr != NULL)
//        {
//            if (runner_ptr->data == value)
//            {
//                cout << " -> " << (count + 1) << " ";
//            }
//            count++;
//            runner_ptr = runner_ptr->next;
//        }
//        cout << "\n";
//    }
//    //############# Recursive Search ################
//    bool RecursiveSearch(Node* head,int val) {
//        if (head->data==val)
//            return true;
//        else if (head->next == NULL)
//            return false;
//        else
//            return RecursiveSearch(head->next,val);
//    }
//    //######### Recursive print Reverse #########
//    void printReverse(Node* head)
//    {
//        if (head == NULL)
//            return;
//        printReverse(head->next);
//        cout << head->data << " ";
//    }
//    //######### Insert at tail Recursive ##########
//    void insertTailRecursive(Node* currentNode, int val) {
//        if (currentNode->next == NULL) {
//            Node* node = new Node(val);
//            currentNode->next = node;
//        }
//        else
//            insertTailRecursive(currentNode->next,val);
//    }
//    //######### Greatest Value Recursive ##########
//    int findGreatest(Node* currentNode,int currentHighest) {
//        if (currentNode->next == NULL)
//            return currentHighest;
//        else if(currentHighest<=currentNode->data)
//        {
//            currentHighest = currentNode->data;
//            currentHighest = findGreatest(currentNode->next, currentHighest);
//        }
//        return currentHighest;
//    }
//    //######### Display ##########
//    void display()
//    {
//        Node* temp;
//        temp = head;
//        while (temp != NULL)
//        {
//            cout << temp->data << "->";
//            temp = temp->next;
//        }
//        if (temp == NULL)
//        {
//            cout << "NULL";
//        }
//        cout << "\n";
//        delete temp;
//    }
//    //######### Destructor ############
//    ~link()
//    {
//        delete head;
//    }
//};
//int main()
//{
//    link L;
//    L.addRear(1);
//    L.addRear(2);
//    L.addFront(7);
//    L.search(10);
//    L.display();
//    if(L.RecursiveSearch(L.head,20))
//        cout<<"Found\n";
//    else
//        cout << "Not Found\n";
//    L.printReverse(L.head);
//    cout << "\n";
//    L.insertTailRecursive(L.head,10);
//    L.display();
//
//    cout<<"Greatest: "<<L.findGreatest(L.head, L.head->data);
//    return 0;
//}
//
//
//
//
//
// #include <iostream>
// using namespace std;
//
// class StNode
// {
//     // private:
// public:
//     union
//     {
//         char cdata;
//         float fdata;
//     };
//     StNode *next;
//     StNode(char val) : cdata(val)
//     {
//         next = NULL;
//     }
//     StNode(float val) : fdata(val)
//     {
//         next = NULL;
//     }
//     ~StNode() {}
//     // friend class StackLL;
// };
// template <typename T>
// class StackLL
// {
// private:
//     StNode *head;
//     bool isEmpty()
//     {
//         return head == NULL;
//     }
//
// public:
//     StackLL()
//     {
//         head = NULL;
//     }
//     T ftop()
//     {
//         return head->fdata;
//     }
//     T fpop()
//     {
//         if (isEmpty())
//             cout << "Stack Already Empty ... !";
//         else
//         {
//             StNode *tempN = head;
//             T temp = head->fdata;
//             head = head->next;
//             delete tempN;
//             return temp;
//         }
//         return 0;
//     }
//     void fpush(T val)
//     {
//         StNode *node = new StNode(val);
//         node->next = head;
//         head = node;
//     }
//     void fdisplay()
//     {
//         StNode *temp = head;
//         cout << "List : ";
//         while (temp != NULL)
//         {
//             cout << temp->fdata << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };
//
// int main()
// {
//     int data;
//     int Fdata;
//     int choice;
//     cout << "1. char\n2. Float\nEnter choice: ";
//     cin >> choice;
//     switch (choice)
//     {
//         StackLL<float> L;
//         // StackLL<char> Lchar;
//     // case (1):
//     //     data = Lchar.fpop();
//     //     Lchar.fpush('c');
//     //     Lchar.fpush('s');
//     //     Lchar.fpush('q');
//     //     Lchar.fpush('w');
//     //     Lchar.fdisplay();
//     //     data = Lchar.fpop();
//     //     Lchar.fdisplay();
//     //     break;
//     case (2):
//         Fdata = L.fpop();
//         L.fpush(1);
//         L.fpush(2);
//         L.fpush(3);
//         L.fpush(4);
//         L.fdisplay();
//         Fdata = L.fpop();
//         L.fdisplay();
//         break;
//     default:
//         break;
//     }
//     return 0;
// }


#include <iostream>
using namespace std;

class Node
{
    Node* parent;
    Node* right;
    Node* left;
    int data;

public:
    Node(int val = 0) :data(val)
    {
        parent = NULL;
        left = NULL;
        right = NULL;
    }
    void setparent(Node* parent)
    {
        this->parent = parent;
    }
    void setleft(Node* left)
    {
        this->left = left;
    }
    void setright(Node* right)
    {
        this->right = right;
    }
    void setdata(int data)
    {
        this->data = data;
    }
    Node* getparent()
    {
        return this->parent;
    }
    Node* getleft()
    {
        return this->left;
    }
    Node* getright()
    {
        return this->right;
    }
    int getdata()
    {
        return this->data;
    }
    friend class BST;
};
class BST
{
public:
    Node* root;
    BST()
    {
        root = NULL;
    }
    void insert(int val)
    {
        Node* curr = root;
        Node* prev = 0;

        while (curr != NULL && root != 0)
        {
            prev = curr;
            if (val < curr->getdata())
                curr = curr->getleft();
            if (val > curr->getdata())
                curr = curr->getright();
        }
        if (root == 0)
        {
            Node* newnode = new Node();
            newnode->setdata(val);
            root = newnode;
        }
        else if (val < prev->getdata())
        {
            Node* newnode = new Node();
            newnode->setdata(val);
            newnode->setparent(prev);
            prev->setleft(newnode);
        }
        else
        {
            Node* newnode = new Node();
            newnode->setdata(val);
            newnode->setparent(prev);
            prev->setright(newnode);
        }
    }
    // void insert(int value)
    // {
    //     Node *currentNode = root, *prev = 0;
    //     while (currentNode != 0 && root != 0)
    //     {
    //         prev = currentNode;
    //         if (value < currentNode->getdata())
    //             currentNode = currentNode->getleft();
    //         else
    //             currentNode = currentNode->getright();
    //     }
    //     if (root == 0)
    //         root = new Node(value);
    //     else if (value < prev->getdata())
    //     {
    //         Node *temp = new Node(value);
    //         temp->setparent(prev);
    //         prev->setleft(temp);
    //     }
    //     else if (value > prev->getdata())
    //     {
    //         Node *temp = new Node(value);
    //         temp->setparent(prev);
    //         prev->setright(temp);
    //     }
    //     else
    //         cout << "ERROR";
    // }
    void Inorder(Node* node)
    {
        if (node != NULL)
        {
            Inorder(node->getleft());
            cout << node->getdata() << " ";
            Inorder(node->getright());
        }
    }
};
int main()
{
    BST tree;
    tree.insert(67);
    tree.insert(56);
    tree.insert(65);
    tree.Inorder(tree.root);
}