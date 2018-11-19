#include <string>
#include <iostream>
using namespace std;


    bool isSubsequence(string s, string t) {
        int i, j = 0;
        for(i = 0; i < t.length(); i++)
        {
            if(j < s.length() && s[j] == t[i]) j++;
        }
        return (j == s.length());
    }


int main(int argc, char const *argv[])
{
    string s = "abc", t = "ahbgdc";
    cout << isSubsequence(s,t) << endl;

    return 0;
}
