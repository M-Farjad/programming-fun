#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *next;

public:
	Node(int d = 0, Node *n = nullptr)
	{
		data = d;
		next = n;
	}
	void setData(int d)
	{
		data = d;
	}
	int getData()
	{
		return data;
	}
	void setNext(Node *n = nullptr)
	{
		next = n;
	}
	Node *getNext()
	{
		return next;
	}
};
class SinglyLinkedList
{
	Node *head;
	Node *tail;

public:
	int length;
	SinglyLinkedList(Node *h = nullptr, Node *t = nullptr)
	{
		head = h;
		tail = t;
		length = 0;
	}
	bool IsEmpty()
	{
		return head == nullptr;
	}
	void insertAtStart(int val)
	{
		Node *newNode = new Node(val);
		if (IsEmpty())
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			newNode->setNext(head);
			head = newNode;
			length++;
		}
	}
	void insertAtEnd(int val)
	{
		Node *newNode = new Node(val);
		if (IsEmpty())
		{
			head = tail = newNode;
			length++;
		}
		else
		{
			tail->setNext(newNode);
			tail = newNode;
			length++;
		}
	}
	void insertAtPosition(int pos, int nval)
	{
		Node *temp = head;
		int length = getLength();
		while (length != pos)
		{
			temp = temp->getNext();
		}
		Node *newNode = new Node(nval);
		newNode->setNext(temp->getNext());
		temp->setNext(newNode);
		length++;
	}
	int getLength()
	{
		return length;
	}
	void deleteVal(int pos)
	{
		if (head == nullptr)
			cout << "List is empty. So deletion can not be done" << endl;
		else
		{
			Node *prevnode = head;
			Node *nextnode = head->getNext();
			int count = 0;
			if (pos == 0)
			{
				head = head->getNext();
				delete prevnode;
			}
			else if (pos == length)
			{
				cout << "EEEEE\n";
				while (nextnode->getNext() != NULL)
				{
					prevnode = prevnode->getNext();
					nextnode = nextnode->getNext();
				}
				cout<<nextnode->getData();
				prevnode->setNext(nextnode->getNext());
				tail=prevnode;
				delete nextnode;
				nextnode = nullptr;
			}
			else if (pos < length && pos > 0)
			{
				while (count != pos - 1)
				{
					prevnode = prevnode->getNext();
					nextnode = nextnode->getNext();
					count++;
				}
				prevnode->setNext(nextnode->getNext());
				delete nextnode;
				nextnode = nullptr;
			}
			else
				cout << "Error in Logic";
		}
	}
	void display()
	{
		Node *temp = head;
		if (IsEmpty())
			cout << "Your list is empty";
		else
		{
			while (temp != nullptr)
			{
				cout << temp->getData() << "  ";
				temp = temp->getNext();
			}
		}
		cout << "\n";
	}
	~SinglyLinkedList()
	{
		Node *temp = head;
		while (temp != nullptr)
		{
			head = head->getNext();
			delete temp;
			temp = head;
		}
		temp = nullptr;
	}
};
int main()
{
	SinglyLinkedList list;
	list.insertAtStart(67);
	list.insertAtStart(90);
	list.insertAtEnd(78);
	list.insertAtEnd(45);
	list.insertAtPosition(4, 54);
	list.display();
	list.deleteVal(2);
	list.insertAtEnd(34);
	list.display();
}