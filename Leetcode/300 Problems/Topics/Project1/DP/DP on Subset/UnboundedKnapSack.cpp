// https://www.codingninjas.com/studio/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h>
// Memorization
int unboundedKnapsackHelper(int index, int W, vector<int> &profit,
                            vector<int> &weight, vector<vector<int>> &dp)
{
  if (index == 0)
    return profit[index] * (W / weight[index]);

  if (dp[index][W] != -1)
    return dp[index][W];

  int take = -1e8;
  if (weight[index] <= W)
  {
    take = profit[index] + unboundedKnapsackHelper(index, W - weight[index], profit, weight, dp);
  }

  int notTake = 0 + unboundedKnapsackHelper(index - 1, W, profit, weight, dp);

  dp[index][W] = max(take, notTake);

  return dp[index][W];
}

int unboundedKnapsack(int n, int W, vector<int> &profit, vector<int> &weight)
{
  vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));

  return unboundedKnapsackHelper(n - 1, W, profit, weight, dp);
}

// Tabulation
int unboundedKnapsack(int n, int target, vector<int> &profit, vector<int> &weight)
{
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));

  for (int W = 0; W <= target; ++W)
  {
    dp[0][W] = profit[0] * (W / weight[0]);
  }

  for (int index = 1; index < n; ++index)
  {
    for (int W = 0; W <= target; ++W)
    {
      int take = -1e8;
      if (weight[index] <= W)
      {
        take = profit[index] + dp[index][W - weight[index]];
      }

      int notTake = 0 + dp[index - 1][W];

      dp[index][W] = max(take, notTake);
    }
  }
  return dp[n - 1][target];
}

// Space optimization
int unboundedKnapsack(int n, int target, vector<int> &profit, vector<int> &weight)
{
  vector<int> prev(target + 1, 0);

  for (int W = 0; W <= target; ++W)
  {
    prev[W] = profit[0] * (W / weight[0]);
  }

  for (int index = 1; index < n; ++index)
  {
    vector<int> cur(target + 1, 0);
    for (int W = 0; W <= target; ++W)
    {
      int take = -1e8;
      if (weight[index] <= W)
      {
        take = profit[index] + cur[W - weight[index]];
      }

      int notTake = 0 + prev[W];

      cur[W] = max(take, notTake);
    }
    prev = cur;
  }
  return prev[target];
}