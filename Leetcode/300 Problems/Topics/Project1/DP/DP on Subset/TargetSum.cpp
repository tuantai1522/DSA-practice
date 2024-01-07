// https://www.codingninjas.com/studio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
// Space optimization
int targetSum(int n, int target, vector<int> &arr)
{
  int totalSum = 0;
  for (int i = 0; i < n; ++i)
  {
    totalSum += arr[i];
  }

  vector<int> prev(totalSum + 1, 0), cur(totalSum + 1, 0);

  if (arr[0] == 0)
    prev[0] = 2;
  else
    prev[0] = 1;

  if (arr[0] <= totalSum && arr[0] != 0)
  {
    prev[arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i)
  {
    for (int target = 0; target <= totalSum; ++target)
    {
      int notPick = prev[target];

      // Include the current element
      int pick = 0;
      if (arr[i] <= target)
        pick = prev[target - arr[i]];

      cur[target] = (pick + notPick);
    }

    prev = cur;
  }

  if (totalSum - target < 0 || (totalSum - target) % 2)
    return 0;

  return prev[(totalSum - target) / 2];
}
