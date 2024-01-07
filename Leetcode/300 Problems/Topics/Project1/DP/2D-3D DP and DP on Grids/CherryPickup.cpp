// https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int maximumChocolatesHelper(int i, int j1, int j2, int m,
                            int n, vector<vector<int>> &grid,
                            vector<vector<vector<int>>> &dp)
{
  if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n)
  {
    return -1e7;
  }

  if (i == m - 1)
  {
    if (j1 == j2)
      return grid[i][j1];
    else
      return grid[i][j1] + grid[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxi = -1e7;
  for (int firtMove = -1; firtMove <= 1; ++firtMove)
  {
    for (int secondMove = -1; secondMove <= 1; ++secondMove)
    {
      if (j1 == j2)
        maxi = max(maxi, grid[i][j1] + maximumChocolatesHelper(i + 1, j1 + firtMove, j2 + secondMove, m, n, grid, dp));
      else
        maxi = max(maxi, grid[i][j1] + grid[i][j2] + maximumChocolatesHelper(i + 1, j1 + firtMove, j2 + secondMove, m, n, grid, dp));
    }
  }
  dp[i][j1][j2] = maxi;
  return dp[i][j1][j2];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
  int m = grid.size();
  int n = grid[0].size();
  vector<vector<vector<int>>> dp(m,
                                 vector<vector<int>>(
                                     n, vector<int>(n, -1)));
  return maximumChocolatesHelper(0, 0, n - 1, m, n, grid, dp);
}
