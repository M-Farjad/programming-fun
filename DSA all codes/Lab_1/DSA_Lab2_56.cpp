#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next_Node_Ptr;
	Node()
	{
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
	}

};

class SinglyList {
public:
	Node* head_Ptr;
    ~SinglyList(){
        delete head_Ptr;
    }
	SinglyList()
	{
		head_Ptr = NULL;
	}
	bool Empty()
	{
		return (head_Ptr == NULL);
	}
	void inser_Node_At_End(Node* newNode)
	{
		if (head_Ptr == NULL)
		{
			head_Ptr = newNode;
		}
		else
		{
			Node* runner_Ptr;
			runner_Ptr = head_Ptr;

			while (runner_Ptr->next_Node_Ptr != NULL)
			{
				runner_Ptr = runner_Ptr->next_Node_Ptr;
			}
			runner_Ptr->next_Node_Ptr = newNode;
		}
	}
	void inser_Node_At_Head(Node* newNode)
	{
		newNode->next_Node_Ptr = head_Ptr;
		head_Ptr = newNode;
	}
	void inser_Node_At_AnyPoint(Node* newNode, int count)
	{
		if (head_Ptr == NULL)
		{
			head_Ptr = newNode;
		}
		else
		{
			Node* runner_Ptr;
			runner_Ptr = head_Ptr;

			for (int i = 1; i < count; i++)
			{
				runner_Ptr = runner_Ptr->next_Node_Ptr;
			}
			newNode->next_Node_Ptr = runner_Ptr->next_Node_Ptr;
			runner_Ptr->next_Node_Ptr = newNode;
		}
	}

	void del_At_Start() {
		Node* temp;
		temp = head_Ptr;
		head_Ptr = head_Ptr->next_Node_Ptr;
		temp->next_Node_Ptr = NULL;
		delete temp;
	}

	void del_At_End() {
		Node* temp;
		Node* runner_ptr;
		runner_ptr = head_Ptr;
		while (runner_ptr->next_Node_Ptr->next_Node_Ptr != NULL)
		{
			runner_ptr = runner_ptr->next_Node_Ptr;
		}
		temp = runner_ptr->next_Node_Ptr;
		runner_ptr->next_Node_Ptr = NULL;
		delete temp;
	}

	void del_At_Any_Position(int position) {
		Node* temp;
		Node* runner_Ptr;
		runner_Ptr = head_Ptr;
		temp = runner_Ptr;

		for (int i = 0; i < position-2; i++)
		{
			runner_Ptr = runner_Ptr->next_Node_Ptr;
		}
		temp = runner_Ptr->next_Node_Ptr;
		runner_Ptr->next_Node_Ptr = runner_Ptr->next_Node_Ptr->next_Node_Ptr;
		temp->next_Node_Ptr = NULL;
		delete temp;
	}

	void update(int initial_value, int final_value) {
		int count = 0;
		Node* runner_ptr;
		runner_ptr = head_Ptr;
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
			runner_ptr=runner_ptr->next_Node_Ptr;
		}
	}
	void search(int value) {
		int count = 0;
		Node* runner_ptr;
		runner_ptr = head_Ptr;
		if (runner_ptr == NULL)
		{
			cout << "\nEmpty List.\n";
		}
		while (runner_ptr != NULL)
		{
			if (runner_ptr->data == value)
			{
				cout << "The value is at position " << (count + 1) << endl;
			}
			count++;
			runner_ptr=runner_ptr->next_Node_Ptr;
		}
	}
	void display()
	{
		Node* runner_Ptr;
		runner_Ptr = head_Ptr;

		while (runner_Ptr != NULL)
		{
			cout << runner_Ptr->data << "    ";
			runner_Ptr = runner_Ptr->next_Node_Ptr;
		}
	}

};

int main()
{
	SinglyList l1;
	cout << "List Created.\n";
	l1.inser_Node_At_End(new Node(4));
	l1.inser_Node_At_End(new Node(8));
	l1.inser_Node_At_End(new Node(7));
	l1.inser_Node_At_End(new Node(9));
	l1.inser_Node_At_End(new Node(12));
	l1.inser_Node_At_Head(new Node(3));
	l1.inser_Node_At_AnyPoint(new Node(5), 2);

	l1.display();
	cout << "\n\n";
	cout << "Delete at the start.\n";
	l1.del_At_Start();
	l1.display();
	
	cout << "\n\n";
	cout << "Delete at the end.\n";
	l1.del_At_End();
	l1.display();

	cout << "\n\n";
	cout << "Delete at any position.\n";
	l1.del_At_Any_Position(2);
	l1.display();


	cout << "\n\n";
	cout << "Searching.\n";
	l1.search(9);
	l1.display();

	cout << "\n\n";
	cout << "Updation.\n";
	l1.update(9,6);
	l1.display();
	cout << "\n\n";
	return 0;
}