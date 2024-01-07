// https://www.codingninjas.com/studio/problems/divisible-set_3754960?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

vector<int> divisibleSet(vector<int> &arr)
{
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<int> dp(n, 1);
  vector<int> hash(n, 0);

  int maxiValue = 0;
  int maxiIdx = 0;
  for (int idx = 1; idx < n; ++idx)
  {
    hash[idx] = idx;
    for (int prev_idx = 0; prev_idx < idx; ++prev_idx)
    {
      if (arr[idx] % arr[prev_idx] == 0 && dp[idx] < dp[prev_idx] + 1)
      {
        dp[idx] = dp[prev_idx] + 1;
        hash[idx] = prev_idx;
      }
    }
    if (maxiValue < dp[idx])
    {
      maxiValue = dp[idx];
      maxiIdx = idx;
    }
  }
  vector<int> ans;

  int start = maxiIdx;

  ans.push_back(arr[start]);
  while (hash[start] != start)
  {
    start = hash[start];

    ans.push_back(arr[start]);
  }

  reverse(ans.begin(), ans.end());
  return ans;
}