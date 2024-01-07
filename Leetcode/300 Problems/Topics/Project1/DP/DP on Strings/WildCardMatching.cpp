// https://www.codingninjas.com/studio/problems/wildcard-pattern-matching_701650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization
bool wildcardMatchingHelper(int i, int j, string pattern, string text,
                            vector<vector<int>> &dp)
{
  if (i == 0 && j == 0)
    return true;

  if ((i == 0 && j != 0))
    return false;

  if ((i != 0 && j == 0))
  {
    for (int ii = 1; ii <= i; ++ii)
    {
      if (pattern[ii - 1] != '*')
        return false;
    }

    return true;
  }
  if (dp[i][j] != -1)
    return dp[i][j];
  if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
    return dp[i][j] = wildcardMatchingHelper(i - 1, j - 1, pattern, text, dp);
  else if (pattern[i - 1] == '*')
    return dp[i][j] = wildcardMatchingHelper(i - 1, j, pattern, text, dp) ||
                      wildcardMatchingHelper(i, j - 1, pattern, text, dp);
}
bool wildcardMatching(string pattern, string text)
{
  int m = pattern.size();
  int n = text.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  return wildcardMatchingHelper(m, n, pattern, text, dp);
}

// Tabulation
bool wildcardMatching(string pattern, string text)
{
  int m = pattern.size();
  int n = text.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // Base case
  dp[0][0] = 1;
  for (int i = 1; i <= m; ++i)
  {
    int check = 1;
    for (int ii = 1; ii <= i; ++ii)
    {
      if (pattern[ii - 1] != '*')
      {
        check = 0;
        break;
      }
    }

    dp[i][0] = check;
  }

  for (int j = 1; j <= n; ++j)
  {
    dp[0][j] = 0;
  }

  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        dp[i][j] = dp[i - 1][j - 1];
      else if (pattern[i - 1] == '*')
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
    }
  }
  return dp[m][n];
}

// Space optimization
bool wildcardMatching(string pattern, string text)
{
  int m = pattern.size();
  int n = text.size();
  vector<int> prev(n + 1, 0);
  // Base case
  prev[0] = 1;

  for (int j = 1; j <= n; ++j)
  {
    prev[j] = 0;
  }

  for (int i = 1; i <= m; ++i)
  {
    int check = 1;
    for (int ii = 1; ii <= i; ++ii)
    {
      if (pattern[ii - 1] != '*')
      {
        check = 0;
        break;
      }
    }
    vector<int> cur(n + 1, 0);

    cur[0] = check;

    for (int j = 1; j <= n; ++j)
    {
      if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
        cur[j] = prev[j - 1];
      else if (pattern[i - 1] == '*')
        cur[j] = prev[j] || cur[j - 1];
    }
    prev = cur;
  }
  return prev[n];
}