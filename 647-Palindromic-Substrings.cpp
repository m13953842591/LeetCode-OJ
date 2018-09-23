// dynamic programming
#include <iostream>
#include <string>

using namespace std;

int countSubstrings(string s) {
    int N = s.length(), ans = 0;
    for(int center = 0; center < 2 * N - 1; ++center)
    {
        int left = center / 2;
        int right = center / 2 + center % 2; 
        
        while(left >= 0 && right <= N - 1 && s[left] == s[right]){
            left--;
            right++;
            ans++;
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{    /* code */
    return 0;
}
