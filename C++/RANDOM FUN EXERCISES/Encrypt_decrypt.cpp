//#include <iostream>
//
//using namespace std;
//
//class Encryption
//{
//public:
//	Encryption() {
//		cout << "*********************ENcryption/decryption********************\n";
//		cout << "Enter the key to encrypt your word(atmost 6 characters long: ";
//		cin >> key;
//		cout << "\nEnter the word to encrypt: ";
//		cin >> word;
//		for (int i = 0; i < 6; i++)			//i is number of letters to encrypt
//		{
//			y=(key+findIndex(word.at(i)))%26;
//			cout <<endl<< i+1<<" letter is : " << letters[y] << endl;
//		}
//	}
//	int findIndex(char seek)
//	{
//		for (int i = 0; i < 26; ++i) {
//			if (letters[i] == seek) return i;
//		}cout << "me nhi batau ga hehehehehehehehehehe\n";
//	}
//private:
//	int key;
//	string word;
//	int y;				//to get index of a char
//	char letters[26]={ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//};
//int main() {
//	Encryption e; return 0;
//}



#include <iostream>
#include<string>
#include<cstring>
using namespace std;

class enc_dec
{
public:
	enc_dec();
	~enc_dec();
	int findIndex(char seek)
		{
			for (int i = 0; i < 26; ++i) {
				if (word[i] == seek) return i;
			}cout << "me nhi batau ga hehehehehehehehehehe\n";
		}
private:
	int key; string word;
};

enc_dec::enc_dec()
{
	cout << "*********************ENcryption/decryption********************\n";
	cout << "Enter the key to encrypt your word(atmost 6 characters long: ";
	cin >> key;
	cout << "\nEnter the word to encrypt: ";
	getline(cin, word);

	for (int i = 0; i < 6; i++)			//i is number of letters to encrypt
	{
		y=(key+findIndex(word.at(i)))%26;
		cout <<endl<< i+1<<" letter is : " << letters[y] << endl;
	}
}

enc_dec::~enc_dec()
{
}