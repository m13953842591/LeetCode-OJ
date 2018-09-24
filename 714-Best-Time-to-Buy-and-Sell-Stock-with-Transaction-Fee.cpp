#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int cash = 0, hold = -prices[0];
    //cash: don't have stocks, hold: have stocks
    for(auto p : prices)
    {
        cash = max(cash, hold + p);
        hold = max(hold, cash - p);
    }
    return cash;
}

