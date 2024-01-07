// https://www.codingninjas.com/studio/problems/longest-string-chain_3752111?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h>
bool compareTo(string s1, string s2)
{
  int i = 0;
  int j = 0;
  int length_1 = s1.length();
  int length_2 = s2.length();

  if (length_1 + 1 != length_2)
    return false;

  while (j < length_2)
  {
    if (s1[i] == s2[j])
    {
      ++i;
      ++j;
    }
    else
      ++j;
  }

  return i == length_1 && j == length_2;
}

bool comp(string s1, string s2)
{
  return s1.size() < s2.size();
}
int longestStrChain(vector<string> &arr)
{
  int n = arr.size();

  // sắp xếp độ dài của từng chuỗi
  sort(arr.begin(), arr.end(), comp);

  vector<int> dp(n, 1);
  int maxiValue = 1;
  for (int idx = 1; idx < n; ++idx)
  {
    for (int prev_idx = 0; prev_idx < idx; ++prev_idx)
    {
      if (compareTo(arr[prev_idx], arr[idx]) && dp[idx] < dp[prev_idx] + 1)
        dp[idx] = dp[prev_idx] + 1;
    }
    maxiValue = max(maxiValue, dp[idx]);
  }
  return maxiValue;
}