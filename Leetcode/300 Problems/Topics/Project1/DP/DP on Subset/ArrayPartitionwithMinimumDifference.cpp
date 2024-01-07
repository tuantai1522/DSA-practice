// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization
bool subsetSumToKHelper(int index, vector<int> &arr,
                        int n, int k, vector<vector<int>> &dp)
{
  if (k == 0)
    return true;

  if (index < 0)
    return false;

  if (dp[index][k] != -1)
    return dp[index][k];

  // Exclude the current element
  bool notPick = subsetSumToKHelper(index - 1, arr, n, k, dp);

  // Include the current element
  bool pick = false;
  if (arr[index] <= k)
    pick = subsetSumToKHelper(index - 1, arr, n, k - arr[index], dp);

  // Update the dp table
  dp[index][k] = pick || notPick;

  return dp[index][k];
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
  int total = 0;
  for (int i = 0; i < n; ++i)
  {
    total += arr[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(total + 1, -1));

  int ans = INT_MAX;
  for (int i = 0; i <= total / 2; ++i)
  {
    if (subsetSumToKHelper(n - 1, arr, n, i, dp))
    {
      int sumS1 = i;
      int sumS2 = total - i;
      ans = min(ans, abs(sumS1 - sumS2));
    }
  }
  return ans;
}

// Space optimization
int minSubsetSumDifference(vector<int> &arr, int n)
{
  int total = 0;
  for (int i = 0; i < n; ++i)
  {
    total += arr[i];
  }
  int target = total / 2;

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

  int ans = INT_MAX;
  for (int i = 0; i <= total / 2; ++i)
  {
    if (prev[i])
    {
      int sumS1 = i;
      int sumS2 = total - i;
      ans = min(ans, abs(sumS1 - sumS2));
    }
  }
  return ans;
}
