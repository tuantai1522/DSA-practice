// https: // leetcode.com/problems/house-robber/description/?envType=study-plan-v2&envId=top-interview-150

// Recursion
// Go from n - 1 to 0
int robHelper(vector<int> &nums, int idx, int n)
{
  if (idx < 0)
    return 0;

  int take = nums[idx] + robHelper(nums, idx - 2, n);
  int not_take = 0 + robHelper(nums, idx - 1, n);

  return max(take, not_take);
}
int rob(vector<int> &nums)
{
  int n = nums.size();
  return robHelper(nums, n - 1, n);
}

// Tabulation
int robHelper(vector<int> &nums, int idx, int n, vector<int> &dp)
{
  if (idx < 0)
    return 0;

  if (dp[idx] != -1)
    return dp[idx];

  int take = nums[idx] + robHelper(nums, idx - 2, n, dp);
  int not_take = 0 + robHelper(nums, idx - 1, n, dp);

  dp[idx] = max(take, not_take);
  return dp[idx];
}
int rob(vector<int> &nums)
{
  int n = nums.size();
  vector<int> dp(n + 1, -1);

  return robHelper(nums, n - 1, n, dp);
}

// Memorization
int rob(vector<int> &nums)
{
  int n = nums.size();

  if (n == 1)
    return nums[0];

  if (n == 2)
    return max(nums[0], nums[1]);

  vector<int> dp(n, 0);

  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int idx = 2; idx < n; ++idx)
  {
    int take = nums[idx] + dp[idx - 2];
    int not_take = 0 + dp[idx - 1];

    dp[idx] = max(take, not_take);
  }

  return dp[n - 1];
}