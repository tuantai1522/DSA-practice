// https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
long countWaysToMakeChangeHelper(int index, int *num, int x,
                                 vector<vector<long>> &dp)
{
  if (index == 0)
  {
    if (x % num[0] == 0)
      return 1;

    return 0;
  }

  if (dp[index][x] != -1)
    return dp[index][x];

  long take = 0;
  if (num[index] <= x)
    take = countWaysToMakeChangeHelper(index, num, x - num[index], dp);

  long notTake = countWaysToMakeChangeHelper(index - 1, num, x, dp);

  dp[index][x] = take + notTake;
  return dp[index][x];
}
long countWaysToMakeChange(int *num, int n, int x)
{
  vector<vector<long>> dp(n + 1, vector<long>(x + 1, -1));

  return countWaysToMakeChangeHelper(n - 1, num, x, dp);
}

// Tabulation
long countWaysToMakeChange(int *num, int n, int x)
{
  vector<vector<long>> dp(n + 1, vector<long>(x + 1, 0));

  for (int i = 0; i <= x; ++i)
  {
    if (i % num[0] == 0)
      dp[0][i] = 1;
  }

  for (int index = 1; index < n; ++index)
  {
    for (int target = 0; target <= x; ++target)
    {
      long take = 0;
      if (num[index] <= target)
        take = dp[index][target - num[index]];

      long notTake = dp[index - 1][target];

      dp[index][target] = take + notTake; // Sửa đổi ở đây để tính tổng số cách
    }
  }
  return dp[n - 1][x];
}

// Space optimization
long countWaysToMakeChange(int *num, int n, int x)
{
  vector<long> prev(x + 1, 0);

  for (int i = 0; i <= x; ++i)
  {
    if (i % num[0] == 0)
      prev[i] = 1;
  }

  for (int index = 1; index < n; ++index)
  {
    vector<long> cur(x + 1, 0);
    for (int target = 0; target <= x; ++target)
    {
      long take = 0;
      if (num[index] <= target)
        take = cur[target - num[index]];

      long notTake = prev[target];

      cur[target] = take + notTake;
    }

    prev = cur;
  }

  return prev[x];
}