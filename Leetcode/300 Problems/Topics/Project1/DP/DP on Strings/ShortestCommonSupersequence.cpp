// https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
string shortestSupersequence(string s, string t)
{

  // Construct dp table
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

  // Print shorstest common supersequence
  int length = length_1 + length_2 - dp[length_1][length_2];
  string ans(length, '-');
  int idx = length - 1;

  int i = length_1; // dòng
  int j = length_2; // cột

  while (i > 0 && j > 0)
  {
    if (s[i - 1] == t[j - 1])
    {
      ans[idx--] = s[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      ans[idx--] = s[i - 1];
      i--;
    }
    else
    {
      ans[idx--] = t[j - 1];
      j--;
    }
  }

  while (i > 0)
  {
    ans[idx--] = s[i - 1];
    i--;
  }

  while (j > 0)
  {
    ans[idx--] = t[j - 1];
    j--;
  }
  return ans;
}