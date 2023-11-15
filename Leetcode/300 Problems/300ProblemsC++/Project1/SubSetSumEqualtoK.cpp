// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?fbclid=IwAR1TGndMhpz0fmUIzMzk3N8M5HW1DyZsJ0HjcC3LBrQ-_-CeGAP79U2xJhk
using namespace std;
#include <bits/stdc++.h>
bool subsetSumToKHelper(int n, int k, vector<int> arr,
                        int index, int &totalSum)
{
  if (totalSum == k)
  {
    return true;
  }
  if (index >= n || totalSum > k)
  {
    return false;
  }

  totalSum += arr[index];

  bool subSet1 = subsetSumToKHelper(n, k, arr, index + 1, totalSum);

  totalSum -= arr[index];
  bool subSet2 = subsetSumToKHelper(n, k, arr, index + 1, totalSum);

  return subSet1 || subSet2;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
  int totalSum = 0;

  return subsetSumToKHelper(n, k, arr, 0, totalSum);
  // Write your code here.
}