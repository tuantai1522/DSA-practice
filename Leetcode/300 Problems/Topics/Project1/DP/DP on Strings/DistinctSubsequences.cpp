// https://www.codingninjas.com/studio/problems/subsequence-counting_3755256?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
int module = 1e9 + 7;

// Memorization
int distinctSubsequencesHelper(int idx1, int idx2, string s, string t,
                               vector<vector<int>> &dp)
{
  if (idx2 < 0)
    return 1;
  if (idx1 < 0)
    return 0;

  if (dp[idx1][idx2] != -1)
    return dp[idx1][idx2];

  if (s[idx1] == t[idx2])
    return dp[idx1][idx2] = (distinctSubsequencesHelper(idx1 - 1, idx2 - 1, s, t, dp) + distinctSubsequencesHelper(idx1 - 1, idx2, s, t, dp)) % module;

  return dp[idx1][idx2] = distinctSubsequencesHelper(idx1 - 1, idx2, s, t, dp) % module;
}
int distinctSubsequences(string &str, string &sub)
{
  int length_1 = str.length();
  int length_2 = sub.length();
  vector<vector<int>> dp(length_1, vector<int>(length_2 + 1, -1));

  return distinctSubsequencesHelper(length_1 - 1, length_2 - 1, str, sub, dp);
}

// Tabulation
int distinctSubsequences(string &str, string &sub)
{
  int length_1 = str.length();
  int length_2 = sub.length();
  vector<vector<int>> dp(length_1 + 1, vector<int>(length_2 + 1, 0));
  for (int i = 0; i <= length_1; ++i)
    dp[i][0] = 1;

  for (int j = 1; j <= length_2; ++j)
    dp[0][j] = 0;

  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (str[idx1 - 1] == sub[idx2 - 1])
        dp[idx1][idx2] = (dp[idx1 - 1][idx2 - 1] + dp[idx1 - 1][idx2]) % module;
      else
        dp[idx1][idx2] = dp[idx1 - 1][idx2] % module;
    }
  }
  return dp[length_1][length_2];
}

// Space optimization
int distinctSubsequences(string &str, string &sub)
{
  int length_1 = str.length();
  int length_2 = sub.length();
  vector<int> prev(length_2 + 1, 0);
  prev[0] = 1;

  for (int j = 1; j <= length_2; ++j)
    prev[j] = 0;

  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    vector<int> cur(length_2 + 1, 0);
    cur[0] = 1;

    for (int idx2 = 1; idx2 <= length_2; ++idx2)
    {
      if (str[idx1 - 1] == sub[idx2 - 1])
        cur[idx2] = (prev[idx2 - 1] + prev[idx2]) % module;
      else
        cur[idx2] = prev[idx2] % module;
    }
    prev = cur;
  }
  return prev[length_2];
}

// 1D Array
int distinctSubsequences(string &str, string &sub)
{
  int length_1 = str.length();
  int length_2 = sub.length();
  vector<int> prev(length_2 + 1, 0);
  prev[0] = 1;

  for (int j = 1; j <= length_2; ++j)
    prev[j] = 0;

  for (int idx1 = 1; idx1 <= length_1; ++idx1)
  {
    for (int idx2 = length_2; idx2 >= 0; --idx2)
    {
      if (str[idx1 - 1] == sub[idx2 - 1])
        prev[idx2] = (prev[idx2 - 1] + prev[idx2]) % module;
    }
  }
  return prev[length_2];
}