// https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization
int longestCommonSubsequences(int idx1, int idx2, string s, string t,
                              vector<vector<int>> &dp)
{
  if (idx1 < 0 || idx2 < 0)
    return 0;

  if (dp[idx1][idx2] != -1)
    return dp[idx1][idx2];

  if (s[idx1] != t[idx2])
    return dp[idx1][idx2] = max(longestCommonSubsequences(idx1 - 1, idx2, s, t, dp), longestCommonSubsequences(idx1, idx2 - 1, s, t, dp));

  return dp[idx1][idx2] = 1 + longestCommonSubsequences(idx1 - 1, idx2 - 1, s, t, dp);
}

int canYouMake(string &s1, string &s2)
{
  int m = s1.size();
  int n = s2.size();
  vector<vector<int>> dp(m, vector<int>(n + 1, -1));

  int temp = longestCommonSubsequences(m - 1, n - 1, s1, s2, dp);

  return m - temp + n - temp;
}