#include <iostream>
#include <stack>
#include <string>

using namespace std;

int longestValidParentheses(string s) {
    stack<char> q;
    bool isContinuous = false;
    int maxLength = 0, curLength = 0; 
    for(int i = 0; i < s.length(); i++)
    {
        if(q.empty()){
            cout << "get a empty stack\n";
            if(s[i] == '(') q.push(s[i]);
            else isContinuous = false;
            continue;
        }
        if(q.top() == '(' && s[i] == ')')
        {
            cout << "get a parentheses\n";
            q.pop();
            if(!isContinuous) 
            {
                isContinuous = true;
                curLength = 2;
            }
            else curLength+=2;
            maxLength = max(maxLength, curLength);
        }
        else{
            cout << "get unmatched\n";
            q.push(s[i]);
        }
        cout << "curlengh = " << curLength << endl;
    }
    return maxLength;
}

int main()
{
    string s("()(())");
    cout << longestValidParentheses(s) << endl;
    return 0;
}