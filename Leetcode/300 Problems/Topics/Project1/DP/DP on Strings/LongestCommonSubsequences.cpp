// https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
// Memorization
int lcsHelper(int idx1, int idx2, string s, string t,
              vector<vector<int>> &dp)
{
  if (idx1 < 0 || idx2 < 0)
    return 0;

  if (dp[idx1][idx2] != -1)
    return dp[idx1][idx2];

  if (s[idx1] != t[idx2])
    return dp[idx1][idx2] = max(lcsHelper(idx1 - 1, idx2, s, t, dp), lcsHelper(idx1, idx2 - 1, s, t, dp));

  return dp[idx1][idx2] = 1 + lcsHelper(idx1 - 1, idx2 - 1, s, t, dp);
}
int lcs(string s, string t)
{
  int length_1 = s.length();
  int length_2 = t.length();
  vector<vector<int>> dp(length_1, vector<int>(length_2 + 1, -1));

  return lcsHelper(length_1 - 1, length_2 - 1, s, t, dp);
}

// Tabulation
// Shifting index: index at -1 is index at 0
int lcs(string s, string t)
{
  int length_1 = s.length();
  int length_2 = t.length();
  vector<vector<int>> dp(length_1 + 1, vector<int>(length_2 + 1, 0));

  // Base case: all value at row 0 is 0 and all value at column 0 is 0
  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (s[idx1 - 1] != t[idx2 - 1])
        dp[idx1][idx2] = max(dp[idx1 - 1][idx2], dp[idx1][idx2 - 1]);
      else
        dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
    }
  }
  return dp[length_1][length_2];
}

// Space optimization
// Shifting index: index at -1 is index at 0
int lcs(string s, string t)
{
  int length_1 = s.length();
  int length_2 = t.length();
  vector<int> prev(length_2 + 1, 0);

  // Base case: all value at row 0 is 0 and all value at column 0 is 0

  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    vector<int> cur(length_2 + 1, 0);
    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (s[idx1 - 1] != t[idx2 - 1])
        cur[idx2] = max(prev[idx2], cur[idx2 - 1]);
      else
        cur[idx2] = 1 + prev[idx2 - 1];
    }
    prev = cur;
  }
  return prev[length_2];
}