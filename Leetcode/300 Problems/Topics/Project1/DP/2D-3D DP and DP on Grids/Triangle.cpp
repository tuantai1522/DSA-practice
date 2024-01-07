// https://www.codingninjas.com/studio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int minimumPathSumHelper(int i, int j,
                         vector<vector<int>> &triangle, int n,
                         vector<vector<int>> &dp)
{
  if (i == n - 1)
    return triangle[i][j];

  if (dp[i][j] != -1)
    return dp[i][j];

  int down = triangle[i][j] + minimumPathSumHelper(i + 1, j, triangle, n, dp);
  int right_down = triangle[i][j] + minimumPathSumHelper(i + 1, j + 1, triangle, n, dp);

  dp[i][j] = min(down, right_down);
  return dp[i][j];
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));

  return minimumPathSumHelper(0, 0, triangle, n, dp);
}

// Tabulation
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<vector<int>> dp(n, vector<int>(n, -1));

  for (int i = n - 1; i >= 0; --i)
  {
    for (int j = 0; j < triangle[i].size(); ++j)
    {
      if (i == n - 1)
      {
        dp[i][j] = triangle[i][j];
      }
      else
      {
        int down = triangle[i][j] + dp[i + 1][j];
        int right_down = triangle[i][j] + dp[i + 1][j + 1];

        dp[i][j] = min(down, right_down);
      }
    }
  }

  return dp[0][0];
}

// Space optimization
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
  vector<int> next(n);

  for (int i = n - 1; i >= 0; --i)
  {
    vector<int> cur(n);

    for (int j = 0; j < triangle[i].size(); ++j)
    {
      if (i == n - 1)
      {
        cur[j] = triangle[i][j];
      }
      else
      {
        int down = triangle[i][j] + next[j];
        int right_down = triangle[i][j] + next[j + 1];

        cur[j] = min(down, right_down);
      }
    }

    next = cur;
  }

  return next[0];
}