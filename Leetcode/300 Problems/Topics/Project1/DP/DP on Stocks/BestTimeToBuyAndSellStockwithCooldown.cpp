// https://www.codingninjas.com/studio/problems/highway-billboards_3125969?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
// Memorization
int f(int index, int buy, int n, vector<int> &prices,
      vector<vector<int>> &dp)
{
  if (index >= n)
    return 0;

  if (dp[index][buy] != -1)
    return dp[index][buy];

  int profit = 0;
  if (buy)
    profit = max(f(index + 1, 0, n, prices, dp) - prices[index],
                 f(index + 1, 1, n, prices, dp) - 0);
  else
    profit = max(f(index + 2, 1, n, prices, dp) + prices[index], // can not buy after sell
                 f(index + 1, 0, n, prices, dp) + 0);

  dp[index][buy] = profit;
  return dp[index][buy];
}
int stockProfit(vector<int> &prices)
{
  int n = prices.size();
  // buy: 1, sell: 0
  vector<vector<int>> dp(n + 1, vector<int>(2, -1));

  return f(0, 1, n, prices, dp);
}

// Tabulation
int stockProfit(vector<int> &prices)
{
  int n = prices.size();
  // buy: 1, sell: 0
  vector<vector<int>> dp(n + 2, vector<int>(2, 0));

  // Base case
  for (int buy = 0; buy < 2; ++buy)
  {
    dp[n][buy] = 0;
    dp[n + 1][buy] = 0;
  }

  for (int index = n - 1; index >= 0; --index)
  {
    for (int buy = 0; buy < 2; ++buy)
    {
      int profit = 0;
      if (buy)
        profit = max(dp[index + 1][0] - prices[index],
                     dp[index + 1][1] - 0);
      else
        profit = max(dp[index + 2][1] + prices[index], // can not buy after sell
                     dp[index + 1][0] + 0);

      dp[index][buy] = profit;
    }
  }

  return dp[0][1];
}
