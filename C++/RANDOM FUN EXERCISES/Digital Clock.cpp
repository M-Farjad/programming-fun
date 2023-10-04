#include<iostream>
#include<windows.h>

using namespace std;

int main()
{
	int hrs,min,sec;
	while(1)
	{
		system("cls");
		for(hrs=0;hrs<23;hrs++)
		{
			for(min=0;min<60;min++)
			{
	
				for(sec=0;sec<60;sec++)
				{
					system("cls");
					cout<<hrs<<":"<<min<<":"<<sec;
					Sleep(1000);
				}
				sec=0;
			}
			min=0;
		}
	}
	return 0;
}
