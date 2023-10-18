//#include<iostream>
//using namespace std;
//
//void matching(string patt)
//{
//	string text = "NMOUTRCFGHKLBE";
//	bool cond = true;
//	int count1 = 0, count2 = 0, sum1 = 0, sum2 = 0, c = 0;
//	char* arr = new char[patt.length()];
//	for (int i = count1; i < text.length() - 3; i++)
//	{
//		c = count1;
//		for (int j = 0; j < patt.length(); j++)
//		{
//			arr[j] = text[c];
//			sum1 += arr[j];
//			sum2 += patt[j];
//			c++;
//		}
//		if (sum1 == sum2)
//		{
//			for (int j = count1; j < patt.length(); j++)
//			{
//				if (arr[j] == text[j])
//				{
//					cond = true;
//				}
//				else
//					cond = false;
//			}
//			if (cond)
//				count2++;
//		}
//		count1++;
//	}
//	cout << count2;
//}
//int main()
//{
//	matching("TDX");
//}









