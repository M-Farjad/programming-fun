#include <iostream>
#include <stack>

using namespace std;

class Solution
{

public:
    // bool isValid(string s) {
    //     stack<char> st;
    //     for(auto c:s){
    //         if(c=='('||c=='{'||c=='[') st.push(c);
    //         else if(st.empty()) return false;
    //         else if(c==')'){
    //             if(st.top()!='(')return false;
    //             st.pop();
    //         }
    //         else if(c=='}'){
    //             if(st.top()!='{') return false;
    //             st.pop();
    //         }
    //         else if(c==']'){
    //             if(st.top()!='[') return false;
    //             st.pop();
    //         }
    //     }
    //     if(st.empty()) return true;
    //     return false;
        
    // }
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c:s)
        {
            if (c == '{' || c == '[' || c == '(')
                st.push(c);
            else if(st.empty()) return 0;
            else if (c == '}')
            {
                if (st.top() == '{')
                    st.pop();
                else
                    return 0;
            }
            else if (c == ']')
            {
                if (st.top() == '[')
                    st.pop();
                else
                    return 0;
            }
            else if (c == ')')
            {
                if (st.top() == '(')
                    st.pop();
                else
                    return 0;
            }
        }
        if (st.empty())
            return 1;
        return 0;
    }
};
int main()
{
    Solution obj;
    cout << obj.isValid("()[]{}");
}