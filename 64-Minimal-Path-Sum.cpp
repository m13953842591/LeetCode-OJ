#include <iostream>
#include <vector>
using namespace std;
#define inf INT32_MAX;
int minPathSum(vector<vector<int>>& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;

    vector<vector<int>> path(grid.begin(), grid.end());
    int m = path.size(), n = path[0].size();
    for(auto & it : path)
        for(auto & i : it) i = inf;

    int width = 1, start = m - 1;
    path[m - 1][n - 1] = grid[m - 1][n - 1];
    for(int j = m - 1; j > 0; j--)
    {   
        for(int incr = 0; incr < width; incr++){

            int up = (start + incr - 1 + m) % m, flat = (start + incr) % m, down = (start + incr + 1) % m;

            path[up][j - 1] = min(path[up][j - 1], grid[up][j - 1] + path[flat][j]);
            path[flat][j - 1] = min(path[flat][j - 1], grid[flat][j - 1] + path[flat][j]);
            path[down][j - 1] = min(path[down][j - 1], grid[down][j - 1] + path[flat][j]);
        }
        start = (start - 1 + m) % m;
        width = (width <= m - 2)? width + 2 : m;
    }
    
    return path[0][0]; 
}
int main(int argc, char const *argv[])
{
// [[1,3,1],[1,5,1],[4,2,1]]
    vector<vector<int>> vec;
    int a[] = {1,3,1}, b[] = {1,5,1}, c[] = {4,2,1};
    vector<int> aa(a, a + sizeof(a)/ sizeof(int));
    vector<int> bb(b, b + sizeof(b)/ sizeof(int));
    vector<int> cc(c, c + sizeof(c)/ sizeof(int));
    vec.push_back(aa);vec.push_back(bb);vec.push_back(cc);
    minPathSum(vec);
    return 0;
}
