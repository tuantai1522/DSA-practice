// https://leetcode.com/problems/climbing-stairs/submissions/1138042491/?envType=study-plan-v2&envId=top-interview-150

// Recursion
int climbStairsHelper(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  return climbStairsHelper(n - 1) + climbStairsHelper(n - 2);
}
int climbStairs(int n)
{
  return climbStairsHelper(n);
}

// Tabulation
int climbStairsHelper(vector<int> &dp, int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  if (dp[n] != -1)
    return dp[n];

  dp[n] = climbStairsHelper(dp, n - 1) + climbStairsHelper(dp, n - 2);

  return dp[n];
}
int climbStairs(int n)
{
  vector<int> dp(n + 1, -1);

  return climbStairsHelper(dp, n);
}

// Memorization
int climbStairs(int n)
{
  if (n == 1)
    return 1;
  if (n == 2)
    return 2;

  vector<int> dp(n + 1, 0);
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  return dp[n];
}