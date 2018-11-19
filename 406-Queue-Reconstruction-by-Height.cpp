#include <utility>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2)
                    { return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second); };
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> ans;
        for(auto& p : people)
        {
            ans.insert(people.begin() + p.second, p);
        }
        return ans;
    }
};