#include <iostream>
#include <list>
#include <string>

using namespace std;

class HashTable
{
private:
    static const int hashGroups = 10; // list 1, index 0, list 2, Index 1 ...
    list<pair<int, string>> table[hashGroups];

public:
    bool isEmpty() const;
    int hashFunction(int key);          //Task 2
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
    auto &cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++)
    {
        if (bItr->first == key)
        {
            keyExists = true;
            bItr->second = val;
            cout << "[WARNING]      Key ["<<key<<"] exists. Value replaced." << endl;
            break;
        }
    }
    if (!keyExists)
        cell.emplace_back(key, val);
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
    // Task 1
    HT.insertItem(905, "Labeeb");
    HT.insertItem(364, "Haseeb");
    HT.insertItem(835, "Wall-E");
    HT.insertItem(663, "Farjad");
    HT.insertItem(314, "Salman");
    HT.insertItem(332, "Ahmad");
    HT.insertItem(332, "Numan");


    HT.printTable();


    // Task 3
    HT.removeItem(364);
    HT.removeItem(100);

    HT.printTable();

    // Task 4
    HT.searchTable(100); 
    HT.searchTable(314); 

    if (HT.isEmpty())
        cout << "Oh oh. We need to check out code!";
    else
        cout << "Correct answer! Good job." << endl;
    return 0;
}












#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int val = 0):next(NULL),data(val){}
};
class List
{
public:
	Node* head;
	Node* tail;
	List():head(NULL),tail(NULL)
	{
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void insertKeyAtBeginning(int val)
	{
		Node* newnode = new Node(val);
		tail = head = newnode;
	}
	void InsertAfterHead(int val)
	{
		Node* newnode = new Node(val);
		tail->next = newnode;
		tail = newnode;
	}
};
class Hash 
{
	int Size;
	List *list;
public:
	Hash(int s):Size(s),list(new List[Size]){}
	int Hashfun(int key)
	{
		return key % Size;
	}
	void insert(int key)
	{
		int i = Hashfun(key);
		if (list[i].IsEmpty())
			list[i].insertKeyAtBeginning(key);
		else
		{
			list[i].InsertAfterHead(key);
		}
	}
	bool Search(int key)
	{
		for (int i = 0; i <= Size - 1; i++)
		{
			if (list[i].head)
			{
				Node* temp = list[i].head;
				if (key == temp->data)
					return 1;
				if (temp->next)
				{
					while (temp)
					{
						if (key == temp->data)
							return 1;
						temp = temp->next;
					}
				}
			}
		}
		return 0;
	}
	void deleteKey(int key)
	{
		for (int i = 0; i <= Size - 1; i++)
		{
			if (list[i].head)
			{
				Node* temp1 = list[i].head;
				Node* temp2 = list[i].head;
				if (key == temp1->data)
				{
					cout << "\n" << temp1->data << " has been removed\n";
					if (temp1->next)
					{
						list[i].head = temp1->next;
						break;
					}
					else
					{
						list[i].head = NULL;
						break;
					}
				}
				else
				{
					int count1 = 0;
					int count2 = 0;
					while (temp1->data != key)
					{
						temp1 = temp1->next;
						count1++;
						if (temp1 == NULL)
							break;
					}
					while (count2 < count1 - 1)
					{
						temp2 = temp2->next;
						count2++;
					}
					if (temp1)
					{
						temp2->next = temp1->next;
						temp1 = NULL;
					}
				}
			}

		}
	}
	void display()
	{
		cout << "\nHash Keys are: \n";
		for (int i = 0; i < Size; i++)
		{
			if (list[i].IsEmpty())
				cout << "empty\n";
			if (!list[i].IsEmpty())
			{
				Node* temp = list[i].head;
				cout << temp->data;
				if (temp->next != NULL)
				{
					temp = temp->next;
					while (temp != NULL)
					{
						cout << ", " << temp->data;
						temp = temp->next;
					}
				}
				cout << endl;
			}
		}
	}
};
int main()
{
	Hash myHashTable(5);
	myHashTable.insert(5);
	myHashTable.insert(8);
	myHashTable.insert(5);
	myHashTable.insert(4);
	myHashTable.display();

	myHashTable.deleteKey(4);
	myHashTable.display();
	myHashTable.deleteKey(7);
	myHashTable.display();
	if (myHashTable.Search(8))
		cout << "\nfound\n";
	else
		cout << "\nnot found\n";
}