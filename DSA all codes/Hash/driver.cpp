#include<iostream>
#include<queue>
#include<set>

using namespace std;


// The main function to print vertical oder of a
// binary tree with given root
void printVerticalOrder(Node *root){
    // Base case
    if (!root) return;
// Create a map and store vertical oder in
// map using function getVerticalOrder()
set<int, vector<int>> m;
int hd = 0;
// Create queue to do level order traversal.
// Every item of queue contains node and
// horizontal distance.
queue<pair<Node *, int>> que;
que.push(make_pair(root, hd));
while (!que.empty())
{
    // pop from queue front
    pair<Node *, int> temp = que.front();
    que.pop();
    hd = temp.second;
    Node *node = temp.first;
    // insert this node's data in vector of hash
    m[hd].push_back(node->key);
    if (node->left != NULL)
        que.push(make_pair(node->left, hd - 1));
    if (node->right != NULL)
        que.push(make_pair(node->right, hd + 1));
}
// Traverse the map and print nodes at
// every horigontal distance (hd)
map<int, vector<int>>::iterator it;
for (it - m.begin(); it != m.end(); it++)
{
    for (int i = 0; i < it->second.size(); ++i)
        cout << it->second[i] << " ";
    cout << endl;
}}





#include <iostream>
#include <climits>
using namespace std;

class Node
{
    Node* next;
    int data;

public:
    Node(int val = 0) : data(val), next(NULL) {}
    void setData(int val = -1) { data = val; }
    int getData() { return data; }
    void setNext(Node* node) { next = node; }
    Node* getNext() { return next; }
};
class Hash
{
    Node* arr;
    int size;

public:
    Hash(int size);
    void insert(int key);
    int Hashfun(const string& key, int tableSize)
    {
        int hashVal = 0;
        for (int i = 0; i < key.length(); i++)
            hashVal += key[i];
        return hashVal % tableSize;
    }
    void Remove(int key);
    bool Search(int key);
    void display();
};
void Hash::insert(int key) {}
bool Hash::Search(int key) { return 0; }
void Hash::Remove(int key) {}

Hash::Hash(int size = 10)
{
    this->size = size;
    arr = new Node[size];
    for (int i = 0; i < size; i++) {
        arr[i].setData();
        arr[i].setNext(NULL);
        if ((arr[i].getNext()) == NULL)
            continue;
    }
}
void Hash::display()
{
    cout << "The Hash according to hash keys are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i].getData() << " ";
    }
}
int main()
{
    Hash obj;
    obj.display();
}