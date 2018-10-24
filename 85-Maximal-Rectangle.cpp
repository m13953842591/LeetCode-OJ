#include <vector>
#include <iostream>
using namespace std;



int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size(), cur_left = 0, cur_right = n;
    vector<int> height(n, 0), left(n, 0), right(n, n);
    int maxA = 0;
    for(int i = 0; i < m; i++)
    {
        cur_left = 0; cur_right = n;
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == '1') {
                height[j]++;
                left[j] = max(left[j], cur_left);
                }
            else {
                height[j] = 0;
                left[j] = 0;
                cur_left = j + 1;
                }
        }
        for(int j = n - 1; j >= 0; j--){
            if(matrix[i][j] == '1') right[j] = min(right[j], cur_right);
            else {right[j] = n; cur_right = j;}
        }
        for(int j = 0; j < n; j++)
            maxA = max( maxA, (right[j] - left[j]) * height[j] );
    }
    return maxA;
}