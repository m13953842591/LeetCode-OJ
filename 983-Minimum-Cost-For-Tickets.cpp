#include<iostream>
#include<vector>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int opt[days.size() + 1] = {0};
    int i, k, days_7, days_30, end = days.size() - 1; 
   
    for(i = end; i >= 0; i--)
    {
        days_7 = days_30 = -1;
        for(k = end; k > i; k--)
        {
            if(days[k] - days[i] + 1 > 7)
                days_7 = k;
            else break;
            if(days[k] - days[i] + 1 > 30)
                days_30 = k;
        }
        opt[i] = opt[i + 1] + costs[0];
        
        if(days[end] - days[i] + 1 <= 30)
            opt[i] = min(opt[i], costs[2]);
        if(days[end] - days[i] + 1 <= 7)
            opt[i] = min(opt[i], costs[1]);
        if(days_7 > 0)
            opt[i] = min(opt[i], opt[days_7] + costs[1]);
        if(days_30 > 0)
            opt[i] = min(opt[i], opt[days_30] + costs[2]);
    }
    
    for (int i = 0; i <= days.size(); i++)
        cout << opt[i] << " ";

    return opt[0];
}


int main()
{
    int d[] = {1,2,3,4,5,6,7,8,9,10,30,31}, c[] = {2,7,15};
    vector<int> days(d, d + sizeof(d) / sizeof(int));
    vector<int> costs(c, c + sizeof(c) / sizeof(int));
    cout << "mincostTickets: " << mincostTickets(days, costs) << endl;
    return 0; 
}