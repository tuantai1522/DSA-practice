// https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Tabulation
int lcs(string s, string t)
{
  int length_1 = s.length();
  int length_2 = t.length();
  vector<vector<int>> dp(length_1 + 1, vector<int>(length_2 + 1, 0));
  int ans = 0;
  // Base case: all value at row 0 is 0 and all value at column 0 is 0
  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (s[idx1 - 1] != t[idx2 - 1])
        dp[idx1][idx2] = 0;
      else
      {
        dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
        ans = max(ans, dp[idx1][idx2]);
      }
    }
  }
  return ans;
}

// Space optimization
// Shifting index: index at -1 is index at 0
int lcs(string s, string t)
{
  int length_1 = s.length();
  int length_2 = t.length();
  vector<int> prev(length_2 + 1, 0);
  int ans = 0;

  // Base case: all value at row 0 is 0 and all value at column 0 is 0

  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    vector<int> cur(length_2 + 1, 0);
    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (s[idx1 - 1] != t[idx2 - 1])
        cur[idx2] = 0;
      else
      {
        cur[idx2] = 1 + prev[idx2 - 1];
        ans = max(ans, cur[idx2]);
      }
    }
    prev = cur;
  }
  return ans;
}