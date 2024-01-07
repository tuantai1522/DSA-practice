// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;

// Memorization
bool subsetSumToKHelper(int index, int n, int k,
                        vector<vector<int>> &dp,
                        vector<int> &arr)
{
  if (k == 0)
    return true;

  if (index < 0)
    return false;

  if (dp[index][k] != -1)
    return dp[index][k];

  // Exclude the current element
  bool notPick = subsetSumToKHelper(index - 1, n, k, dp, arr);

  // Include the current element
  bool pick = false;
  if (arr[index] <= k)
    pick = subsetSumToKHelper(index - 1, n, k - arr[index], dp, arr);

  // Update the dp table
  dp[index][k] = pick || notPick;

  return dp[index][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

  return subsetSumToKHelper(n - 1, n, k, dp, arr);
}

// Tabulation
bool subsetSumToK(int n, int target, vector<int> &arr)
{
  vector<vector<int>> dp(n, vector<int>(target + 1, 0));

  for (int i = 0; i < n; ++i)
    dp[i][0] = 1;

  if (arr[0] <= target)
    dp[0][arr[0]] = 1;

  for (int idx = 1; idx < n; ++idx)
  {
    for (int k = 1; k <= target; ++k)
    {
      bool pick = false;
      if (arr[idx] <= k)
        pick = dp[idx - 1][k - arr[idx]];

      bool notPick = dp[idx - 1][k];

      dp[idx][k] = pick || notPick;
    }
  }

  return dp[n - 1][target];
}

// Space optimization
bool subsetSumToK(int n, int target, vector<int> &arr)
{
  vector<int> prev(target + 1, 0);

  prev[0] = 1;

  if (arr[0] <= target)
    prev[arr[0]] = 1;

  for (int idx = 1; idx < n; ++idx)
  {
    vector<int> cur(target + 1, 0);
    for (int k = 0; k <= target; ++k)
    {
      if (k == 0)
      {
        cur[k] = 1;
      }
      else
      {
        bool pick = false;
        if (arr[idx] <= k)
          pick = prev[k - arr[idx]];

        bool notPick = prev[k];

        cur[k] = pick | notPick;
      }
    }
    prev = cur;
  }
  return prev[target];
}