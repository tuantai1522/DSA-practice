#include <bits/stdc++.h>

// Memorization
int mod = (int)(1e9 + 7);

int mazeObstaclesHelper(int row, int col,
                        vector<vector<int>> mat,
                        vector<vector<int>> &dp)
{

  if (row == 0 && col == 0)
    return 1;

  if (row < 0 || col < 0)
    return 0;

  if (dp[row][col] != -1)
    return dp[row][col];

  if (mat[row][col] == -1)
    return 0;

  // move left
  int left = mazeObstaclesHelper(row, col - 1, mat, dp);

  // move top
  int top = mazeObstaclesHelper(row - 1, col, mat, dp);

  dp[row][col] = (left + top) % mod;
  return dp[row][col];
}
int mazeObstacles(int m, int n, vector<vector<int>> &mat)
{
  vector<vector<int>> dp(m, vector<int>(n, -1));

  return mazeObstaclesHelper(m - 1, n - 1, mat, dp);
}

// Tabulation
int mazeObstacles(int m, int n, vector<vector<int>> &mat)
{
  vector<vector<int>> dp(m, vector<int>(n, 0));

  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == 0 && j == 0)
        dp[i][j] = 1;
      else
      {
        if (mat[i][j] == -1)
          continue;
        else
        {
          int top = 0;
          int left = 0;

          if (i > 0)
            top = dp[i - 1][j];

          if (j > 0)
            left = dp[i][j - 1];

          dp[i][j] = (left + top) % mod;
        }
      }
    }
  }
  return dp[m - 1][n - 1];
}