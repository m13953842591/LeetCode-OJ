#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2) {
    int m = num1.size(), n = num2.size(), pos;
    vector<int> v(m + n , 0);
    string sum;
    for(int i = m - 1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--)
        {
            pos = i + j + 1;
            v[pos] += (num1[i] - '0') * (num2[j] - '0');
            v[pos - 1] += v[pos] / 10;
            v[pos] %= 10;
        }
    for(auto p : v)
        if(!(sum.size() == 0 && p == 0))
            sum += p + '0';
    
    return (sum.size() == 0)? "0" : sum;
}



int main(int argc, char const *argv[])
{
    cout << multiply("123456", "0");
    return 0;
}
