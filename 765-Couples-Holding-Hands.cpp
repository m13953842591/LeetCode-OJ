#include <vector>
#include <iostream>
using namespace std;


int couple(int x){
    return (4 * (x / 2) + 1 - x);
}
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int minSwap, i;
        bool flag = true;
        vector<int> whereIs(row.size());
        for(int i = 0; i < row.size(); i++)
                whereIs[row[i]] = i;
        while(flag)
        {
            flag = false;

        }
    }
};