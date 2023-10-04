#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> arr;
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
            arr.push_back("FizzBuzz");
        else if (i % 3 == 0)
            arr.push_back("Fizz");
        else if (i % 5 == 0)
            arr.push_back("Buzz");
        else
        {
            string x = "";
            int z = i;
            while (z)
            {
                x += to_string(z % 10);
                z /= 10;
            }
            reverse(x.begin(), x.end());
            arr.push_back(x);
        }
    }
    return arr;
}
int main()
{
    vector<string> arr = fizzBuzz(15);
    for (int i = 0; i < 15; i++)
    {
        cout << arr[i] << endl;
    }
}