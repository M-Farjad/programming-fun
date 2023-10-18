#include <iostream>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    // Node* prev;
    Node(int value)
    {
        data = value;
        next = NULL;
        // prev=NULL;
    }
};
class link
{
public:
    Node *head, *last;
    link()
    {
        head = last = nullptr;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }
    //################## insert Rear #####################
    void addRear(int val)
    {
        Node *node = new Node(val);
        if (isEmpty())
        {
            head = node;
            last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
    }
    //################## insert Front #####################
    void addFront(int val)
    {
        Node *node = new Node(val);
        // if (isEmpty())
        // {
        //     head = node;
        //     last = node;
        // }
        // else
        // {
            node->next = head;
            head = node;
        // }
    }
    //################## insert after #####################
    void addAfter(int newVal, int prvVal)
    {
        if (isEmpty())
        {
            cout << "List is empty...!\n";
            addFront(newVal);
        }
        else
        {
            Node *node = new Node(newVal);
            Node *temp = head;
            while (temp->data != prvVal)
            {
                temp = temp->next;
            }
            node->next = temp->next;
            temp->next = node;
        }
    }
    //################## Delete at Beginning #####################
    void delAtBeginning()
    {
        Node *ptr = head;
        head = head->next;
        delete ptr;
        ptr = nullptr;
    }
    void delAtIndex(int Index)
    {
        int count = 0;
        if (Index < 0)
        {
            cout << "Index Out of bound ... !\n";
        }

        if (isEmpty())
        {
            cout << "Already Empty\n";
        }
        else
        {
            Node *p = head;
            while (count < Index)
            {
                p = p->next;
                count++;
                if (p->next == NULL)
                {
                    cout << "Index Out of bound ... !\n";
                    return;
                }
            }
            Node *q = p->next;
            p->next = q->next;
            delete q;
            q = NULL;
            // cout<<p->next;
        }
    }
    //################## Delete by Value #####################
    void delByVal(int val)
    {
        Node *p = head, *q = p->next;
        if (isEmpty())
        {
            cout << "Already Empty\n";
        }
        // else if (head->next == NULL)
        // {
        //     cout<<"HHHEHEHHEHE";
        //     if (head->data == val)
        //     {
        //         delete head;
        //         head=NULL;
        //     }
        //     else
        //         cout<<"No Such Value Found\n";
        // }
        // else
        // {
        //     while (q->next!=NULL)
        //     {
        //         if (q->data==val)
        //         {
        //             p->next=q->next;
        //             delete q;
        //             q=p->next;
        //         }
        //         p = p->next;
        //         q = q->next;
        //     }
        //     // p->next = q->next;
        //     // delete q;
        //     q = NULL;
        // }
        while (p != NULL &&  p->data == val)
        { // del at head
            Node *del = head;
            p = p->next;
            delete del;
            if (p == NULL)
            {
                return;
            }
        }
        Node *temp = p;

        while (temp != NULL)
        { // del after head
            if (temp->next != NULL && temp->next->data == val)
            {
                Node *del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    //################## Delete at tail #####################
    void delAtTail()
    {
        if (isEmpty())
        {
            cout << "Already Empty\n";
        }
        else
        {

            if (head->next == NULL)
            {
                delAtBeginning();
            }
            else
            {
                Node *p = head, *q = p->next;
                while (q->next != NULL)
                {
                    p = p->next;
                    q = q->next;
                }
                p->next = q->next;
                delete q;
                q = NULL;
            }
        }
    }
    //################## ascending sort #####################
    void ascSortList()
    {
        Node *i, *j;int temp;
        for (i = head; i->next != NULL; i = i->next)
        {
            for ( j=i->next; j!=NULL; j=j->next)
            {
                if(i->data>j->data)
                {
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
            
        }
    }
    //################## Descending sort #####################
    void dscSortList(){
        Node *i, *j;int temp;
        for (i = head; i->next != NULL; i = i->next)
        {
            for ( j=i->next; j!=NULL; j=j->next)
            {
                if(i->data<j->data)
                {
                    temp=i->data;
                    i->data=j->data;
                    j->data=temp;
                }
            }
            
        }
    }
    //################## Update List #####################
    void update(int initial_value, int final_value) {
		int count = 0;
		Node* runner_ptr;
		runner_ptr = head;
		if (runner_ptr == NULL)
		{
			cout << "\nEmpty List.\n";
		}
		while (runner_ptr != NULL)
		{
			if (runner_ptr->data == initial_value)
			{
				runner_ptr->data = final_value;
			}
			count++;
			runner_ptr=runner_ptr->next;
		}
	}
    //########## Search #############
    void search(int value) {
		int count = 0;
		Node* runner_ptr;
		runner_ptr = head;
		if (runner_ptr == NULL)
		{
			cout << "\nEmpty List.\n";
		}
        cout<<"The value is at position ";
		while (runner_ptr != NULL)
		{
			if (runner_ptr->data == value)
			{
				cout <<" -> "<< (count + 1)<<" ";
			}
			count++;
			runner_ptr=runner_ptr->next;
		}
            cout<<"\n";
	}
    //######### Display ##########
    void display()
    {
        Node *temp;
        temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "NULL";
        }
        cout << "\n";
        delete temp;
    }
    //######### Destructor ############
    ~link()
    {
        delete head;
        delete last;
    }
};
int main()
{
    link L;
    L.addRear(1);
    L.addRear(2);
    L.addFront(3);
    L.addRear(10);
    L.addAfter(10, 3);
    L.addRear(6);
    L.addFront(7);
    L.search(10);
    L.display();
    L.delAtBeginning();
    L.display();

    L.dscSortList();
    L.display();

    L.delAtIndex(2);

    L.display();
    L.delAtTail();

    L.display();
    L.ascSortList();
    L.display();

    L.update(10,6);
    L.display();

    L.delByVal(6);
    L.display();


    return 0;
}