#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}
int findMinArrowShots(vector<pair<int, int>>& points) {
    sort(points.begin(), points.end(), comp);
    int cnt = 1, end = points[0].second;
    for(int i = 0; i < points.size(); i++)
    {
        if(points[i].first <= end) continue;
        else{
            end = points[i].second;
            cnt++;
        }
    }
    return cnt;
}