// https://www.codingninjas.com/studio/problems/selling-stock_630282?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
// Memorizaion
#include <bits/stdc++.h>
long f(int idx, int buy, long *prices, int n,
       vector<vector<long>> &dp)
{
  if (idx == n)
    return 0;
  if (dp[idx][buy] != -1)
    return dp[idx][buy];

  long profit = 0;
  if (buy)
    profit = max(f(idx + 1, 1, prices, n, dp) - 0,
                 f(idx + 1, 0, prices, n, dp) - prices[idx]);
  else
    profit = max(f(idx + 1, 0, prices, n, dp) + 0,
                 f(idx + 1, 1, prices, n, dp) + prices[idx]);

  dp[idx][buy] = profit;

  return dp[idx][buy];
}
long getMaximumProfit(long *prices, int n)
{
  vector<vector<long>> dp(n, vector<long>(2, -1));
  return f(0, 1, prices, n, dp);
}

// Tabulation
long getMaximumProfit(long *prices, int n)
{
  vector<vector<long>> dp(n + 1, vector<long>(2, 0));

  // Base case
  for (int i = 0; i < 2; ++i)
  {
    dp[n][i] = 0;
  }

  for (int idx = n - 1; idx >= 0; --idx)
  {
    for (int buy = 0; buy < 2; ++buy)
    {
      long profit = 0;

      if (buy)
        profit = max(dp[idx + 1][1] + 0, dp[idx + 1][0] - prices[idx]);
      else
        profit = max(dp[idx + 1][0] + 0, dp[idx + 1][1] + prices[idx]);
      dp[idx][buy] = profit;
    }
  }

  return dp[0][1];
}

long getMaximumProfit(long *prices, int n)
{
  vector<long> next(2, 0);
  // Base case
  for (int i = 0; i < 2; ++i)
  {
    next[i] = 0;
  }

  for (int idx = n - 1; idx >= 0; --idx)
  {
    vector<long> cur(2, 0);

    for (int buy = 0; buy < 2; ++buy)
    {
      long profit = 0;

      if (buy)
        profit = max(next[1] + 0, next[0] - prices[idx]);
      else
        profit = max(next[0] + 0, next[1] + prices[idx]);
      cur[buy] = profit;
    }
    next = cur;
  }

  return next[1];
}