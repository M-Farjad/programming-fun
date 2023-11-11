#include <iostream>
using namespace std;
class Array
{
private:
	int* array;
	int size;

public:
	Array() // default constructor
	{
		cout << "Enter the size of the array: ";
		cin >> size;
		array = new int[size];
		cout << "Enter the elements of the array: ";
		for (int i = 0; i < size; i++)
		{
			cin >> array[i];
		}
	}
	void display()
	{
		cout << "The elements of the array are: ";
		for (int i = 0; i < size; i++)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void search()
	{
		int number;
		int index = -1;
		bool check = false;
		cout << "Enter the number you wanna search from array:";
		cin >> number;

		int start = 0;
		int end = size;
		int mid = 0;
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (array[mid] == number)
			{
				index = mid;
				check = true;
				break;
			}
			else if (number > array[mid])
			{
				start = mid + 1;
			}
			else if (number < array[mid])
			{
				end = mid - 1;
			}
		}
		if (check == true)
		{
			cout << endl
				<< number << " is at " << index << " index." << endl;
		}
		else
		{
			cout << "number not found!" << endl;
		}
	}
	void menu()
	{
		int choice;
		do
		{
			cout << "\nwhat do you wanna do?\n";
			cout << " 0: insert an element\n 1: remove an element\n 2: update an element\n 3: Display \n 4: Search from array \n 5: index_at \n 6: Exit \n";
			cin >> choice;

			switch (choice)
			{
			case 0:
				system("cls");
				insert();
				break;
			case 1:
				system("cls");
				remove();
				break;
			case 2:
				system("cls");
				update();
				break;
			case 3:
				system("cls");
				display();
				break;
			case 4:
				system("cls");
				search();
				break;
			case 5:
				system("cls");
				index_at();
				break;
			case 6:
				system("cls");
				exit(0);
			default:
				system("cls");
				cout << "invalid choice.";
				break;
			}
		} while (choice < 0 || choice > 8 || choice != 6);
	}
	void index_at(){
		int element;
		cout << "enter the element, of which you want to find index: ";
		cin >> element;
		bool found = false;

		for (int i = 0; i < size; i++)
		{
			if (array[i] == element) {
				cout << "index at element " << element<<" is "<<i << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << "Element not found.\n";
		}
	}
	void insert()
	{
		cout << "where do you want to enter digit?\n h or t\n";
		char choice;
		cin >> choice;     // head or tale
		if (choice == 'h') // for head
		{
			int digit;
			cout << "enter the digit:";
			cin >> digit;
			size = size + 1;
			int* newArray = new int[size];
			newArray[0] = digit;
			for (int i = 1; i < size; i++)
			{
				newArray[i] = array[i - 1];
			}
			//     display(array,size);
			// cout<<endl;
			int* del = array;
			array = newArray;
			delete[] del;
			// display(array,size);
		}
		else if (choice == 't')
		{ // for tale
			int digit;
			cout << "enter the digit:";
			cin >> digit;
			size = size + 1;
			int* newArray = new int[size];
			newArray[size - 1] = digit;
			for (int i = 0; i < size - 1; i++)
			{
				newArray[i] = array[i];
			}
			int* del = array;
			array = newArray;
			delete[] del;
		}
	}
	void update()
	{
		bool found = false;
		int index;
		int element;
		int number;
		char choice;
		cout << "\n You wanna update an array?\n by index or by element\n i for index\n e for element\n";
		cin >> choice;
		if (choice == 'i')
		{
			do
			{
				cout << "enter the index number.";
				cin >> index;
				
			} while (index > size - 1 || index < 0);

			cout << "enter the new number.";
			cin >> number;
			array[index] = number;
		}
		else if (choice == 'e')
		{
			cout << "enter the element number you wanna update\n";
			cin >> element;

			cout << "enter the new number.";
			cin >> number;

			for (int i = 0; i < size; i++)
			{
				if (array[i] == element)

				{
					array[i] = number;
					found = true; // if found
				}
			}
			if (found)
			{
				cout << "element not found." << endl;
			}
		}
	}
	void remove()
	{
		int choice;
		bool check = false;
		bool found = false;
		int index;
		int number;
		do {
			cout << "you want to delete a number by using index or element.\n 0:index \n 1:element\n";
			cin >> choice;
		} while (choice < 0 || choice > 1);
		if (choice == 1) {
			cout << "enter the number you wanna delete:";
			cin >> number;
			
			do
			{
				check = false;
				for (int i = 0; i < size; i++)
				{
					if (number == array[i])
					{
						check = true;
						break;
					}
					else {
						check = false;
						break;
					}
				}

				for (int i = 0; i < size; i++)
				{
					if (array[i] == number)
					{
						for (int j = i; j < size - 1; j++)
						{
							array[j] = array[j + 1];
						}
						size--;
						found = true;
						break;
					}
				}
			} while (check);
			if (found == false)
			{
				cout << "element does not exist." << endl;
			}
		}
		

		else if (choice == 0) {
			do {
				cout << "\nenter the index number:";
				cin >> index;
			} while (index<0 || index>size - 1);

			for (int i = 0; i < size; i++)
			{
				if (i == (index+1)) {
					for (int j = i; j < size; j++)
					{
						array[i] = array[i + 1];
					}
					size--;
					found = true;
					break;
				}
			}
		}
		
	}
};

int main()
{
	Array array;
	array.menu();

	return 0;
}