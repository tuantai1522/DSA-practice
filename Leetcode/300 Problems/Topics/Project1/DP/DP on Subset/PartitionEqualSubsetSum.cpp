
// Memorization
bool canPartitionHelper(int idx, int n, int target,
                        vector<int> &arr,
                        vector<vector<int>> &dp)
{
  if (target == 0)
    return true;

  if (idx < 0)
    return false;

  if (dp[idx][target] != -1)
    return dp[idx][target];

  bool pick = false;
  if (arr[idx] <= target)
    pick = canPartitionHelper(idx - 1, n, target - arr[idx], arr, dp);

  bool notPick = canPartitionHelper(idx - 1, n, target, arr, dp);

  dp[idx][target] = pick || notPick;
  return dp[idx][target];
}
bool canPartition(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  if (totalSum % 2 != 0)
    return false;

  int target = totalSum / 2;
  vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));

  return canPartitionHelper(n - 1, n, target, arr, dp);
}

// Tabulation
bool canPartition(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  if (totalSum % 2 != 0)
    return false;

  int target = totalSum / 2;
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
bool canPartition(vector<int> &arr, int n)
{
  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  if (totalSum % 2 != 0)
    return false;

  int target = totalSum / 2;

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
        if (arr[idx] <= target)
          pick = prev[k - arr[idx]];

        bool notPick = prev[k];

        cur[k] = pick | notPick;
      }
    }
    prev = cur;
  }
  return prev[target];
}