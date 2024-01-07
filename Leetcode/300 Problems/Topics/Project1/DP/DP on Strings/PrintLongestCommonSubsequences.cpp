// https://www.codingninjas.com/studio/problems/print-longest-common-subsequence_8416383?leftPanelTabValue=SUBMISSION
string findLCS(int length_1, int length_2, string &s, string &t)
{
  // to build dp table
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

  // to print longest common subsequences;
  string ans(dp[length_1][length_2], '-');

  int index = dp[length_1][length_2] - 1;

  int i = length_1;
  int j = length_2;

  while (i > 0 && j > 0)
  {
    // ans is on the left
    if (s[i - 1] == t[j - 1])
    {
      ans[index--] = s[i - 1];
      i = i - 1;
      j = j - 1;
    }
    else if (dp[i][j - 1] < dp[i - 1][j])
    {
      i = i - 1;
    }
    else
    {
      j = j - 1;
    }
  }
  return ans;
}