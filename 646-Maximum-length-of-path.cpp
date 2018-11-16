#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

bool comp(vector<int>& a, vector<int> &b){return a[0] < b[0];}
    
class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), comp);
        
        vector<int> num(pairs.size(), 1);
        int maxN = 1, temp;
        bool flag;
        for(int i = pairs.size() - 1; i >= 0; i--)
        {
            if(i == pairs.size() - 1) continue;
            temp = 1;
            flag = false;
            for(int j = pairs.size() - 1; j > i; j--)
            {
                if(pairs[i][1] < pairs[j][0])
                {
                    temp = (temp < num[j])? num[j] : temp;
                    flag = true;
                }
                    
                else break;
            }
            if(flag)
            {
                num[i] = temp + 1;
            maxN = (maxN < num[i])? num[i] : maxN;
            }
            
        }
        for(int i = 0; i < pairs.size(); i++)
        {
            cout << pairs[i][0] <<" "<< pairs[i][1] << " " << num[i] << endl;
        }
        return maxN;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> pairs;
    ifstream in("in.txt");
    int first, second;
    while(in >> first >> second)
    {
        vector<int> tmp(2, 1);
        tmp[0] = first; tmp[1] = second;
        pairs.push_back(tmp);
    }
    Solution sol;
    int num = sol.findLongestChain(pairs);
    return 0;
}
