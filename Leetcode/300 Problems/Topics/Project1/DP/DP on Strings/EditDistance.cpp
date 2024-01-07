// https://www.codingninjas.com/studio/problems/edit-distance_630420?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int editDistanceHelper(int i, int j, string str1, string str2,
                       vector<vector<int>> &dp)
{
  if (i == 0)
    return j;

  if (j == 0)
    return i;

  if (dp[i][j] != -1)
    return dp[i][j];

  if (str1[i - 1] != str2[j - 1])
    return dp[i][j] = min({1 + editDistanceHelper(i - 1, j, str1, str2, dp),       // delete
                           1 + editDistanceHelper(i, j - 1, str1, str2, dp),       // insert
                           1 + editDistanceHelper(i - 1, j - 1, str1, str2, dp)}); // replace
  else
    return dp[i][j] = editDistanceHelper(i - 1, j - 1, str1, str2, dp);
}
int editDistance(string str1, string str2)
{
  int m = str1.size();
  int n = str2.size();
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

  return editDistanceHelper(m, n, str1, str2, dp);
}

// Tabulation
int editDistance(string str1, string str2)
{
  int m = str1.size(); // số dòng
  int n = str2.size(); // số cột
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  // i dòng; j cột
  for (int i = 1; i <= m; ++i)
    dp[i][0] = i;
  for (int j = 1; j <= n; ++j)
    dp[0][j] = j;

  for (int i = 1; i <= m; ++i)
  {
    for (int j = 1; j <= n; ++j)
    {
      if (str1[i - 1] != str2[j - 1])
        dp[i][j] = min({1 + dp[i - 1][j],       // delete
                        1 + dp[i][j - 1],       // insert
                        1 + dp[i - 1][j - 1]}); // replace
      else
        dp[i][j] = dp[i - 1][j - 1];
    }
  }
  return dp[m][n];
}

// Space optimization
int editDistance(string str1, string str2)
{
  int m = str1.size(); // số dòng
  int n = str2.size(); // số cột
  vector<int> prev(n + 1, 0);

  // i dòng; j cột
  for (int j = 1; j <= n; ++j)
    prev[j] = j;

  for (int i = 1; i <= m; ++i)
  {
    vector<int> cur(n + 1, 0);
    cur[0] = i;

    for (int j = 1; j <= n; ++j)
    {
      if (str1[i - 1] != str2[j - 1])
        cur[j] = min({1 + prev[j],       // delete
                      1 + cur[j - 1],    // insert
                      1 + prev[j - 1]}); // replace
      else
        cur[j] = prev[j - 1];
    }
    prev = cur;
  }
  return prev[n];
}