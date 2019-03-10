#include <iostream>
#include <vector>
using namespace std;

int operator*(const vector<int>& a, const vector<int>& b)
{
    int res = 0;
    for(int i = 0; i < a.size(); i++)
        res += a[i] * b[i];
    return res; 
}
bool operator>=(const vector<int>& a, const vector<int>& b)
{
    for(int i = 0; i < a.size(); i++)
        if(a[i] < b[i]) return false;
    return true; 
}
void operator+=(vector<int> &a, const vector<int>&b)
{
    for(int i = 0; i < a.size(); i++)
        a[i] += b[i];
}
void operator-=(vector<int> &a, const vector<int>&b)
{
    for(int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}
int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int cost = price * needs;
    for(auto & spe : special)
    {
        if(spe.back() > cost) continue;
        if(needs >= spe)
        {
            needs -= spe;
            cost = min(cost, spe.back() + shoppingOffers(price, special, needs));
            needs += spe;
        }
    }
    return cost;
}