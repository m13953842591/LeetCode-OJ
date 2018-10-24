#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> & first, int low, int high)
{
    //merge first[low : high]
    if(high <= low) return;
    int mid = (low + high) / 2;
    vector<int> tmp(first.size(), 0);
    int i = low, j = mid + 1, k = low;
    while(k <= high)
    {
        if(i <= mid && j <= high)
        {
            if(first[i] < first[j]) 
                tmp[k++] = first[i++];
            else
                tmp[k++] = first[j++];
        }
        else if(i <= mid)
            tmp[k++] = first[i++];
        else 
            tmp[k++] = first[j++];
    }
    for(int s = low; s <= high; s++)
    {
        first[s] = tmp[s];
    }
}
int sort(vector<int>& first, int low, int high, int lower, int upper)
{
    int mid = (low + high) / 2;
    if(mid == low)
    {
        if(first[low] > first[high])
        {
            int tmp = first[low]; first[low] = first[high]; first[high] = tmp;
        }
        return 0;
    } 
    int count = sort(first, low, mid, lower, upper) + sort(first, mid, high, lower, upper);
    int i = mid, j = mid;
    for(int left = low; left <= mid; left++)
    {
        while(i < high && first[i] - first[left] < lower) i += 1;
        while(j < high && first[j] - first[left] <= lower) j += 1;
        count += j - i;
    }
    merge(first, low, high);
    return count;
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<int> first(nums.size(), 0);
    //first[0] is the sum of the first m numbers
    for(int i = 1; i < nums.size(); i++)
        first[i] = first[i - 1] + nums[i - 1];
    return sort(first, 0, first.size(), lower, upper);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
