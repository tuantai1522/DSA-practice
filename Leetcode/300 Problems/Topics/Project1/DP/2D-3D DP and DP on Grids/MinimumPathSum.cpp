// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int minSumPathHelper(int m, int n, vector<vector<int>> &grid,
                     vector<vector<int>> &dp)
{
  if (m < 0 || n < 0)
    return 1e7;

  if (m == 0 && n == 0)
    return grid[m][n];

  if (dp[m][n] != -1)
    return dp[m][n];

  // move up
  int top = grid[m][n] + minSumPathHelper(m - 1, n, grid, dp);

  // move left
  int left = grid[m][n] + minSumPathHelper(m, n - 1, grid, dp);

  dp[m][n] = min(top, left);
  return dp[m][n];
}

int minSumPath(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, -1));

  return minSumPathHelper(m - 1, n - 1, grid, dp);
}

// Tabulation
int minSumPath(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == 0 && j == 0)
        dp[0][0] = grid[0][0];
      else
      {
        int top = 1e7;
        int left = 1e7;

        if (i > 0)
          top = grid[i][j] + dp[i - 1][j];

        if (j > 0)
          left = grid[i][j] + dp[i][j - 1];

        dp[i][j] = min(top, left);
      }
    }
  }

  return dp[m - 1][n - 1];
}

// Space optimization
int minSumPath(vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();

  vector<int> prev(n, 0);

  for (int i = 0; i < m; ++i)
  {
    vector<int> cur(n, 0);

    for (int j = 0; j < n; ++j)
    {
      if (i == 0 && j == 0)
        cur[0] = grid[0][0];
      else
      {
        int top = 1e7;
        int left = 1e7;

        if (i > 0)
          top = grid[i][j] + prev[j];

        if (j > 0)
          left = grid[i][j] + cur[j - 1];

        cur[j] = min(top, left);
      }
    }
    prev = cur;
  }

  return prev[n - 1];
}