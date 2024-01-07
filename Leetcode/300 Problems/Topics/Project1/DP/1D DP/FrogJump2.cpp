// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;

// Memorization
int FrogJump_2(int n, int k, vector<int> &heights, vector<int> &dp)
{
  if (n == 0)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int minSteps = INT_MAX;
  for (int i = 1; i <= k; ++i)
  {
    if (n - i >= 0)
    {
      int count = FrogJump_2(n - i, k, heights, dp) + abs(heights[n] - heights[n - i]);
      minSteps = min(minSteps, count);
    }
  }
  dp[n] = minSteps;
  return dp[n];
}

int main()
{
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> heights(n);
  vector<int> dp(n + 1, -1);
  for (int i = 0; i < n; ++i)
  {
    cin >> heights[i];
  }
  cout << FrogJump_2(n - 1, k, heights, dp);
  return 0;
}

// Tabulation
int FrogJump_2(int n, int k, vector<int> &heights)
{
  if (n == 0)
    return 0;

  vector<int> dp(n + 1, 0);
  for (int i = 1; i < n; ++i)
  {
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; ++j)
    {
      if (i - j >= 0)
      {
        int count = dp[i - j] + abs(heights[i] - heights[i - j]);
        minSteps = min(minSteps, count);
      }
    }
    dp[i] = minSteps;
  }

  return dp[n - 1];
}
int main()
{
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> heights(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> heights[i];
  }
  cout << FrogJump_2(n, k, heights);
  return 0;
}