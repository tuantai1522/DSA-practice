// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

int module = (int)(1e9 + 7);
int subsetSumToK(int index, int n, int k,
                 vector<vector<int>> &dp,
                 vector<int> &arr)
{
  if (k == 0)
    return 1;

  if (index < 0)
    return 0;

  if (dp[index][k] != -1)
    return dp[index][k];

  // Exclude the current element
  int notPick = subsetSumToK(index - 1, n, k, dp, arr);

  // Include the current element
  int pick = 0;
  if (arr[index] <= k)
    pick = subsetSumToK(index - 1, n, k - arr[index], dp, arr);

  // Update the dp table
  dp[index][k] = (pick + notPick) % module;

  return dp[index][k];
}

int findWays(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
  vector<int> visited(n, 0);

  return subsetSumToK(n - 1, n, k, dp, arr) % module;
}

int findWays(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> prev(k + 1, 0), cur(k + 1, 0);

  prev[0] = cur[0] = 1;
  if (arr[0] <= k)
  {
    prev[arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i)
  {
    for (int target = 0; target <= k; ++target)
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

  return prev[k];
}

int findWays(vector<int> &arr, int k)
{
  int n = arr.size();
  vector<int> prev(k + 1, 0);

  prev[0] = 1;
  if (arr[0] <= k)
  {
    prev[arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i)
  {
    vector<int> cur(k + 1, 0);
    for (int target = 1; target <= k; ++target)
    {
      int notPick = prev[target];

      // Include the current element
      int pick = 0;
      if (arr[index] <= k)
        pick = prev[k - arr[index]];

      cur[target] = pick + notPick;
    }

    prev = cur;
  }

  return prev[k - 1];
}
