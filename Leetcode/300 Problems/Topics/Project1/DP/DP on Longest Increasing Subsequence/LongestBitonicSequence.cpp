// https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
int longestBitonicSubsequence(vector<int> &arr, int n)
{
  vector<int> dp1(n, 1);
  vector<int> dp2(n, 1);
  int maxiValue = 1;

  // to construct longest incresing subsequence from index 0 to n - 1
  for (int idx = 1; idx < n; ++idx)
  {
    for (int prev_idx = 0; prev_idx < idx; ++prev_idx)
    {
      if (arr[prev_idx] < arr[idx] &&
          dp1[idx] < dp1[prev_idx] + 1)
      {
        dp1[idx] = dp1[prev_idx] + 1;
      }
    }
  }

  // to construct longest decreasing subsequence from index n - 1 to 0
  for (int idx = n - 2; idx >= 0; --idx)
  {
    for (int prev_idx = n - 1; prev_idx >= idx; --prev_idx)
    {
      if (arr[prev_idx] < arr[idx] &&
          dp2[idx] < dp2[prev_idx] + 1)
      {
        dp2[idx] = dp2[prev_idx] + 1;
      }
    }
  }

  // find maxValue
  for (int i = 0; i < n; ++i)
    maxiValue = max(maxiValue, dp1[i] + dp2[i] - 1);

  return maxiValue;
}
