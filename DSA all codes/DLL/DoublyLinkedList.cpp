#include<iostream>
using namespace std;

class Node 
{
	int data;
	Node* next;
	Node* prev;
public:
	Node(int d = 0, Node* n = nullptr, Node* p = nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setNext(Node* n = nullptr)
	{
		next = n;
	}
	void setPrev(Node* p = nullptr)
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
public:
	int length = 0;
	DoublyLinkedList(Node* h = nullptr, Node* t = nullptr)
	{
		head = h;
		tail = t;
		head->setNext(tail);
		tail->setPrev(head);
		head->setPrev();
		tail->setNext();
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void insertAtEnd(int val)
	{
		Node* newNode = new Node(val);
		if (IsEmpty())
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
			length++;
		}
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
		while (temp != nullptr)
		{
			head = head->getNext();
			delete temp;
			temp = head;
		}
		temp = nullptr;
		delete tail;
	}
	void display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->getdata() << "  " << endl;
			temp = temp->getNext();
		}
	}
};
int main()
{
	DoublyLinkedList list;
	list.getLength();
	list.insertAtStart(89);
	list.insertAtEnd(76);
	list.insertAtPosition(1,54);
	list.display();
}