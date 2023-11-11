#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<fstream>


using namespace std;


vector<string> getHTMLtags()
{
	vector<string> tags;
	string filename;
	cout << "enter the file name:";
	while(!(cin >> filename)){
		cout<<"Enter a valid name: ";
		cin.clear();
	};
	ifstream read;
	read.open(filename);

	if (read)
	{
		while (read)
		{
			string line;
			getline(read, line);
			int pos = 0;
			int ts = line.find("<", pos);
			while (ts != string::npos)
			{
				int te = line.find(">", ts + 1);
				tags.push_back(line.substr(ts, te - ts + 1));

				pos = te + 1;
				ts = line.find("<", pos);
			}
		}

	}
	else
		cout << "unable to open file\n";
	read.close();
	return tags;

}

bool isHtmlMatched(const vector<string>& tags)
{
	stack<string> S;		
	typedef vector<string>::const_iterator Iter;
	for (Iter p = tags.begin(); p != tags.end(); ++p)
	{
		if (p -> at(1) != '/')    
			S.push(*p); 
		else {										
			if (S.empty())
				return false; 

			string open = S.top().substr(1); 
			string close = p -> substr(2); 

			if (open.compare(close) != 0)

				return false; 

			else S.pop(); 
		}
	}
	if (S.empty()) return true; 
	else return false; 

}

int main()
{
	vector<string>::iterator iter;
	//getHTMLtags();
	vector<string> String_of_tags;
	String_of_tags = getHTMLtags();
	if (isHtmlMatched(String_of_tags))
	{
		cout << "balanced\n";
		for (int i = 0; i < String_of_tags.size(); i++)
		{
			cout << String_of_tags[i] << endl;
		}

	}
	else
		cout << "unbalanced";
		return 0;
}