#include <iostream>
#include <string>
using namespace std;

//class declarations
class Book {
	string Name;
	int price;
	int T_pages;	
public:
	Book(string, int, int);
	string getName() {
		return Name;
	}
	int getpages() {
		return T_pages;
	}
	int getPrice() {
		return price;
	}
};
Book::Book(string s,int Price,int pages) {

	Name = s;
	price = Price;
	T_pages = pages;
}
int main() {
	Book b1("Hello World", 50000, 455);
	cout << "The name of book is: " << b1.getName() << endl;
	cout << "The price of book is: " << b1.getPrice() << endl;
	cout << "the total no of pages are: " << b1.getpages() << endl;
	return 0;

}