#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {
    int N = nums.size(), len, start, end, coins, bestCoins;
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);

    // rangeValues[i][j] is the maximum # of coins that can be obtained
    // by popping balloons only in the range [i,j]
    vector<vector<int>> rangeValues(nums.size(), vector<int>(nums.size(), 0));
    
    // build up from shorter ranges to longer ranges
    for (len = 1; len <= N; ++len) {
        for (start = 1; start <= N - len + 1; ++start) {
            end = start + len - 1;
            // calculate the max # of coins that can be obtained by
            // popping balloons only in the range [start,end].
            // consider all possible choices of final balloon to pop
            bestCoins = 0;
            for (int final = start; final <= end; ++final) {
                coins = rangeValues[start][final-1] + rangeValues[final+1][end] // coins from popping subranges
                + nums[start-1] * nums[final] * nums[end+1]; // coins from final pop
                if (coins > bestCoins) bestCoins = coins;
            }
            rangeValues[start][end] = bestCoins;
        }
    }
    return rangeValues[1][N];
}

int main(int argc, char const *argv[])
{
    int x[]{3,1,5,8};
    vector<int> v (x,  x + sizeof(x)/sizeof(int));
    cout << maxCoins(v);
    return 0;
}
