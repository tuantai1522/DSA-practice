// https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
#include <bits/stdc++.h>
long long int func(vector<int> &arr, int n, int mid)
{
  long long int ans = 0;
  for (int i = 0; i < n; ++i)
    ans += ceil(arr[i] * 1.0 / mid);
  return ans;
}

int findMax(vector<int> &arr, int n)
{
  int maxi = INT_MIN;
  for (int i = 0; i < n; ++i)
    maxi = max(maxi, arr[i]);
  return maxi;
}
int minimumRateToEatBananas(vector<int> arr, int h)
{
  int n = arr.size();

  int low = 1;
  int high = findMax(arr, n);

  while (low <= high)
  {
    long long int mid = (low + high) / 2;
    long long int total = func(arr, n, mid);
    if (total <= h)
      high = mid - 1;
    else
      low = mid + 1;
  }
  return low;
}