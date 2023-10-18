#include <iostream>
using namespace std;

class Node
{
	int data;
	Node* next;
	Node* prev;

public:
	Node(int d = 0, Node* n = NULL, Node* p = NULL)
	{
		data = d;
		next = n;
		prev = p;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setNext(Node* n = NULL)
	{
		next = n;
	}
	void setPrev(Node* p = NULL)
	{
		prev = p;
	}
	int getdata()
	{
		return data;
	}
	Node* getNext()
	{
		return next;
	}
	Node* getPrev()
	{
		return prev;
	}
};
class DoublyLinkedList
{
	Node* head;
	Node* tail;
	int length = 0;

public:
	DoublyLinkedList()
	{
		head = new Node();
		tail = new Node();
		head->setNext(tail);
		tail->setPrev(head);
		head->setPrev();
		tail->setNext();
	}
	bool IsEmpty()
	{
		return head == NULL;
	}
	void insertAtEnd(int val)
	{
		Node* newNode = new Node(val);
		newNode->setPrev(tail->getPrev());
		tail->getPrev()->setNext(newNode);
		tail->setPrev(newNode);
		newNode->setNext(tail);
		length++;
	}
	void insertAtStart(int val)
	{
		Node* newNode = new Node(val);
		if (IsEmpty())
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			head->setPrev(newNode);
			newNode->setNext(head);
			head = newNode;
			length++;
		}
	}
	void insertAtPosition(int pos, int val)
	{
		int count = 0;
		Node* tempPre = head;
		Node* tempNex = head->getNext();
		if (pos > 0 && pos < length)
		{
			while (count < pos - 1)
			{
				tempPre = tempPre->getNext();
				tempNex = tempNex->getNext();
			}
			Node* newNode = new Node(val);
			newNode->setPrev(tempPre);
			newNode->setNext(tempNex);
			tempNex->setPrev(newNode);
			tempPre->setNext(newNode);
		}
		length++;
	}
	int getLength()
	{
		return length;
	}
	~DoublyLinkedList()
	{
		Node* temp = head;
		while (temp != tail)
		{
			cout << "hello";
			temp = temp->getNext();
			delete temp;
			cout << "ppp";
		}
		temp = nullptr;
		delete tail;
		delete head;
		cout << "ooo";
	}
	void display()
	{
		Node* temp = head->getNext();
		while (temp != tail)
		{
			cout << temp->getdata() << "  ";
			temp = temp->getNext();
		}
	}
};
int main()
{
	DoublyLinkedList list;
	cout << "Error nhi ha insert se phle";
	// list.insertAtStart(89);
	list.insertAtEnd(76);
	cout << "Error nhi ha insert ke baad";
	cout << list.getLength();
	list.insertAtEnd(10);
	cout << list.getLength() << endl;
	// list.insertAtPosition(1,54);
	list.display();
}