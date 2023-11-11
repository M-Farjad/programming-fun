#include<iostream>
#include<fstream>
#include<stack>    //built-in stack
#include<vector>   //built-in vector
#include<string>
using namespace std;

vector<string> gethtmlTags()
{
    string input_line;
    // ifstream file("htmldoc.txt");
    string file;
    ifstream inputfile;
    cout << "Enter name of your file:" << endl;
    getline(cin, file);
    inputfile.open(file);
    if (!inputfile) {
        cout << "File does not exist" << endl;
        exit(-1);
    }

    else
    {
        cout << "Reading data from the file.\n";
        vector<string> tags;

        while (!inputfile.eof())
        {
            getline(inputfile, input_line);
            int pos = 0;
            int ts = input_line.find("<", pos);         //start

            while (ts != string::npos)
            {
                int te = input_line.find(">", ts + 1);
                tags.push_back(input_line.substr(ts, te - ts + 1));      //append tag to vector
                pos = te + 1;
                ts = input_line.find("<", pos);

            }

        }return tags;
    }
}
bool isHtmlMatched(const vector<string>& tags)
{// check for matching tags
    typedef vector<string>::const_iterator Iter;// iterator type->const so you can't moify the container
    // iterate through vector

    stack<string>S;     // stack for opening tags

    for (Iter p = tags.begin(); p != tags.end(); ++p)
    {
        if (p->at(1) != '/') {   // opening tag?
            S.push(*p);// push it on the stack
            string open = S.top().substr(1);
            cout << "<" << open << "\n";
        }
        else
        {// else must be closing tag
            if (S.empty()) // nothing to match - failure
                return false;

            string open = S.top().substr(1);     //opening tag excluding <
            string close = p->substr(2);
         //   cout << "<" << open << endl;
           cout << "</" << close << endl;
            if(open.compare(close) != 0)
            { // fail to match
                cout << "Failed at where " << S.top() << " did not match with " << *p << endl;
                return false;
            }

            else {
                S.pop();// pop matched element

            }

        }
    }

    if (S.empty())
    {
        return true;   // everything matched - good
    }
    else
    {
        cout << " These start tags";
        while (!S.empty()) {
            cout << S.top() << " ";
            S.pop();
        }
        cout << "do not have a matching end tag " << endl;
        return false;  // some unmatched - bad
    }
}

int main()
{
    cout << "/////////////////////////////" << endl;
    if (isHtmlMatched(gethtmlTags()))
    {

        cout << "VALID HTML" << endl;

    }
    else {

        cout << "INVALID HTML" << endl;

    }
    cout << "/////////////////////////////" << endl;
    return 0;
}

