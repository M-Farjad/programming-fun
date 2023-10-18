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
	int length = 0;

public:
	SinglyLinkedList(Node *h = nullptr, Node *t = nullptr)
	{
		head = h;
		tail = t;
		length = 0;
	}
	// SinglyLinkedList()
	// {
	// 	head = tail = NULL;
	// }
	int getLength()
	{
		return length;
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
		}
		else
		{
			newNode->setNext(head);
			head = newNode;
		}
		length++;
	}
	void insertAtEnd(int val)
	{
		Node *newNode = new Node(val);
		if (IsEmpty())
			head = tail = newNode;
		else
		{
			tail->setNext(newNode);
			tail = newNode;
		}
		length++;
	}
	void insertAtPosition(int pos, int nval)
	{
		Node *temp = head;
		Node *newNode = new Node(nval);
		if (pos == 0)
		{
			newNode->setNext(head);
			head=newNode;
		}
		else
		{
			if (pos < length && pos > 0)
			{
				int count = 0;
				while (count != pos-1 && temp->getNext() != NULL)
				{
					temp = temp->getNext();
					count++;
				}
				newNode->setNext(temp->getNext());
				temp->setNext(newNode);
			}
			else if(pos==length)
			{
				insertAtEnd(nval);
			}
			else
			{
				cout << "Index Out of Bound\n";
				return;
			}
		}
		length++;
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
	cout << list.getLength() << endl;
	list.display();
	// list.deleteVal(3);
	cout << "KKKKKKKKKK";
	list.display();
}