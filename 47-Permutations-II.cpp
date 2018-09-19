// underfinished
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void recursion(vector<int> nums, int begin, vector<vector<int>> &res)
{
    if(begin >= nums.size() - 1)
    {
        res.push_back(nums);
        return;
    }
    for(int i = begin; i < nums.size(); i++)
    {
        swap(nums[i], nums[begin]);
    }
    
}

vector<vector<int>> permuteUnique(vector<int> & nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    recursion(nums, 0, res);
    return res;
}

int main(int argc, char const *argv[])
{
    int x[4]{1,2,3,4};
    vector<int> nums(x, x + sizeof(x) / sizeof(int));
    for(auto it : nums)
    cout << it << ' ';
    vector<vector<int>> res = permuteUnique(nums);
    for(auto vec : res)
    {
        for(auto it : vec)
        {
            cout << it << ' '; 
        }
        cout << endl;
    }
    return 0;
}

