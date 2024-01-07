// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int maximumNonAdjacentSumHelper(int index, vector<int> &nums, vector<int> &dp)
{
  if (index < 0)
    return 0;

  if (index == 0)
    return nums[index];

  if (dp[index] != -1)
    return dp[index];

  int pick = nums[index] + maximumNonAdjacentSumHelper(index - 2, nums, dp);
  int not_pick = 0 + maximumNonAdjacentSumHelper(index - 1, nums, dp);

  dp[index] = max(pick, not_pick);

  return dp[index];
}
int maximumNonAdjacentSum(vector<int> &nums)
{
  int index = nums.size();
  vector<int> dp(index + 1, -1);
  return maximumNonAdjacentSumHelper(index - 1, nums, dp);
}

// Tabulation
int maximumNonAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n + 1);
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; ++i)
  {
    int pick = nums[i] + dp[i - 2];
    int not_pick = 0 + dp[i - 1];
    dp[i] = max(pick, not_pick);
  }

  return dp[n - 1];
}

// Space optimization
int maximumNonAdjacentSum(vector<int> &nums)
{
  int n = nums.size();
  int prev2 = nums[0];
  int prev = max(nums[0], nums[1]);
  for (int i = 2; i < n; ++i)
  {
    int pick = nums[i] + prev2;
    int not_pick = 0 + prev;
    int cur = max(pick, not_pick);

    prev2 = prev;
    prev = cur;
  }

  return prev;
}