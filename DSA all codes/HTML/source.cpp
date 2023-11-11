//DSA THEORY ASSIGNMENT
#include<iostream>
#include"HTMLTAGS.h"
using namespace std;
int main() {
    HTMLTAGS obj;
    obj.readFile();
    obj.getTags();
    if (obj.checkErrors())
        cout << endl << "|         TAGS MATCHED              |" << endl;
    else
        cout << endl << "|         TAGS NOT MATCHED          |" << endl;

    return 0;
}




















// #pragma once
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <string>
// #include <conio.h>
// #include <stack>
// using namespace std;
// class HTMLTAGS
// {
//     string fileData;
//     vector<string> tags;

// public:
//     HTMLTAGS(string s = ""):fileData(s){}
//     void readFile();
//     bool isOpeningTag(string); 
//     bool isClosingTag(string);
//     string getTagName(string);
//     string getTagWithoutSpace(string);
//     void printTabs(int);
//     void getTags();
//     bool checkErrors();
// };


// string HTMLTAGS::getTagWithoutSpace(string s)
// { // if extra space is present in tags it will be removed
//     string tag = "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == ' ')
//             continue;
//         tag += s[i];
//     }
//     return tag;
// }
// bool HTMLTAGS::isOpeningTag(string tag)
// {
//     tag = getTagWithoutSpace(tag); // if extra space is present in tags it will be removed
//     return (tag[1] != '/');
// }

// bool HTMLTAGS::isClosingTag(string tag)
// {
//     tag = getTagWithoutSpace(tag); // if extra space is present in tags it will be removed
//     return (tag[1] == '/');
// }

// string HTMLTAGS::getTagName(string tag)
// {
//     string tagName = "";
//     for (int i = 0; i < tag.length(); i++)
//     {
//         if (tag[i] == ' ' || tag[i] == '<' || tag[i] == '>' || tag[i] == '/')
//         {
//             continue;
//         }
//         tagName += tag[i];
//     }
//     return tagName;
// }
// void HTMLTAGS::printTabs(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         cout << "\t";
//     }
// }
// void HTMLTAGS::getTags()
// {
//     while (!tags.empty())
//     { // to clean the vector
//         tags.pop_back();
//     }
//     int len = fileData.length(); // length function will be called only once
//     for (int i = 0; i < len; i++)
//     {
//         string tag = "";
//         if (fileData[i] == '<')
//         {
//             while ((i < len))
//             {
//                 tag += fileData[i];
//                 if (fileData[i] == '>')
//                 {
//                     break;
//                 }
//                 i++;
//                 if (fileData[i] == '<')
//                 {
//                     tag = ""; // to ignore the previous incomplete tag
//                     continue;
//                 }
//             }
//             tags.push_back(tag);
//             tag = ""; // clear the previous tag
//         }
//     }
// }

// bool HTMLTAGS::checkErrors()
// {
//     stack<string> st;
//     int len = tags.size();
//     bool match = true; // to check error is found
//     for (int i = 0; i < len; i++)
//     {
//         if (isOpeningTag(tags[i]))
//         {
//             printTabs(st.size());
//             cout << tags[i] << endl;
//             st.push(tags[i]);
//         }
//         else if (isClosingTag(tags[i]))
//         {
//             if (st.empty())
//             {
//                 cout << "|    Missing Tag:  <" << getTagName(tags[i]) << ">       |" << endl; // opening tag is missing
//                 match = false;
//                 cout << tags[i] << endl;
//             }
//             else if (getTagName(st.top()) == getTagName(tags[i]))
//             {
//                 st.pop();
//                 printTabs(st.size());
//                 cout << tags[i] << endl;
//             }
//             else if (getTagName(st.top()) != getTagName(tags[i]))
//             {
//                 bool flag = false;
//                 // opeing miss      //compare with st.top
//                 for (int j = i + 1; j < len; j++)
//                 {
//                     if (isClosingTag(tags[j]) && getTagName(st.top()) == getTagName(tags[j]))
//                     {
//                         // opening of tags[i] miss
//                         match = false;
//                         cout << "|    Missing Tag:  <" << getTagName(tags[i]) << ">       |" << endl;
//                         flag = true;
//                         break;
//                     }
//                     else if (isOpeningTag(tags[j]) && getTagName(st.top()) == getTagName(tags[j]))
//                     {
//                         // closing of st.top() miss
//                         match = false;
//                         cout << "|    Missing Tag:  </" << getTagName(st.top()) << ">       |" << endl;
//                         st.pop();
//                         i--; // not to skip the current closing tag
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if (!flag)
//                 { // niether opening next nor closing of st.top() found
//                     // closing of st.top() miss
//                     match = false;
//                     cout << "|      Missing Tag:  </" << getTagName(st.top()) << ">       |" << endl;
//                     st.pop();
//                     i--; // not to skip the current closing tag
//                 }
//             }
//         }
//     }
//     while (!st.empty())
//     { // check if some opening tags are left in the stack
//         match = false;
//         cout << "|     Missing Tag:  </" << getTagName(st.top()) << ">       |" << endl;
//         st.pop();
//     }
//     return match;
// }
// void HTMLTAGS::readFile()
// {
//     fileData = "";    // remove previous data
//     string name;      // to hold the name of the file
//     fstream readFile; // to read the file
//     bool flag = true; // to re ask filename if file is not open
//     do
//     {
//         cout << "Enter the name of file: ";
//         flag = true; // to re ask filename if file is not open
//         getline(cin, name);

//         readFile.open(name.c_str());
//         if (readFile)
//         {
//             while (!readFile.eof())
//             {
//                 string temp;
//                 getline(readFile, temp);
//                 fileData += temp;
//                 fileData += "\n";
//             }
//         }
//         else
//         {           // if fail to open file re ask to enter file name
//             char c; // for choice
//             cout << "Failed to open the file." << endl;
//             do
//             {
//                 cout << "Do you want to re enter the file name " << endl;
//                 cout << " 1- Yes. " << endl;
//                 cout << " 2- NO. " << endl;
//                 cin >> c;
//                 if (c == '1')
//                     flag = false;
//                 else if (c == '2')
//                     exit(0);
//             } while (!(c == '1' || c == '2'));
//         }
//     } while (!flag);
// }