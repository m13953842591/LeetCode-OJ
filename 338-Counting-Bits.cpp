#include <iostream>
#include <vector>
using namespace std;


vector<int> countBits(int num) {
    vector<int> v(num + 1,0);
    for(int i = 1; i <= num; i++)
        v[i] = (i % 2)? (v[i - 1] + 1) : v[i / 2];
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> v = countBits(10);
    for(auto it : v)
    {
        cout << it << ' ';
    }
    return 0;
}
