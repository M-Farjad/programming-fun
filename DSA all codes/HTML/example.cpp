// #include <iostream>
// #include <stack>
// #include <vector>
// #include <string>
// using namespace std;

// vector<string> getHtmlTags() {                                      //receives a string of html tags and divide them by "<, >"
//     vector<string> tags;                                            //vector of html tags
//     while (cin) {                                                   //reads the whole input
//         string line;
//         getline (cin,line);
//         int pos = 0;                                                //current scanning position
//         int ts = line.find("<",pos);                                //scans from the current scanning position
//         while (ts!=string::npos) {                                  //repeat until end of string
//             int te = line.find(">", ts+1);                          //scans for the end of a tag (<)
//             tags.push_back(line.substr(ts,te-ts+1));                //save tag to the vector
//             pos = te + 1;                                           //repositioning
//             ts = line.find("<",pos);
//         }
//     }
//     return tags;                                                    //return vector of tags
// }


// bool isHtmlMatched(const vector<string>& tags) {                    //checks if the html tags are correctly matched
//     stack<string> S;                                            //implememted stack from above for opening tags
//     typedef vector<string>::const_iterator Iter;                    //iterate through vector

//     for (Iter p = tags.begin(); p != tags.end(); ++p) {             
//         if (p->at(1) != '/')                                        //is it the opening tag?
//             S.push(*p);                                             //push to the stack
//         else{
//             if (S.empty()) return false;                            //there is nothing to match
//             string open = S.top().substr(1);                        //opening tag excluding '<'
//             string close = p->substr(2);                            //closing tag excluding '>'
//             if (open.compare(close) != 0) return false;             //exception for fail to match
//             else S.pop();                                           //pop matched element

//         }
//     }
//     if (S.empty()) return true;                                     //everything has matched correctly - Correct
//     else return false;                                              //some did not match correctly - Incorrect
// }

// int main() {

//     int rep;                                                        //decides the number of trial
//     cin >> rep;

//     for (int i=1; i<=rep; i++) {                                    //loop up to the decided trial
//         if(isHtmlMatched(getHtmlTags()))
//             cout << "Correct" << endl;
//         else cout << "Incorrect" << endl;
//     }
// }

#include<stack>
#include<fstream>
#include<iostream>
using namespace std;

const string opening = "<*>";
const string closing = "</*>";
string input;



int main()
{
    char element;
    stack<char> stk;
    ifstream file;

    cout << "Please Enter File name: ";
         cin >> input;

    //std::file.open(input);

    file.open(input.c_str());

    if(file.fail())
        cout<<"File is corrupt or does not exists!"<<endl;

    while(!file.eof())
    {
        file>>element;

        //push left group symbols onto stack
        if(element==opening[0])
            stk.push(element);
        else if(element==opening[1])
            stk.push(element);
        else if(element==opening[2])
            stk.push(element);

    }
    file.close();
    file.open(input.c_str());
    while(!file.eof())
    {
        file>>element;

        if(stk.top()==opening[0])
        {
            if(element==closing[0])
                stk.pop();
        }
        else if(stk.top()==opening[1])
        {
            if(element==closing[1])
                stk.pop();
        }
        else if(stk.top()==opening[2])
        {
            if(element==closing[2])
                stk.pop();
        }
    }
    file.close();

    if(!stk.empty())
        cout<<"\nILLEGAL"<<endl;
    else if(stk.empty())
        cout<<"\nLEGAL"<<endl;

    cout << "\n\nProgram complete." <<  endl;
    return 0;
}