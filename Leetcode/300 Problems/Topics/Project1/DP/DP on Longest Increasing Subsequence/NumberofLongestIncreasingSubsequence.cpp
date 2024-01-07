// https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
int findNumberOfLIS(vector<int> &arr)
{
  int n = arr.size();
  vector<int> dp(n, 1);
  vector<int> count(n, 1);

  int maxiValue = 1;

  for (int idx = 1; idx < n; ++idx)
  {
    for (int prev_idx = 0; prev_idx < idx; ++prev_idx)
    {
      if (arr[prev_idx] < arr[idx] && dp[prev_idx] + 1 > dp[idx])
      {
        dp[idx] = dp[prev_idx] + 1;
        count[idx] = count[prev_idx];
      }
      else if (arr[prev_idx] < arr[idx] && dp[prev_idx] + 1 == dp[idx])
        count[idx] += count[prev_idx];
    }
    maxiValue = max(maxiValue, dp[idx]);
  }

  int ans = 0;
  for (int idx = 0; idx < n; ++idx)
  {
    if (dp[idx] == maxiValue)
      ans += count[idx];
  }

  return ans;
}