#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
         char stk[num.length() + 1];
         int top = 0, stat = 0, digits = num.length() - k; 
         for(int i = 0; i < num.length(); i++)
         {
             while(top > 0 && num[i] < stk[top - 1] && k > 0)
             {
                 --top; --k;
             }
             stk[top++] = num[i];
         }
         stk[top] = '\0';
         while(stat < digits && stk[stat] == '0') ++stat;
         return (stat == digits)? "0": string(stk + stat);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.removeKdigits("9", 1) << endl;
    return 0;
}
