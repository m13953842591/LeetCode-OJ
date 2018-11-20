#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int base = 0, steps, new_base, n = nums.size();
        while(base < n - 1)
        {
            steps = nums[base];
            new_base = base;
            for(; new_base < n - 1 && new_base <= base + steps; new_base++)
            {
                if(new_base + nums[new_base]> base + steps)
                    break;
            }
            cout << "base = " << base << " new_base = " << new_base << endl;
            if(new_base > base + steps) return false;
            base = new_base;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v({0});
    cout << s.canJump(v) << endl;
    return 0;
}
