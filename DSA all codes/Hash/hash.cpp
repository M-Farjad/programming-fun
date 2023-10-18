// #include <iostream>
// #include <climits>
// using namespace std;

// class Node
// {
//     Node* next;
//     int data;

// public:
//     Node(int val = 0) : data(val), next(NULL) {}
//     void setData(int val = -1) { data = val; }
//     int getData() { return data; }
//     void setNext(Node* node) { next = node; }
//     Node* getNext() { return next; }
// };
// class Hash
// {
//     Node* arr;
//     int size;

// public:
//     Hash(int size);
//     void insert(int key);
//     int Hashfun(const string& key, int tableSize)
//     {
//         int hashVal = 0;
//         for (int i = 0; i < key.length(); i++)
//             hashVal += key[i];
//         return hashVal % tableSize;
//     }
//     void Remove(int key);
//     bool Search(int key);
//     void display();
// };
// void Hash::insert(int key) {}
// bool Hash::Search(int key) { return 0; }
// void Hash::Remove(int key) {}

// Hash::Hash(int size = 10)
// {
//     this->size = size;
//     arr = new Node[size];
//     for (int i = 0; i < size; i++) {
//         arr[i].setData();
//         arr[i].setNext(NULL);
//         if ((arr[i].getNext()) == NULL)
//             continue;
//     }
// }
// void Hash::display()
// {
//     cout << "The Hash according to hash keys are: ";
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i].getData() << " ";
//     }
// }
// int main()
// {
//     Hash obj;
//     obj.display();
// }






// C++ program to illustrate the array
// of Linked Lists
#include <iostream>
using namespace std;

// Structure of Linked Lists
struct info {
	int data;
	info* next;
};

// Driver Code
int main()
{
	int size = 10;

	// Pointer To Pointer Array
	info** head;

	// Array of pointers to info struct
	// of size
	head = new info*[size];

	// Initialize pointer array to NULL
	for (int i = 0; i < size; ++i) {
		*(head + i) = NULL;
	}

	// Traverse the pointer array
	for (int i = 0; i < size; ++i) {

		// To track last node of the list
		info* prev = NULL;

		// Randomly taking 4 nodes in each
		// linked list
		int s = 4;

		while (s--) {

			// Create a new node
			info* n = new info;

			// Input the random data
			n->data = i * s;
			n->next = NULL;

			// If the node is first
			if (*(head + i) == NULL) {
				*(head + i) = n;
			}
			else {
				prev->next = n;
			}
			prev = n;
		}
	}

	// Print the array of linked list
	for (int i = 0; i < size; ++i) {
		info* temp = *(head + i);

		// Linked list number
		cout << i << "-->\t";

		// Print the Linked List
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << '\n';
	}

	return 0;
}
