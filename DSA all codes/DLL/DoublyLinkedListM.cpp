#include <iostream>
using namespace std;

class Node
{
	int data;
	Node *next;
	Node *prev;

public:
	Node(int d = 0, Node *n = NULL, Node *p = NULL)
	{
		data = d;
		next = n;
		prev = p;
	}
	void setdata(int d)
	{
		data = d;
	}
	void setNext(Node *n = NULL)
	{
		next = n;
	}
	void setPrev(Node *p = NULL)
	{
		prev = p;
	}
	int getdata()
	{
		return data;
	}
	Node *getNext()
	{
		return next;
	}
	Node *getPrev()
	{
		return prev;
	}
};
class DoublyLinkedList
{
	Node *head;
	Node *tail;
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
		Node *newNode = new Node(val);
		newNode->setPrev(tail->getPrev());
		tail->getPrev()->setNext(newNode);
		tail->setPrev(newNode);
		newNode->setNext(tail);
		length++;
	}
	void insertAtStart(int val)
	{
		Node *newNode = new Node(val);
		newNode->setNext(head->getNext());
		head->getNext()->setPrev(newNode);
		head->setNext(newNode);
		newNode->setPrev(head);
		length++;
	}
	void dscSortList(){
        Node *i, *j;int temp;
        for (i = head; i->getNext() != NULL; i = i->getNext())
        {
            for ( j=i->getNext(); j!=NULL; j=j->getNext())
            {
                if(i->getdata()<j->getdata())
                {
                    temp=i->getdata();
                    i->setdata(j->getdata());
                    j->setdata(temp);
                }
            }
            
        }
    }
	void ascSortList()
    {
        Node *i, *j;int temp;
        for (i = head; i->getNext() != NULL; i = i->getNext())
        {
            for ( j=i->getNext(); j!=NULL; j=j->getNext())
            {
                if(i->getdata()>j->getdata())
                {
                    temp=i->getdata();
                    i->setdata(j->getdata());
                    j->setdata(temp);
                }
            }
            
        }
    }
	// void insertAtPosition(int pos, int val)
	// {
	// 	// int count = 0;
	// 	// Node *tempPre = head;
	// 	// Node *tempNex = head->getNext();
	// 	Node* temp = head;
	// 	Node* nodeNew = new Node(val);
	// 	if (pos == 0)
	// 	{
	// 		insertAtStart(val);
	// 		return;
	// 	}
	// 	else if (pos == length)
	// 	{
	// 		insertAtEnd(val);
	// 		return;
	// 	}
	// 	else if (pos > 0 && pos < length)
	// 	{

	// 		int count = 0;
	// 		cout<<"Hel;=";
	// 		while (count != pos - 1 && temp->getNext() != tail)
	// 		{
	// 		cout<<"Hel;=";
	// 			temp = temp->getNext();
	// 			count++;
	// 		}
	// 		nodeNew->setNext(temp->getNext());
	// 		temp->setNext(nodeNew);
	// 	}
	// 	else
	// 	{
	// 		cout << "Index Out of Bound inserting at end";
	// 		insertAtEnd(val);
	// 		return;
	// 	}
	// 	length++;
	// }
	void insertAtAnyPosition(int position, int value)
	{
		if (position == 0)
		{
			insertAtStart(value);
		}
		else if (position > length || position < 0)
		{
			cout << "position Out of Bound inserting at head\n";
			insertAtStart(value);
		}
		else
		{
			int count = 0;
			Node *temp = head;
			Node *newNode = new Node(value);
			for (int i = 1; i < position; i++)
			{
				temp = temp->getNext();
			}

			// 1 2 3
			// 1 0 2 3

			newNode->setNext(temp->getNext());
			temp->getNext()->setPrev(newNode);
			temp->setNext(newNode);
			newNode->setPrev(temp);
			length++;
		}
	}
	void delAtIndex(int Index)
	{
		int count = 0;
		if (Index < 0)
		{
			cout << "Index Out of bound ... !\n";
		}
		if (Index == 0)
		{
			if (head->getNext() == tail)
			{
				Node *ptr = head;
				head = NULL;
				delete ptr;
			}
			else
			{
				Node *ptr = head;
				head = head->getNext();
				head->getNext()->setPrev(NULL);
				delete ptr;
			}
		}
		else
		{
			if (IsEmpty())
			{
				cout << "Already Empty\n";
			}

			else
			{
				Node *p = head;
				while (count < Index - 1)
				{
					p = p->getNext();
					count++;
					if (p->getNext() == NULL)
					{
						cout << "Index Out of bound ... !\n";
						return;
					}
				}
				Node *q = p->getNext();
				p->setNext(q->getNext());
				q->getNext()->setPrev(p);
				delete q;
				q = NULL;
				// cout<<p->next;
			}
		}
		length--;
	}
	void delAtBeginning()
	{
		if (head == NULL)
			cout << "Already Empty\n";
		else
		{
			Node *ptr = head;
			head->getNext()->setPrev(NULL);
			head = head->getNext();
			delete ptr;
			ptr = nullptr;
		}
		length--;
	}
	// void insertAtPosition(int pos, int nval)
	// {
	// 	Node *temp = head;
	// 	Node *newNode = new Node(nval);
	// 	if (pos == 0)
	// 	{
	// 		newNode->setNext(head);
	// 		head=newNode;
	// 	}
	// 	else
	// 	{
	// 		if (pos < length && pos > 0)
	// 		{
	// 			int count = 0;
	// 			while (count != pos-1 && temp->getNext() != NULL)
	// 			{
	// 				temp = temp->getNext();
	// 				count++;
	// 			}
	// 			newNode->setNext(temp->getNext());
	// 			temp->setNext(newNode);
	// 		}
	// 		else if(pos==length)
	// 		{
	// 			insertAtEnd(nval);
	// 		}
	// 		else
	// 		{
	// 			cout << "Index Out of Bound\n";
	// 			return;
	// 		}
	// 	}
	// 	length++;
	// }
	int getLength()
	{
		return length;
	}
	~DoublyLinkedList()
	{
		Node *temp = head;
		while (temp != tail)
		{
			Node *del = temp;
			temp = temp->getNext();
			delete del;
		}
		delete tail;
		head = NULL;
		tail = NULL;
	}
	void display()
	{
		Node *temp = head->getNext();
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
	list.insertAtStart(98);
	list.insertAtEnd(76);
	list.insertAtStart(89);
	cout << list.getLength();
	list.insertAtEnd(10);
	cout << list.getLength();
	list.insertAtStart(78);
	cout << list.getLength();
	list.insertAtAnyPosition(7, 54);
	cout << list.getLength() << endl;
	list.display();
	list.delAtIndex(2);
	cout << endl<<list.getLength()<<endl;
	list.display();
	list.dscSortList();
	cout<<"\nDesc Sorted";
	list.display();
	list.ascSortList();
	cout<<"\nAsc Sorted";
	list.display();
	return 0;
}