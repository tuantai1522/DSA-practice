// https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// ------------------------------ 3D Vector
// Memorizaion
#include <bits/stdc++.h>
int f(int idx, int buy, int maxi, vector<int> &prices, int n,
      vector<vector<vector<int>>> &dp)
{
  if (maxi == 0)
    return 0;

  if (idx == n)
    return 0;

  if (dp[idx][buy][maxi] != -1)
    return dp[idx][buy][maxi];

  int profit = 0;
  if (buy)
    profit = max(f(idx + 1, 1, maxi, prices, n, dp) - 0,
                 f(idx + 1, 0, maxi, prices, n, dp) - prices[idx]);
  else
    profit = max(f(idx + 1, 0, maxi, prices, n, dp) + 0,
                 f(idx + 1, 1, maxi - 1, prices, n, dp) + prices[idx]); // done 1 transaction

  dp[idx][buy][maxi] = profit;

  return dp[idx][buy][maxi];
}
int maxProfit(vector<int> &prices)
{
  int n = prices.size();

  // [n][2][3]
  vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

  return f(0, 1, 2, prices, n, dp);
}

// Tabulation
int maxProfit(vector<int> &prices)
{
  int n = prices.size();

  // [n][2][3]
  vector<vector<vector<int>>> dp(n + 1,
                                 vector<vector<int>>(2,
                                                     vector<int>(3, 0)));

  // Base case

  // Maxi == 0
  for (int idx = 0; idx < n; ++idx)
  {
    for (int buy = 0; buy < 2; ++buy)
    {
      dp[idx][buy][0] = 0;
    }
  }

  // idx == n
  for (int buy = 0; buy < 2; ++buy)
  {
    for (int maxi = 0; maxi < 3; ++maxi)
    {
      dp[n][buy][maxi] = 0;
    }
  }

  for (int idx = n - 1; idx >= 0; --idx)
  {
    for (int buy = 0; buy < 2; ++buy)
    {
      for (int maxi = 0; maxi < 3; ++maxi)
      {

        int profit = 0;

        if (buy)
          profit =
              max(dp[idx + 1][1][maxi] - 0,
                  dp[idx + 1][0][maxi] - prices[idx]);
        else
          profit = max(dp[idx + 1][0][maxi] + 0,
                       dp[idx + 1][1][maxi - 1] + prices[idx]);

        dp[idx][buy][maxi] = profit;
      }
    }
  }

  return dp[0][1][2];
}

// ------------------------------ 2D Vector
int f(int idx, int trans, vector<int> &prices, int n,
      vector<vector<int>> &dp)
{
  if (trans == 4)
    return 0;

  if (idx == n)
    return 0;

  if (dp[idx][trans] != -1)
    return dp[idx][trans];

  int profit = 0;
  if (trans % 2 == 0) // buy
    profit = max(f(idx + 1, trans, prices, n, dp) - 0,
                 f(idx + 1, trans + 1, prices, n, dp) - prices[idx]);
  else
    profit = max(f(idx + 1, trans, prices, n, dp) + 0,
                 f(idx + 1, trans + 1, prices, n, dp) + prices[idx]);

  dp[idx][trans] = profit;

  return dp[idx][trans];
}
int maxProfit(vector<int> &prices)
{
  int n = prices.size();

  // [n][4]
  vector<vector<int>> dp(n + 1, vector<int>(4, -1));

  return f(0, 0, prices, n, dp);
}