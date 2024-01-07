// https://www.codingninjas.com/studio/problems/best-time-to-buy-and-sell-stock_1080698?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos#include <bits/stdc++.h>

// Memorization
int f(int idx, int trans, vector<int> &prices, int n, int k,
      vector<vector<int>> &dp)
{
  if (idx == n || trans == 2 * k)
    return 0;

  if (dp[idx][trans] != -1)
    return dp[idx][trans];

  int profit = 0;
  // when we buy, we sell after that
  if (trans % 2 == 0)
    profit = max(f(idx + 1, trans + 1, prices, n, k, dp) - prices[idx],
                 f(idx + 1, trans, prices, n, k, dp) - 0);
  else
    profit = max(f(idx + 1, trans + 1, prices, n, k, dp) + prices[idx],
                 f(idx + 1, trans, prices, n, k, dp) + 0);

  dp[idx][trans] = profit;
  return dp[idx][trans];
}

int maximumProfit(vector<int> &prices, int n, int k)
{
  vector<vector<int>> dp(n + 1, vector<int>(k * 2, -1));

  return f(0, 0, prices, n, k, dp);
}

// Tabulation
int maximumProfit(vector<int> &prices, int n, int k)
{
  vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1, 0));

  // Base case
  for (int idx = 0; idx <= n; ++idx)
  {
    dp[idx][0] = 0;
  }

  for (int trans = (k * 2) - 1; trans >= 0; --trans)
  {
    dp[n][trans] = 0;
  }

  for (int idx = n - 1; idx >= 0; --idx)
  {
    for (int trans = (k * 2) - 1; trans >= 0; --trans)
    {
      int profit = 0;
      // when we buy, we sell after that
      if (trans % 2 == 0)
        profit = max(dp[idx + 1][trans + 1] - prices[idx],
                     dp[idx + 1][trans] - 0);
      else
        profit = max(dp[idx + 1][trans + 1] + prices[idx],
                     dp[idx + 1][trans] + 0);

      dp[idx][trans] = profit;
    }
  }
  return dp[0][0];
}

// Space optimization
int maximumProfit(vector<int> &prices, int n, int k)
{
  vector<vector<int>> dp(n + 1, vector<int>(k * 2 + 1, 0));
  vector<int> after(k * 2 + 1, 0);

  // Base case
  after[0] = 0;

  for (int trans = (k * 2) - 1; trans >= 0; --trans)
  {
    after[trans] = 0;
  }

  for (int idx = n - 1; idx >= 0; --idx)
  {
    vector<int> cur(k * 2 + 1, 0);

    for (int trans = (k * 2) - 1; trans >= 0; --trans)
    {
      int profit = 0;
      // when we buy, we sell after that
      if (trans % 2 == 0)
        profit = max(after[trans + 1] - prices[idx],
                     after[trans] - 0);
      else
        profit = max(after[trans + 1] + prices[idx],
                     after[trans] + 0);

      cur[trans] = profit;
    }
    after = cur;
  }
  return after[0];
}