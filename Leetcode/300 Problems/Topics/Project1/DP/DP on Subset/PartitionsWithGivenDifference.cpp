// https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

int module = (int)(1e9 + 7);
int findWays(int index, int n, int k,
             vector<vector<int>> &dp,
             vector<int> &arr)
{

  // working at index 0
  if (index == 0)
  {
    if (k == 0 && arr[0] == 0)
      return 2;
    if (k == 0 || k == arr[0])
      return 1;
    return 0;
  }

  if (dp[index][k] != -1)
    return dp[index][k];

  // Exclude the current element
  int notPick = findWays(index - 1, n, k, dp, arr);

  // Include the current element
  int pick = 0;
  if (arr[index] <= k)
    pick = findWays(index - 1, n, k - arr[index], dp, arr);

  // Update the dp table
  dp[index][k] = (pick + notPick) % module;

  return dp[index][k];
}

int countPartitions(int n, int d, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(totalSum + 1, -1));

  if (totalSum - d < 0 || (totalSum - d) % 2)
    return 0;

  return findWays(n - 1, n, (totalSum - d) / 2, dp, arr);
}

// Space optimization
int countPartitions(int n, int d, vector<int> &arr)
{

  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  vector<int> prev(totalSum + 1, 0), cur(totalSum + 1, 0);

  if (arr[0] == 0)
    prev[0] = 2;
  else
    prev[0] = 1;

  if (arr[0] <= totalSum && arr[0] != 0)
  {
    prev[arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i)
  {
    for (int target = 0; target <= totalSum; ++target)
    {
      int notPick = prev[target];

      // Include the current element
      int pick = 0;
      if (arr[i] <= target)
        pick = prev[target - arr[i]];

      cur[target] = (pick + notPick) % module;
    }

    prev = cur;
  }

  if (totalSum - d < 0 || (totalSum - d) % 2)
    return 0;

  return prev[(totalSum - d) / 2];
}