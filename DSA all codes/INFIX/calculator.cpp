#include<iostream>
using namespace std;





//>>>
// #include <iostream>
// #include <fstream>
// #include <conio.h>
// #include <vector>
// #include <iterator>
// #include <string>
// using namespace std;

// class StNode
// {
// private:
//     string data;
//     StNode *next;

// public:
//     StNode(string val = 0) : data(val)
//     {
//         next = NULL;
//     }
//     ~StNode() {}
//     friend class StackLL;
// };
// class StackLL
// {
// private:
//     StNode *head;

// public:
//     bool isEmpty()
//     {
//         return head == NULL;
//     }
//     StackLL()
//     {
//         head = NULL;
//     }
//     string top()
//     {
//         return head->data;
//     }
//     string pop()
//     {
//         if (isEmpty())
//             cout << "Stack Already Empty ... !";
//         else
//         {
//             StNode *tempN = head;
//             string temp = head->data;
//             head = head->next;
//             delete tempN;
//             return temp;
//         }
//         return 0;
//     }
//     void push(string val)
//     {
//         StNode *node = new StNode(val);
//         node->next = head;
//         head = node;
//     }
//     void display()
//     {
//         StNode *temp = head;
//         cout << "List : ";
//         while (temp != NULL)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << "\n";
//     }
// };
// // int main()
// // {
// //     StackLL HtmlStack;
// //     fstream inputFile;
// //     inputFile.open("html.txt", ios::in);
// //     if (inputFile)
// //     {
// //         string tag;
// //         while (inputFile >> tag)
// //         {
// //         }
// //     }
// //     return 0;
// // }

// vector<string> getHtmlTags()
// {                        // store tags in a vector
//     vector<string> tags; // vector of html tags
//     fstream inputFile;
//     inputFile.open("html.txt", ios::in);
//     if (inputFile)
//     {
//         string line;
//         while (inputFile >> line)
//         {
//             getline(inputFile, line);     // input a full line of text
//             int pos = 0;                  // current scan position
//             int ts = line.find("<", pos); // possible tag start
//             while (ts != string::npos)
//             {                                                 // repeat until end of string
//                 int te = line.find(">", ts + 1);              // scan for tag end
//                 tags.push_back(line.substr(ts, te - ts + 1)); // append tag to the vector
//                 pos = te + 1;                                 // advance our position
//                 ts = line.find("<", pos);
//             }
//         }
//     }
//     else
//         cout<<"file opening error";
//     // while (cin)
//     // { // read until end of file
//     //     string line;
//     //     getline(cin, line);           // input a full line of text
//     //     int pos = 0;                  // current scan position
//     //     int ts = line.find("<", pos); // possible tag start
//     //     while (ts != string::npos)
//     //     {                                                 // repeat until end of string
//     //         int te = line.find(">", ts + 1);              // scan for tag end
//     //         tags.push_back(line.substr(ts, te - ts + 1)); // append tag to the vector
//     //         pos = te + 1;                                 // advance our position
//     //         ts = line.find("<", pos);
//     //     }
//     // }
//     return tags; // return vector of tags
// }

// bool isHtmlMatched(const vector<string> &tags)
// {
//     StackLL S;                                   // stack for opening tags
//     typedef vector<string>::const_iterator Iter; // iterator type
//     // iterate through vector
//     for (Iter p = tags.begin(); p != tags.end(); ++p)
//     {
//         if (p->at(1) != '/') // opening tag?
//             S.push(*p);      // push it on the stack
//         else
//         { // else must be closing tag
//             if (S.isEmpty())
//                 return false;                // nothing to match - failure
//             string open = S.top().substr(1); // opening tag excluding ’<’
//             string close = p->substr(2);     // closing tag excluding ’</’
//             if (open.compare(close) != 0)
//                 return false; // fail to match
//             else
//                 S.pop(); // pop matched element
//         }
//     }
//     if (S.isEmpty())
//         return true; // everything matched - good
//     else
//         return false; // some unmatched - bad
// }
// int main()
// {                                     // main HTML tester
//     if (isHtmlMatched(getHtmlTags())) // get tags and test them
//         cout << "The input file is a matched HTML document." << endl;
//     else
//         cout << "The input file is not a matched HTML document." << endl;
// }



//<<<


class StNode
{
private:
    int data;
    StNode *next;
public:
    StNode(int val=0) : data(val){
        next = NULL;
    }
    ~StNode() {}
    friend class StackLL;
};
class StackLL
{
private:
    StNode *head;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    StackLL(){
        head = NULL;
    }
    int top()
    {
        return head->data;
    }
    int pop()
    {
        if (isEmpty())
            cout << "Stack Already Empty ... !";
        else
        {
            StNode *tempN = head;
            int temp = head->data;
            head = head->next;
            delete tempN;
            return temp;
        }
        return 0;
    }
    void push(int val){
        StNode* node = new StNode(val);
        node->next=head;
        head=node;
    }
    void display(){
        StNode* temp = head;
        cout<<"List : ";
        while (temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};

int main(){

    return 0;
}