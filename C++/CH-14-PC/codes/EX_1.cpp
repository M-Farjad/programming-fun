#include<iostream>
#include<string>
using namespace std;

class Numbers {
	int number;
	static string lessThanTwenty[20];
	static string tens[8];
	static string hundred;
	static string thousand;
public:
	Numbers(int number) {
		(*this).number = number;
	}
	void print() {
		string num = to_string(number);		//Convert int to string
		string r1, r2, r3;

		cout << "====================" << endl;
		cout << "NUMBER IN WORDS" << endl;
		cout << "====================" << endl;

		if (number < 19)
			cout << lessThanTwenty[number] << endl;

		else if (number >= 20 && number <= 99) {
			r1 = num.at(1);
			if (r1 == "0")				//suppose it is 30
				cout << tens[(number / 10) - 2] << endl;
			else
				cout << tens[(number / 10) - 2] << " " << lessThanTwenty[number % 10] << endl;
		}

		else if (number >= 100 && number <= 999) {
			r1 = num.at(1);
			r2 = num.at(2);
			if (r1 == "0" && r2 == "0") {		//600
				cout << lessThanTwenty[number / 100] << " " << hundred << endl;
			}
			else if (r1 == "0") {				//605
				cout << lessThanTwenty[number / 100] << " " << hundred << ", and"
					<< lessThanTwenty[((number % 100) % 10)] << endl;
			}
			else if (r2 == "0") {				//650, 610
				cout << lessThanTwenty[number / 100] << " " << hundred << ", ";
				if (number % 100 <= 19)			//610
					cout << lessThanTwenty[number % 100] << endl;
				else                            //650
					cout << tens[((number % 100) / 10) - 2] << " " << endl;
			}
			else {								//675,619
				cout << lessThanTwenty[number / 100] << " " << hundred << ", ";
				if (number % 100 <= 19)			//618,619
					cout << lessThanTwenty[number % 100] << endl;
				else {							//675
					cout << tens[((number % 100) / 10) - 2] << " ";
					cout << lessThanTwenty[((number % 100) % 10)] << endl;
				}
			}
		}

		else {
			r1 = num.at(1);
			r2 = num.at(2);
			r3 = num.at(3);
			if (r1 == "0" && r2 == "0" && r3 == "0") {		//6000
				cout << lessThanTwenty[number / 1000] << " " << thousand << endl;
			}
			else if (r2 == "0" && r3 == "0") {				//6400
				cout << lessThanTwenty[number / 1000] << " " << thousand << ", " <<
					lessThanTwenty[(number % 1000) / 100] << " " << hundred << endl;
			}
			else if (r1 == "0" && r2 == "0") {				//6005
				cout << lessThanTwenty[number / 1000] << " " << thousand << ", and " <<
					lessThanTwenty[number % 1000] << endl;
			}
			else if (r1 == "0") {							//6045, 6015
				cout << lessThanTwenty[number / 1000] << " " << thousand << ", and ";
				if (((number % 1000) % 100) <= 19)			//6015
					cout << lessThanTwenty[(number % 1000) % 100] << endl;
				else {										//6045
					cout << tens[(((number % 1000) % 100) / 10) - 2] << " " <<
						lessThanTwenty[(((number % 1000) % 100) % 10)] << endl;
				}
			}
			else {											//6378, 6315, 6306
				cout << lessThanTwenty[number / 1000] << " " << thousand << ", " <<
					lessThanTwenty[(number % 1000) / 100] << " " << hundred << ", and ";
				if (((number % 1000) % 100) <= 19)			//6315, 6309
					cout << lessThanTwenty[(number % 1000) % 100] << endl;
				else {										//6378
					cout << tens[(((number % 1000) % 100) / 10) - 2] << " " <<
						lessThanTwenty[(((number % 1000) % 100) % 10)] << endl;
				}
			}
		}
	}
};
string Numbers::lessThanTwenty[20] = { "Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten",
"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
string Numbers::tens[8] = { "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

int main() {
	int num;
	char choice;
	cout << "====CONVERT DIGITS TO WORDS====" << endl;

	do {
		cout << "Enter any number in the range of(0 - 9999) : ";
		cin >> num;
		if (num < 0 || num>9999) {
			do {
				cout << "Invalid Number" << endl;
				cout << "Enter the number again: ";
				cin >> num;
			} while (num < 0 || num>9999);
		}
		Numbers n(num);
		n.print();

		cout << "Press 'Y' or 'y' if you want to convert any more number: ";
		cin >> choice;
		cout << endl << endl;
	} while (choice == 'Y' || choice == 'y');
}