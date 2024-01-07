// https://www.codingninjas.com/studio/problems/stocks-are-profitable_893405?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
  // At index i, try to find the minimum from [0, i -1 ]
  int mini = prices[0];
  int maxProfit = 0;

  int n = prices.size();
  for (int i = 1; i < n; ++i)
  {
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }
  return maxProfit;
}