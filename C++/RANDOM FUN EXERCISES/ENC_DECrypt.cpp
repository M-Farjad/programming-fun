//>>---------------------------->> ENCRYPTION <<--------------------------<<

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	cout << "|                                       ||----->> Well Come to Encryption System <<-----||      " << endl;
	cout << "|                                               Here ! You can Encrypt your Data " << endl << endl;
	int key;
	int size;
	int num, num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16, num17, num18, num19, num20, num21, num22, num23, num24, num25;
	int y, y1, y2, y3, y4, y5, y6, y7, y8, y9, y10, y11, y12, y13, y14, y15, y16, y17, y18, y19, y20, y21, y22, y23, y24, y25;
	int a = 0;
	string word;
	cout << "|   Enter the key to Encrypt Your Word into our Secret Code : " << endl;
	cin >> key;
	cout << "Note :   You can not enter the word containing more than 6 alphabets due to shortage of code  " << endl << endl;
	cout << "|   Enter the Word which you wanna want to Encrypt : " << endl;
	cin >> word;
	size = word.length();
	int arr[26] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
	char array[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

	//-------------------------->>  1st Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[0] == array[i])
			{


				num = i;
				cout << num << endl;
				y = (key + num) % 26;

				cout << endl << endl;


				cout << "|                 Here! You have Converted -->  " << word[0] << "  <-- into ---->>  ";

				switch (y)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;

				}
			}
		}
	}

	//-------------------------->>  2nd Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[1] == array[i])
			{


				num1 = i;
				cout << num << endl;
				y1 = (key + num1) % 26;

				cout << endl << endl;



				cout << "|                 Here! You have Converted -->  " << word[1] << "  <-- into ---->>  ";
				switch (y1)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;
				}
			}
		}

	}

	//-------------------------->>  3rd Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[2] == array[i])
			{


				num2 = i;
				cout << num2 << endl;
				y2 = (key + num2) % 26;

				cout << endl << endl;



				cout << "|                 Here! You have Converted -->  " << word[2] << "  <-- into ---->>  ";
				switch (y2)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;
				}
			}
		}

	}
	//-------------------------->>  4th Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[3] == array[i])
			{


				num3 = i;
				cout << num3 << endl;
				y3 = (key + num3) % 26;

				cout << endl << endl;


				cout << "|                 Here! You have Converted -->  " << word[3] << "  <-- into ---->>  ";

				switch (y3)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;

				}
			}
		}

	}

	//-------------------------->>  5th Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[4] == array[i])
			{


				num4 = i;
				cout << num4 << endl;
				y4 = (key + num4) % 26;

				cout << endl << endl;



				cout << "|                 Here! You have Converted -->  " << word[4] << "  <-- into ---->>  ";
				switch (y4)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;
				}
			}
		}

	}

	//-------------------------->>  6th Alphabet   <<----------------------------

	for (int i = 1; i <= 1; i++)
	{
		for (int i = 0; i < 26; i++)
		{

			if (word[5] == array[i])
			{


				num5 = i;
				cout << num5 << endl;
				y5 = (key + num5) % 26;

				cout << endl << endl;



				cout << "|                 Here! You have Converted -->  " << word[5] << "  <-- into ---->>  ";
				switch (y5)
				{
				case 0:
					cout << "A" << endl;
					break;
				case 1:
					cout << "B" << endl;

					break;
				case 2: cout << "c" << endl;

					break;
				case 3: cout << "D" << endl;

					break;
				case 4: cout << "E" << endl;

					break;
				case 5: cout << "F" << endl;

					break;
				case 6: cout << "G" << endl;

					break;
				case 7: cout << "H" << endl;

					break;
				case 8: cout << "I" << endl;

					break;
				case 9: cout << "J" << endl;

					break;
				case 10: cout << "K" << endl;

					break;
				case 11: cout << "L" << endl;

					break;
				case 12: cout << "M" << endl;

					break;
				case 13: cout << "N" << endl;

					break;
				case 14: cout << "O" << endl;

					break;
				case 15: cout << "P" << endl;

					break;
				case 16: cout << "Q" << endl;

					break;
				case 17: cout << "R" << endl;

					break;
				case 18: cout << "S" << endl;

					break;
				case 19: cout << "T" << endl;

					break;
				case 20: cout << "U" << endl;

					break;
				case 21: cout << "V" << endl;

					break;
				case 22: cout << "W" << endl;

					break;
				case 23: cout << "X" << endl;

					break;
				case 24: cout << "Y" << endl;

					break;
				case 25: cout << "Z" << endl;

					break;
				}
			}
		}

	}

	return 0;
}