/*
C++ vectors basics
and functions used
with vectors
*/
#include <iostream>
#include <vector>

using namespace std;
void display(vector<int> &);

int main()
{
    int size, val;
    cout << "enter size of vector(please enter no greater than 4\njust to function properly): ";
    cin >> size;

    vector<int> vec1;
    for (int i = 0; i < size; i++)
    {
        cout << "\nenter the value in vector: ";
        cin >> val;
        vec1.push_back(val);
        cout << endl;
    }
    system("clear");
    cout << "\noriginal\n";
    display(vec1);
    cout << "\ninserting 566\n";

    vector<int>::iterator iter = vec1.begin();
    vec1.insert(iter, 566); // TO INSERT to first position
    display(vec1);
    cout << "\ninserting 44" << endl;
    vec1.insert(iter + 1, 44); // to insert to 3rd position
    display(vec1);
    cout << endl;
    cout << "insert 5 times 44\n";
    vec1.insert(iter + 1, 5, 100); // to insert to 3rd position 100 5 times
    display(vec1);
    cout << "\nafter poping\n";
    vec1.pop_back(); // to extract last value
    display(vec1);

    // now using another method to display vectors
    vector<int> vec2(6, 44);
    cout << endl;
    cout << "Now displaying another vector\n";
    display(vec2);
    return 0;
}

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}