// https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
using namespace std;
// Memorization
int ninjaTrainingHelper(int current_day,
                        int previous_day,
                        vector<vector<int>> &points,
                        vector<vector<int>> &dp)
{
  if (current_day == 0)
  {
    int maxPoint = 0;

    for (int i = 0; i < 3; ++i)
    {
      if (i != previous_day)
      {
        maxPoint = max(maxPoint, points[0][i]);
      }
    }
    dp[current_day][previous_day] = maxPoint;

    return dp[current_day][previous_day];
  }

  if (dp[current_day][previous_day] != -1)
    return dp[current_day][previous_day];

  int maxPoint = 0;

  for (int i = 0; i < 3; ++i)
  {
    if (i != previous_day)
    {
      int count = ninjaTrainingHelper(current_day - 1, i, points, dp) + points[current_day][i];
      maxPoint = max(maxPoint, count);
    }
  }
  dp[current_day][previous_day] = maxPoint;

  return dp[current_day][previous_day];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n + 1, vector<int>(4, -1));

  return ninjaTrainingHelper(n - 1, 3, points, dp);
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points)
{
  vector<vector<int>> dp(n + 1, vector<int>(4, 0));
  dp[0][0] = max(points[0][1], points[0][2]);
  dp[0][1] = max(points[0][0], points[0][2]);
  dp[0][2] = max(points[0][0], points[0][1]);
  dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

  // last column to store value of current row
  for (int current_day = 1; current_day < n; ++current_day)
  {
    for (int previous_task = 0; previous_task < 3; ++previous_task)
    {
      for (int current_task = 0; current_task < 3; ++current_task)
      {
        if (current_task != previous_task)
        {
          int count = points[current_day][current_task] + dp[current_day - 1][current_task];
          dp[current_day][previous_task] = max(dp[current_day][previous_task], count);
        }
      }
    }
    dp[current_day][3] = max({dp[current_day][0], dp[current_day][1], dp[current_day][2]});
  }

  return dp[n - 1][3];
}