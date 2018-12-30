#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int smallestRangeII(vector<int>& A, int K) {
    int arv = 0, _max = INT32_MIN, _min = INT32_MAX;
    for(auto it : A) arv += it;
    arv /= A.size();
    cout << "arv = " << arv << endl;
    cout << "B = ";
    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > arv)
            A[i] -= K;
        else A[i] += K;
        _max = (A[i] > _max)? A[i] : _max;
        _min = (A[i] < _min)? A[i] : _min;
        cout << A[i] << ' '; 
    }
    cout << endl;
    return _max - _min;
}

int main(int argc, char const *argv[])
{
    int a[] = {0,10}, K =2;
    vector<int> A(a, a + 2);
    cout << smallestRangeII(A, K) << endl;

    return 0;
}
