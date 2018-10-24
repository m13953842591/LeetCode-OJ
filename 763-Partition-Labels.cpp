#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;


vector<int> partitionLabels(string S) {
    
    int last[26] = {0};
    
    for(int i = S.length() - 1; i >= 0; i--)
    {
        if(last[S[i] - 'a'] < i)
            last[S[i] - 'a'] = i;
    }

    int anchor = 0, end = last[S[0] - 'a'];
    vector<int> ans;
    for(int i = 0; i < S.length(); i++)
    {
        if(i <= end && last[S[i] - 'a'] > end)
            end = last[S[i] - 'a'];
        else if(i > end)
        {
            ans.push_back(end - anchor + 1);
            anchor = i;
            end = last[S[i] - 'a'];
        }
    }
    ans.push_back(end - anchor + 1);
    return ans;
}
int main(int argc, char const *argv[])
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(s);
    for(auto it: ans) cout << it << ' ';
    return 0;
}
