#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class heap
{
    vector<string> array;

public:
    heap();
    void menu();
    string getFileName();
    int left(int k) { return 2 * k; }
    int right(int k) { return 2 * k + 1; }
    void heapify(int, int);
    void heapSort();
    void display();
    void writeToFile();
};
heap::heap()
{
    string s;
    fstream infile(getFileName().c_str());
    if (infile)
    {
        array.push_back(" ");

        while (!(infile.eof()))
        {
            infile >> s;
            array.push_back(s);
        }
        heapify(array.size(), 1);
    }
    else
    {
        cout << "[WARNING]        Error opening file ... !";
    }
    infile.close();
}
void heap::menu()
{
    cout << "\n##################################################################################################" << endl;
    cout << "1. display words" << endl;
    cout << "2. create sorted word file" << endl;
    cout << "2. display SORTED words" << endl;
    cout << "\n##################################################################################################" << endl;
}
string heap::getFileName()
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
void heap::heapify(int N, int i)
{
    int largest = i;
    if (left(i) < N && array[left(i)] > array[largest])
        largest = left(i);
    if (right(i) < N && array[right(i)] > array[largest])
        largest = right(i);
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(N, largest);
    }
}
void heap::heapSort()
{
    for (int i = array.size() / 2 - 1; i >= 1; i--)
        heapify(array.size(), i);
    for (int i = array.size() - 1; i >= 1; i--)
    {
        swap(array[1], array[i]);
        heapify(i, 1);
    }
}
void heap::display()
{

    cout << "[INFO]        The array is: ";
    for (int i = 1; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }
}

void heap::writeToFile()
{
    ofstream outfile("sortedWords.txt");
    for (int i = 0; i < array.size(); i++)
        outfile << array[i] << "\n";
    cout << "[INFO]       File created with sorted words ... !" << endl;
}