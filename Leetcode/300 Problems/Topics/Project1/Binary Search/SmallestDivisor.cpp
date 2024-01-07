// https://www.codingninjas.com/studio/problems/smallest-divisor-with-the-given-limit_1755882?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
#include <bits/stdc++.h>

bool func(vector<int> arr, int n, int mid, int limit)
{
  int count = 0;
  for (int i = 0; i < n; ++i)
  {
    count += ceil(arr[i] * 1.0 / mid);
  }

  return count <= limit;
}

// 1 2 5 9
// 6
// limit = 9 => 1 + 1 + 1 + 1 = 4;
// limit = 8 => 1 + 1 + 1 + 2 = 5;
// limit = 7 => 1 + 1 + 1 + 2 = 5;
// limit = 6 => 1 + 1 + 1 + 2 = 5;
// limit = 5 => 1 + 1 + 1 + 2 = 5;
// limit = 4 => 1 + 1 + 2 + 3 = 7;
// limit = 3 => 1 + 1 + 2 + 3 = 7;
// limit = 2 => 1 + 1 + 3 + 5 = 10;
// limit = 1 => 1 + 2 + 5 + 9 = 17;
int smallestDivisor(vector<int> &arr, int limit)
{
  int n = arr.size();

  int maxi = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    maxi = max(maxi, arr[i]);
  }

  int low = 1;
  int high = maxi;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    bool check = func(arr, n, mid, limit);

    if (check)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return low;
}