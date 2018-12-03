#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    char x_fx[26], fx_x[26];
    bool match;
    vector<string> res;
    for(int i = 0; i < words.size(); i++)
    {
        memset(x_fx, 0, 26 * sizeof(char));
        memset(fx_x, 0, 26 * sizeof(char));
        match = true;
        for(int j = 0; j < pattern.length(); j++)
        {
            if(x_fx[pattern[j] - 'a'] == 0 && fx_x[words[i][j] - 'a'] == 0)
            {
                x_fx[pattern[j] - 'a'] = words[i][j];
                fx_x[words[i][j] - 'a'] = pattern[j];
            }
            else{
                if(x_fx[pattern[j] - 'a'] != words[i][j] || fx_x[words[i][j] - 'a'] != pattern[j])
                {
                    match = false;
                    break;
                } 
            }
        }
        if(match)
            res.push_back(words[i]);
    }
    return res;
}