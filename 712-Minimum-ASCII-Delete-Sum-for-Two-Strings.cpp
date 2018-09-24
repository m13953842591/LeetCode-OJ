#include <iostream>
#include <vector>
#include <string>
using namespace std;


int minimumDeleteSum(string s1, string s2) {
    int s[s1.length() + 1][s2.length() + 1]{0};
    
    for(int i = s1.length() - 1; i >= 0; i--)
        s[i][s2.length()] = s[i + 1][s2.length()] + s1[i];
    for(int j = s2.length() - 1; j >= 0; j--)
        s[s1.length()][j] = s[s1.length()][j+1] + s2[j];
    for(int i = s1.length() - 1; i >= 0; i--)
        for(int j = s2.length() - 1; j >= 0; j--)
        {
            if(s1[i] == s2[j])
                s[i][j] = s[i + 1][j + 1];
            else 
                s[i][j] = min(s[i + 1][j] + s1[i], s[i][j + 1] + s2[j]);
        }
    return s[0][0];
}

int main(int argc, char const *argv[])
{
    cout << minimumDeleteSum("delete", "leet");
    return 0;
}
