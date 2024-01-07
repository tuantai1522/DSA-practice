// https://www.codingninjas.com/studio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
long long int houseRobberHelper(int index,
                                int n,
                                vector<int> &valueInHouse,
                                vector<long long int> &dp)
{
  if (index < 0 || index == n)
    return 0;

  if (index == 0)
    return valueInHouse[index];

  if (dp[index] != -1)
    return dp[index];

  long long int pick = valueInHouse[index] + houseRobberHelper(index - 2, n, valueInHouse, dp);

  long long int not_pick = 0 + houseRobberHelper(index - 1, n, valueInHouse, dp);

  dp[index] = max(pick, not_pick);

  return dp[index];
}
long long int houseRobber(vector<int> &valueInHouse)
{
  long long int n = valueInHouse.size();

  if (n == 1)
    return valueInHouse[0];

  vector<long long int> dp1(n, -1);
  vector<long long int> dp2(n, -1);
  return max(houseRobberHelper(n - 1, 0, valueInHouse, dp1),  // remove the first index
             houseRobberHelper(n - 2, n, valueInHouse, dp2)); // remove the last index

  // Write your code here.
}