// https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization

#include <bits/stdc++.h>
int f(int idx, int prev_idx, int arr[], int n,
      vector<vector<int>> &dp)
{
  if (idx == n)
    return 0;

  if (dp[idx][prev_idx + 1] != -1)
    return dp[idx][prev_idx + 1];

  int notTake = 0 + f(idx + 1, prev_idx, arr, n, dp);

  int take = 0;
  if (prev_idx == -1 || (arr[idx] > arr[prev_idx]))
    take = 1 + f(idx + 1, idx, arr, n, dp);

  dp[idx][prev_idx + 1] = max(take, notTake);
  return dp[idx][prev_idx + 1];
}

int longestIncreasingSubsequence(int arr[], int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

  return f(0, -1, arr, n, dp);
}

// Tabulation
int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> dp(n, 1);
  int ans = 1;
  for (int idx = 1; idx < n; ++idx)
  {
    for (int prev_idx = 0; prev_idx < idx; ++prev_idx)
    {
      if (arr[prev_idx] < arr[idx])
      {
        dp[idx] = max(dp[idx], dp[prev_idx] + 1);
      }
    }
    ans = max(ans, dp[idx]);
  }

  return ans;
}

// Binary search

// Trong dòng binarySearch[*it] = arr[idx];
// , bạn đang cố gắng gán giá trị arr[idx] cho phần tử trong
// vector binarySearch tại vị trí *it.
// Tuy nhiên, *it là giá trị của phần tử, không phải là chỉ số.
// Để lấy chỉ số, bạn cần sử dụng:
// it - binarySearch.begin().
int longestIncreasingSubsequence(int arr[], int n)
{
  vector<int> binarySearch;
  binarySearch.push_back(arr[0]);
  int ans = 1;

  for (int idx = 1; idx < n; ++idx)
  {
    auto it =
        lower_bound(binarySearch.begin(), binarySearch.end(), arr[idx]);
    if (it != binarySearch.end())
      binarySearch[it - binarySearch.begin()] = arr[idx];
    else
    {
      binarySearch.push_back(arr[idx]);
      ++ans;
    }
  }
  return ans;
}