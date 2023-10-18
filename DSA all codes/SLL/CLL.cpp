// #include <iostream>
// using namespace std;

// typedef string Elem; // element type
// class CNode
// { // circularly linked list node
// private:
//     Elem elem;        // linked list element value
//     CNode *next;      // next item in the list
//     friend class CLL; // provide CLL access
// };

// class CLL
// {
// public:
//     CLL() : cursor(NULL) {}    // constructor
//     bool empty() const;        // is list empty?
//     const Elem &front() const; // element at cursor
//     const Elem &back() const;  // element following cursor
//     void advance();            // advance cursor
//     void add(const Elem &e);   // add after cursor
//     void remove();             // remove node after cursor
//     void display();
// private:
//     CNode *cursor;
// };

// bool CLL::empty() const // is list empty?
// {
//     return cursor == NULL;
// }
// const Elem &CLL::back() const // element at cursor
// {
//     return cursor->elem;
// }
// const Elem &CLL::front() const // element following cursor
// {
//     return cursor->next->elem;
// }
// void CLL::advance() // advance cursor
// {
//     cursor = cursor->next;
// }
// void CLL::display(){
//     CNode *temp = cursor->next;
// 		if (empty())
// 			cout << "Your list is empty";
// 		else
// 		{
//             do
//             {
//                 cout << temp->elem << "  ";
// 				temp = temp->next;
//             } while (temp != cursor->next);
// 		}
// 		cout << "\n";
// }
// int main()
// {
//     CLL L;
//     L.display();
//     return 0;
// }


#include<iostream>
using namespace std;

class node {
private:
	int data;
	node* next;
public:
	node(int value = 0) {
		data = value;
		next = nullptr;
	}
	friend class circularLinkedList;
};

class circularLinkedList {
private:
	node* head;
public:
	circularLinkedList() {
		head = new node();
		head->next = head;
	}
	void insert(int value) {
		node* newNode = new node(value);  //head->head
		newNode->next = head->next;       //0->head
		head->next = newNode;             //head->0->head
	}

	void insertAtEnd(int value) {
		if (head->next == head) {
			insert(value);
		}
		else {
			node* newNode = new node(value);  //head->1->2->3->head
			node* i = head->next;
			while (i->next != head) {
				i = i->next;
			}
			i->next = newNode;
			newNode->next = head;
		}
	}

	void deleteNode(int value) {
		//head->1->2->3->head
		node* i = head;
		while (i->next != head) {
			if (i->next->data == value) {
				node* del = i->next;
				i->next = i->next->next;
				delete del;
			}
			else {
				i = i->next;
			}
		}
	}

	void display() {
		cout << "head->";
		node* i = head->next;
		while (i != head) {
			cout << i->data << "->";
			i = i->next;
		}
		cout << "head\n";
	}
};

int main() {
	circularLinkedList c;

	c.insert(3);
	c.insert(2);
	c.insert(1);
	c.display();

	c.insertAtEnd(4);
	c.insertAtEnd(4);
	c.insertAtEnd(4);
	c.insertAtEnd(5);
	c.insertAtEnd(4);
	c.insertAtEnd(6);
	c.display();

	c.deleteNode(4);
	c.display();
}