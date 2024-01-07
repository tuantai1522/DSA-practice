// https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// Memorization
int frogJumpHelper(int n, vector<int> &heights, vector<int> &dp)
{
  if (n == 0)
    return 0;

  if (dp[n] != -1)
    return dp[n];

  int move1StepBackward = frogJumpHelper(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
  int move2StepsBackward = INT_MAX;

  if (n > 1)
  {
    move2StepsBackward = frogJumpHelper(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
  }

  dp[n] = min(move1StepBackward, move2StepsBackward);

  return dp[n];
}

int frogJump(int n, vector<int> &heights)
{
  vector<int> dp(n + 1, -1);
  return frogJumpHelper(n - 1, heights, dp);
}

// Tabulation
int frogJump(int n, vector<int> &heights)
{
  if (n == 0)
    return 0;

  vector<int> dp(n + 1);
  dp[0] = 0;
  dp[1] = abs(heights[1] - heights[0]);

  for (int i = 2; i < n; ++i)
  {
    int oneStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
    int twoSteps = dp[i - 2] + abs(heights[i] - heights[i - 2]);
    dp[i] = min(oneStep, twoSteps);
  }

  return dp[n - 1];
}

// Space optimization
int frogJump(int n, vector<int> &heights)
{
  if (n == 0)
    return 0;

  int prev2 = 0;
  int prev = abs(heights[1] - heights[0]);
  for (int i = 2; i < n; ++i)
  {
    int oneStep = prev + abs(heights[i] - heights[i - 1]);
    int twoSteps = prev2 + abs(heights[i] - heights[i - 2]);

    int cur = min(oneStep, twoSteps);
    prev2 = prev;
    prev = cur;
  }

  return prev;
}