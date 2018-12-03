#include <iostream>
#include <vector>
#include <map>
using namespace std;
void swap(int &a, int &b)
{int tmp = a; a = b; b = tmp;}

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    bool flag = true;
    const int N = Profits.size();
    if(N == 0) return W;
    bool vis[N] = {false};
    while(flag)
    {
        flag = false;
        for(int i = 0; i < N - 1; i++)
        {
            if(Profits[i] < Profits[i + 1])
            {
                swap(Profits[i], Profits[i + 1]);
                swap(Capital[i], Capital[i + 1]);
                flag = true;
            }
        }
    }
    while(k > 0)
    {
        int i;
        for(i = 0; i < N; i++)
        {
            if(!vis[i] && W >= Capital[i]){
                W += Profits[i];
                --k;
                vis[i] = true;
                break;
            }
        }
        if(i == N) break;
    }
    return W;
}
int main(int argc, char const *argv[])
{
    vector<int> cap({0, 1, 1});
    vector<int> pro({1, 2, 3});
    cout << findMaximizedCapital(2, 0, pro, cap) << endl;
    return 0;
}
