// random_shuffle example
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
using namespace std;

void swap(vector<int>& nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}

int partition(vector<int>& nums, int low, int high)
{
    int pivotValue = nums[low];
    int pivotInd = low++;
    while(low <= high)
    {
        if(nums[low] < pivotValue)
            low++;
        else if(nums[high] >= pivotValue)
            high--;
        else swap(nums, low, high);
    }
    swap(nums, pivotInd, high);
    return high;
}

int findKthLargest(vector<int>& nums, int k) 
{
    random_shuffle(nums.begin(), nums.end());
    int low = 0, high = nums.size() - 1, targetIndex = nums.size() - k, partitionIndex;
    while(true)
    {
        partitionIndex = partition(nums, low, high);
        if(targetIndex < partitionIndex)
            high = partitionIndex - 1;
        else if(targetIndex > partitionIndex)
            low = partitionIndex + 1;
        else break;
    }
    return nums[targetIndex];
}
int main () {

  return 0;
}