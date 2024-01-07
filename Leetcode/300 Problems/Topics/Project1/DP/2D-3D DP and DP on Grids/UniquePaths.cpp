// https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int uniquePathsHelper(int row, int col,
                      vector<vector<int>> &dp)
{
  if (row == 0 && col == 0)
  {
    return 1;
  }
  if (row < 0 || col < 0)
  {
    return 0;
  }
  if (dp[row][col] != -1)
  {
    return dp[row][col];
  }

  int left = uniquePathsHelper(row, col - 1, dp);
  int top = uniquePathsHelper(row - 1, col, dp);

  dp[row][col] = left + top;

  return dp[row][col];
}
int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return uniquePathsHelper(m - 1, n - 1, dp);
}

// Tabulation
int uniquePaths(int m, int n)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == 0 && j == 0)
        dp[0][0] = 1;
      else
      {
        int left = 0;
        int top = 0;

        if (i > 0)
          top = dp[i - 1][j];

        if (j > 0)
          left = dp[i][j - 1];

        dp[i][j] = top + left;
      }
    }
  }
  return dp[m - 1][n - 1];
}

// Space optimization
int uniquePaths(int m, int n)
{
  vector<int> prev(n, 1);

  for (int i = 1; i < m; ++i)
  {
    vector<int> cur(n);
    for (int j = 0; j < n; ++j)
    {
      int left = 0;
      int top = 0;

      if (i > 0)
        top = prev[j];

      if (j > 0)
        left = cur[j - 1];

      cur[j] = top + left;
    }
    prev = cur;
  }
  return prev[n - 1];
}