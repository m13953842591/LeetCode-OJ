#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std; 

void dfs(vector<vector<int>> &res, map<int, int>& dict, vector<int>& current, int depth)
{
    if(depth == 0)
    {
        res.push_back(current);
        return;
    }
    
    for(auto itr = dict.begin(); itr != dict.end(); itr++)
    {
        if (itr->second != 0)
        {
            itr->second--;
            current.push_back(itr->first);
            dfs(res, dict, current, depth - 1);
            itr->second++;
            current.pop_back();
        }
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    map<int, int> dict;
    vector<vector<int>> res;
    vector<int> current;
    for(int i = 0; i < nums.size(); i++)
    {
        if(dict.find(nums[i]) != dict.end())
            dict[nums[i]] += 1;
        else dict[nums[i]] = 1;
    }
    dfs(res, dict, current, nums.size());
    return res;
}

int main()
{
    int x[] = {1,2,2,3,3,4};
    vector<int> nums(x, x + sizeof(x)/ sizeof(int));
    vector<vector<int>> res = permuteUnique(nums);
    for(auto permute : res)
    {
        cout << "[";
        for(auto x : permute)
            cout << x << ", ";
        cout << "]\n";
    }
    return 0;
}