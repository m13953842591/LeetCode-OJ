#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.empty()){return 0;}
        int n = A.size(), minfps, l, r;
        int minFPS[n][n];
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == n - 1)
                    minFPS[i][j] = A[i][j];
                else{
                    l = (j > 0)? j - 1 : j;
                    r = (j < n - 1)? j + 1 : j;
                    minfps = (minFPS[i+1][l] < minFPS[i+1][j])? minFPS[i+1][l] : minFPS[i+1][j];
                    minfps = (minFPS[i+1][r] < minfps)? minFPS[i+1][r] : minfps;
                    minFPS[i][j] = A[i][j] + minfps;
                }
            }
        }
        minfps = minFPS[0][0];
        for(int i = 0; i < n; i++)
        {
            minfps = (minfps < minFPS[0][i])? minfps : minFPS[0][i];
        }
        return minfps;
    }
};