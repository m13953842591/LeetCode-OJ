#include <iostream>
#include <vector>
using namespace std;


int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    int opt = INT32_MAX;
    if(special.empty()) 
    {
        opt = 0;
        for(int i = 0; i < price.size(); i++)
            opt += needs[i] * price[i];
        return opt;
    }

    vector<int> cur_offer = special.back();

    special.pop_back();

    opt = shoppingOffers(price, special, needs);
    int cur_offer_num = 1, 
        cur_offer_price = cur_offer.back();

    while(true){

        for(int i = 0; i < needs.size(); i++)
            if(needs[i] < cur_offer[i]) break;
        for(int i = 0; i < needs.size(); i++)
            needs[i] -= cur_offer[i];
        opt = min(opt, shoppingOffers(price, special, needs) + cur_offer_num * cur_offer_price);
        cur_offer_num++;
    }

    special.push_back(cur_offer);
    return opt;
}