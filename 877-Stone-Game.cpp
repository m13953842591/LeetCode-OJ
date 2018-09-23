#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool stoneGame(vector<int>& piles) {
    int Alex = 0, Lee = 0;
    int left = 0, right = piles.size() - 1;
    int turn = 1; // 1 means Alex, 0 means Lee;
    while(left <= right)
    {
        if(turn)
        {
            if(piles[left] > piles[right])
            {
                Alex += piles[left];
                left++;
            }
            else
            {
                Alex += piles[right];
                right--;
            }
        }
        else
        {
            if(piles[left] > piles[right])
            {
                Lee += piles[left];
                left++;
            }
            else
            {
                Lee += piles[right];
                right--;
            }
        }
        turn = 1 - turn;
    }
    return Alex > Lee;
}

int main(int argc, char const *argv[])
{
    int x[4] = {5,3,4,5};
    vector<int> piles(x, x + sizeof(x) / sizeof(int));
    cout << stoneGame(piles);
    return 0;
}
