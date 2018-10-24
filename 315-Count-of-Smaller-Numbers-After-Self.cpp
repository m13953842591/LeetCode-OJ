#include <iostream>
#include <vector>
#include <pair>
using namespace std;

typedef vector<pair<int, int>> Pii;
typedef Pii::iterator Pit;

void merge(Pit begin, Pit end, vector<int>& res)
{
    if(end - beign <= 1) return;
    auto mid = begin + (end - begin) / 2;
    merge(first, mid, res);
    merge(mid, end, res);// merge and inplace_merge is [)
    for(Pit i = begin, j = mid; i != mid; i++)
    {
        while(j != end && j->first < i->first)//ascending order
            j++;
        res[i->second] += j - mid;
    }
    inplace_merge(begin, mid, end);
}
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n,0);
    Pii nums_(n);
    for(int i = 0; i < n; i++)
        nums_[i] = {nums[i], i};
    merge(nums_.begin(), nums_.end(), res);
    return res;
}