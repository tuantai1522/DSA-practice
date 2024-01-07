// https://www.codingninjas.com/studio/problems/rahul-and-his-chocolates_3118974?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
int f(int index, int buy, int n, int fee, vector<int> &prices,
      vector<vector<int>> &dp)
{
  if (index == n)
    return 0;

  if (dp[index][buy] != -1)
    return dp[index][buy];

  int profit = 0;
  if (buy)
    profit = max(f(index + 1, 0, n, fee, prices, dp) - prices[index],
                 f(index + 1, 1, n, fee, prices, dp) - 0);
  else
    profit = max(f(index + 1, 1, n, fee, prices, dp) + prices[index] - fee,
                 f(index + 1, 0, n, fee, prices, dp) + 0);

  dp[index][buy] = profit;
  return dp[index][buy];
}
int maximumProfit(vector<int> &prices, int n, int fee)
{
  // buy: 1, sell: 0
  vector<vector<int>> dp(n + 1, vector<int>(2, -1));

  return f(0, 1, n, fee, prices, dp);
}

// Tabulation
int maximumProfit(vector<int> &prices, int n, int fee)
{
  // buy: 1, sell: 0
  vector<vector<int>> dp(n + 1, vector<int>(2, 0));

  // Base case
  for (int buy = 0; buy < 2; ++buy)
    dp[n][buy] = 0;

  for (int index = n - 1; index >= 0; --index)
  {
    for (int buy = 0; buy < 2; ++buy)
    {
      int profit = 0;
      if (buy)
        profit = max(dp[index + 1][0] - prices[index],
                     dp[index + 1][1] - 0);
      else
        profit = max(dp[index + 1][1] + prices[index] - fee,
                     dp[index + 1][0] + 0);

      dp[index][buy] = profit;
    }
  }

  return dp[0][1];
}

// Space optimization
int maximumProfit(vector<int> &prices, int n, int fee)
{
  // buy: 1, sell: 0
  vector<int> after(2, 0);

  // Base case
  for (int buy = 0; buy < 2; ++buy)
    after[buy] = 0;

  for (int index = n - 1; index >= 0; --index)
  {
    vector<int> cur(2, 0);
    for (int buy = 0; buy < 2; ++buy)
    {
      int profit = 0;
      if (buy)
        profit = max(after[0] - prices[index],
                     after[1] - 0);
      else
        profit = max(after[1] + prices[index] - fee,
                     after[0] + 0);

      cur[buy] = profit;
    }
    after = cur;
  }

  return after[1];
}