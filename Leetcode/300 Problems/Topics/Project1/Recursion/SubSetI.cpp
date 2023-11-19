// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
bool canPartitionTab(vector<int> nums, int target)
{
  int n = nums.size();
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

  for (int i = 0; i < n; i++)
    dp[i][0] = 1;

  for (int index = n - 1; index >= 0; index--)
  {
    for (int t = 1; t <= target; t++)
    {
      int include = 0;
      if (t - nums[index] >= 0)
        include = dp[index + 1][t - nums[index]];
      int exclude = dp[index + 1][t];

      dp[index][t] = (include or exclude);
    }
  }
  return dp[0][target];
}
bool canPartition(vector<int> &nums)
{

  int total = 0;
  for (auto it : nums)
  {
    total += it;
  }
  if (total % 2 == 1)
    return false;
  int target = total / 2;

  return canPartitionTab(nums, target);
}