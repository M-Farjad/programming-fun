#include <iostream>
#include<list>

using namespace std;
class HashTable
{
private:
    static const int hashGroups = 26;           // list 1, index 0, list 2, Index 1 ...
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);                  // Task 2
    void insertItem(int key, string val);
    void removeItem(int key);
    bool searchTable(int key);
    void printTable();
};

bool HashTable::isEmpty() const
{

    int sum = 0;
    for (int i = 0; i < hashGroups; i++)
        sum += table[i].size();
    if (!sum)
        return true;
    return false;
}
int HashTable::hashFunction(int key)
{
    return key % hashGroups;
}
void HashTable::insertItem(int key, string val)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue]; // O(1) to the required cell
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = val;
            cout << "[WARNING]      Key [" << key << "] exists. Value replaced." << endl;
            break;
        }
    }
    if (!keyExists)
        cell.emplace_back(key, val); // insert just as a vector in the array
    return;
}
void HashTable::removeItem(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "[INFO]         Pair with Key [" << key << "] Removed." << endl;
            break;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING]      Key not found. Pair not removed." << endl;
    }
    return;
}
bool HashTable::searchTable(int key)
{
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            cout << "[INFO]         Pair with Key [" << key << "] Exists." << endl;
            return true;
        }
    }
    if (!keyExists)
    {
        cout << "[WARNING]      Key not found." << endl;
    }
    return false;
}
void HashTable::printTable()
{
    for (int i = 0; i < hashGroups; i++)
    {
        if (table[i].size() == 0)
            continue;
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++)
        {
            cout << "[INFO]         Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main()
{
	HashTable HT;
    string s = "Labeeb The Great",s1="Wali The Great",s2 = "Numan The Great";

    HT.insertItem(int(s[0]), s);
    HT.insertItem(int(s1[0]), s1);
    HT.insertItem(int(s2[0]), s2);

    HT.printTable();
    HT.searchTable(314);


    if (HT.isEmpty())
        cout << "Oh oh. We need to check out code!";
    else
        cout << "Correct answer! Good job." << endl;
    return 0;
}