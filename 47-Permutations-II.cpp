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
    for()
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    map<int, int> dict;
    vector<vector<int>> res;
    for(int i = 0; i < nums.size(); i++)
    {
        if(dict.find(nums[i]) != dict.end())
            dict[nums[i]] += 1;
        else dict[nums[i]] = 1;
    }
    dfs(res, dict, )

}