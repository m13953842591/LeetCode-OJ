#include <iostream>
#include <vector>
using namespace std;


int maxCoins(vector<int>& nums) {
    int target, res = 0;
    while(nums.size() > 2)
    {
        for(auto it : nums)
            cout << it << ' ';
        cout << endl;
        target = 1;
        for(int i = 1; i < nums.size() - 1; i++)
        {
            if(nums[i] < nums[target])
                target = i;
        }
        res += nums[target - 1] * nums[target] * nums[target + 1];
        nums.erase(nums.begin() + target);
    }
    switch(nums.size())
    {
        case 0: return 0;
        case 1: return nums[0];
        case 2: 
        return res + nums[0] * nums[1] + max(nums[0], nums[1]);
    }
}

int main(int argc, char const *argv[])
{
    int x[]{3,1,5,8};
    vector<int> v (x,  x + sizeof(x)/sizeof(int));
    cout << maxCoins(v);
    return 0;
}
