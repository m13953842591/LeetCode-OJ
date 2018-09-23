#include <iostream>
#include <vector>
using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    vector<int> D(A.size(),0);//D[i] difference of A[i] and A[i - 1]
    vector<int> N(A.size(),0); 
    int ans = 0;
    if(A.size() < 3) return 0;
    for(int i = 1; i < A.size(); i++)
    {
        D[i] = A[i] - A[i - 1];
        if(i > 1)
        {
            if(D[i] == D[i - 1])
                N[i] = N[i - 1] * 2 - N[i - 2] + 1;
            else {
                N[i] = 0;
                ans += N[i - 1];
            }
        }
    }
    ans += N[A.size() - 1];
    cout << endl << "D: ";
    for(auto it : D)
        cout << it << ' ';
        cout << endl;
    cout << endl << "N: ";
    for(auto it : N)
        cout << it << ' ';
        cout << endl;
    return ans;
}


int main(int argc, char const *argv[])
{
    int x[] = {1,2,3,8,9,10};
    vector<int> test(x, x + sizeof(x)/ sizeof(int));
    cout << numberOfArithmeticSlices(test);
    return 0;
}
