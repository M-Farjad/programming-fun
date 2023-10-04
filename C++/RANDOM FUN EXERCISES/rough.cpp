#include<iostream>
#include<cctype>
#include<string>
using namespace std;
class Encryptor {
	int key;
	string givenWord;
	char *encryptedWord=nullptr;
	int sizeOfWord;
	char arrOfalpha[26] = { 'a','b','c','d', 'e','f', 'g','h', 'i','j', 'k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
public:
	void getEncrypteArray() {
		for (int i = 0; i < sizeOfWord; i++)
		{	for (int j = 0; j < 26; j++){
			if (toupper(givenWord[i]) == toupper(arrOfalpha[j])){
				encryptedWord[i] = (arrOfalpha[((j + key) % 26)]);
				break;
			}
			}
		}
	}
	void printEncryptedArray(){
		for (int i = 0; i < sizeOfWord; i++){
			cout << encryptedWord[i];
		}
	}
	Encryptor(string wrd="\0", int k = 0) {
		key = k;
		givenWord = wrd;
		sizeOfWord = givenWord.length();
		encryptedWord = new char[sizeOfWord];
		getEncrypteArray();
	}
};
int main(){
	Encryptor test("cAt", 9);
	test.printEncryptedArray();
}