// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>

// Memorization
int getMaxPathSumHelper(int i, int j, int m, int n,
                        vector<vector<int>> &matrix,
                        vector<vector<int>> &dp)
{
  if (j < 0 || j >= n)
    return -1e7;

  if (i == m - 1)
    return matrix[m - 1][j];

  if (dp[i][j] != -1)
    return dp[i][j];

  int down_left = matrix[i][j] + getMaxPathSumHelper(i + 1, j - 1, m, n, matrix, dp);
  int down = matrix[i][j] + getMaxPathSumHelper(i + 1, j, m, n, matrix, dp);
  int down_right = matrix[i][j] + getMaxPathSumHelper(i + 1, j + 1, m, n, matrix, dp);

  dp[i][j] = max({down_left, down, down_right});

  return dp[i][j];
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
  int m = matrix.size();    // số dòng
  int n = matrix[0].size(); // số cột

  int ans = -1e7;

  vector<vector<int>> dp(m, vector<int>(n, -1));
  for (int j = 0; j < n; ++j)
  {

    int count = getMaxPathSumHelper(0, j, m, n, matrix, dp);

    ans = max(ans, count);
  }
  return ans;
}

// Tabulation
int getMaxPathSum(vector<vector<int>> &matrix)
{
  int m = matrix.size();    // số dòng
  int n = matrix[0].size(); // số cột

  int ans = -1e7;

  vector<vector<int>> dp(m, vector<int>(n, 0));

  // except last row
  for (int i = m - 1; i >= 0; --i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (i == m - 1)
        dp[m - 1][j] = matrix[m - 1][j];
      else
      {
        // can move left if j - 1 >= 0
        int down_left = (j - 1 >= 0) ? dp[i + 1][j - 1] : -1e7;

        int down = dp[i + 1][j];

        // can move right if j + 1 < n
        int down_right = (j + 1 < n) ? dp[i + 1][j + 1] : -1e7;

        dp[i][j] = matrix[i][j] + max({down_left, down, down_right});
      }
    }
  }

  for (int j = 0; j < n; ++j)
  {
    ans = max(ans, dp[0][j]);
  }
  return ans;
}
