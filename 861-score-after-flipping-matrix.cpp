#include <iostream>
#include <vector>
using namespace std;

int shouldFlipRow(vector<int> & Ar){
    int a = 0, b = 0;
    for(auto it : Ar){
        a = a * 2 + it;
        b = b * 2 + 1 - it;
    }
    return b > a;
}

int shouldFlipColumn(vector<vector<int>>& A, int c){
    int ans = 0;
    for(int i = 0; i < A.size(); i++){
        ans += A[i][c];
    }
    return ans < (A.size() + 1) / 2;
}

int matrixScore(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size(), ans = 0, tmp;
    bool flag = true;
    
    while(flag)
    {
        flag = false;
        for(int i = 0; i < m; i++)
        {
            if(shouldFlipRow(A[i]))
            {
                for(auto& it : A[i])
                    it = 1 - it;  
                flag = true;
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(shouldFlipColumn(A, j))
            {
                for(int i = 0; i < m; i++)
                    A[i][j] = 1 - A[i][j];
            }
        }
    }
    
    
    for(auto v : A)
    {
        tmp = 0;
        for(auto it : v)
            tmp = tmp *2 + it;
        ans += tmp;
    }
    return ans;
}



int main(int argc, char const *argv[])
{
    int x1[] = {0, 0, 1, 1};
    int x2[] = {1, 0, 1, 0};
    int x3[] = {1, 1, 0, 0};
    vector<int> v1(x1, x1 + sizeof(x1)/sizeof(int));
    vector<int> v2(x2, x2 + sizeof(x2)/sizeof(int));
    vector<int> v3(x3, x3 + sizeof(x3)/sizeof(int));
    vector<vector<int>> test;
    test.push_back(v1); test.push_back(v2); test.push_back(v3);
    cout << matrixScore(test);
    return 0;
}
    
