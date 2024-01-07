// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>

// Memorization
int knapsackHelper(int index, vector<int> weight,
                   vector<int> value, int n, int maxWeight,
                   vector<vector<int>> &dp)
{
  if (index == 0)
  {
    if (weight[index] <= maxWeight)
      return value[0];

    return 0;
  }

  if (dp[index][maxWeight] != -1)
    return dp[index][maxWeight];

  int take = -1e7;
  if (weight[index] <= maxWeight)
  {
    take = value[index] + knapsackHelper(index - 1, weight, value, n,
                                         maxWeight - weight[index], dp);
  }
  int notTake = 0 + knapsackHelper(index - 1, weight, value, n,
                                   maxWeight, dp);

  dp[index][maxWeight] = max(take, notTake);
  return dp[index][maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
  vector<vector<int>> dp(n + 1, vector<int>(maxWeight + 1, 0));

  for (int i = weight[0]; i <= maxWeight; ++i)
  {
    dp[0][i] = value[0];
  }

  for (int index = 1; index < n; ++index)
  {
    for (int W = 0; W <= maxWeight; ++W)
    {
      int take = -1e7;
      if (weight[index] <= W)
      {
        take = value[index] + dp[index - 1][W - weight[index]];
      }
      int notTake = 0 + dp[index - 1][W];

      dp[index][W] = max(take, notTake);
    }
  }
  return dp[n - 1][maxWeight];
}