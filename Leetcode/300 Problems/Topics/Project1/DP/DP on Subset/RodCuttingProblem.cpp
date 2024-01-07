// https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization
int cutRodHelper(int idx, int n, vector<int> &price,
                 vector<vector<int>> &dp)
{
  if (idx == 0)
    return price[idx] * n;

  if (dp[idx][n] != -1)
    return dp[idx][n];

  int take = INT_MIN;
  int rodLength = idx + 1;

  if (rodLength <= n)
    take = price[idx] + cutRodHelper(idx, n - rodLength, price, dp);
  int notTake = 0 + cutRodHelper(idx - 1, n, price, dp);

  dp[idx][n] = max(take, notTake);

  return dp[idx][n];
}

int cutRod(vector<int> &price, int n)
{
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

  return cutRodHelper(n - 1, n, price, dp);
}

// Tabulation
int cutRod(vector<int> &price, int length)
{
  vector<vector<int>> dp(length, vector<int>(length + 1, 0));

  for (int n = 0; n <= length; ++n)
  {
    dp[0][n] = price[0] * n;
  }

  for (int idx = 1; idx < length; ++idx)
  {
    for (int n = 0; n <= length; ++n)
    {
      int take = INT_MIN;
      int rodLength = idx + 1;

      if (rodLength <= n)
        take = price[idx] + dp[idx][n - rodLength];

      int notTake = 0 + dp[idx - 1][n];

      dp[idx][n] = max(take, notTake);
    }
  }

  return dp[length - 1][length];
}

// Space optimization
int cutRod(vector<int> &price, int length)
{
  vector<int> prev(length + 1, 0);

  for (int n = 0; n <= length; ++n)
  {
    prev[n] = price[0] * n;
  }

  for (int idx = 1; idx < length; ++idx)
  {
    vector<int> cur(length + 1, 0);
    for (int n = 0; n <= length; ++n)
    {
      int take = INT_MIN;
      int rodLength = idx + 1;

      if (rodLength <= n)
        take = price[idx] + cur[n - rodLength];

      int notTake = 0 + prev[n];

      cur[n] = max(take, notTake);
    }
    prev = cur;
  }

  return prev[length];
}