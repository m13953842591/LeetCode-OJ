#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void recursion(vector<int>& nums, vector<int> sset, int i, vector<vector<int>>& res)
{
    
    if(i >= nums.size()) 
    {
        res.push_back(sset);
        return;
    }

    if(sset.empty() || sset.back() != nums[i])
        recursion(nums, sset, i + 1, res);

    sset.push_back(nums[i]);
    recursion(nums, sset, i + 1, res);
    
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)  {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> sset;
    recursion(nums, sset, 0, res);
    return res;
}

int main(int argc, char const *argv[])
{
    int x[3]{1,2,2};
    vector<int> nums(x, x + sizeof(x) / sizeof(int));
    //vector<int> nums;
    vector<vector<int>> res = subsetsWithDup(nums);
    for(auto vec : res)
    {   
        cout << "ans: ";
        for(auto it : vec)
        {
            cout << it << ' '; 
        }
        cout << endl;
    }
    return 0;
}
