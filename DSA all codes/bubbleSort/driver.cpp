#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class BubbleSort
{
    vector<string> array;

public:
    string getFileName()
    {
        string fileName;
        do
        {

            cout << "Enter File Name : ";
            cin >> fileName;

            fstream file;
            file.open(fileName.c_str(), ios::in);

            if (!file)
            {
                cout << "File not Found " << endl;
                cout << "Re-";
            }
            else
            {
                file.close();
                return fileName;
            }
        } while (1);
    }
    BubbleSort()
    {
        string s;
        fstream infile(getFileName().c_str());
        if (infile)
        {
            while (!(infile.eof()))
            {
                infile >> s;
                array.push_back(s);
            }
            bubble_sort();
        }
        else
        {
            cout << "Error opening file ... !";
        }
        infile.close();
    }
    void bubble_sort()
    {
        int pos;
        string temp;
        for (int i = 0; i < array.size(); i++)
        {
            pos = findSmallest(i);
            temp = array[i];
            array[i] = array[pos];
            array[pos] = temp;
        }
    }
    int findSmallest(int i)
    {
        string ele_small;
        int position, j;
        ele_small = array[i];
        position = i;
        for (j = i + 1; j < array.size(); j++)
        {
            if (array[j] < ele_small)
            {
                ele_small = array[j];
                position = j;
            }
        }
        return position;
    }
    void display()
    {

        cout << "The array is: ";
        for (int i = 1; i < array.size(); i++)
        {
            cout << array[i] << endl;
        }
    }
    void writeToFile()
    {
        ofstream outfile("Sorted.txt");
        for (int i = 0; i < array.size(); i++)
            outfile << array[i] << "\n";
        cout << "File created with sorted words ... !" << endl;
    }
};

int main()
{
    BubbleSort obj;
    obj.display();
    obj.bubble_sort();
    obj.display();
    obj.writeToFile();
    return 0;
}