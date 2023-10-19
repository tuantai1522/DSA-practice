//https://leetcode.com/problems/coin-change/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    int size = coins.size();



    //every element of this vector is the minimum to achieve that amount
    //[1, 5, 6, 9], 11
    //0 1 2 3 4 5 6 7 8 9 10 11
    //0 1 2 3 4 1 1 2 3 1  2  2
    vector<int> minimumCoin(amount + 1);

    for (int curAmount = 1; curAmount <= amount; ++curAmount) {
        int Min = 2e5;
        for (auto coin : coins) {
            if (coin <= curAmount) {
                //+ 1 becaue it will include CURRENT coin
                Min = min(Min, minimumCoin[curAmount - coin] + 1);
            }
        }

        minimumCoin[curAmount] = Min;
    }

    return minimumCoin[amount] == 2e5 ? -1 : minimumCoin[amount];
}