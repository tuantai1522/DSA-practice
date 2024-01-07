// https://www.codingninjas.com/studio/problems/rose-garden_2248080?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
#include <bits/stdc++.h>

bool func(vector<int> arr, int n, int mid, int k, int m)
{
  vector<int> temp(n, 0);

  int count = 0;
  int total = 0;
  // 1 is doomed, 0 is not doomed
  for (int i = 0; i < n; ++i)
  {
    temp[i] = mid >= arr[i] ? 1 : 0;

    if (temp[i] == 1)
    {
      ++count;

      if (count == k)
      {
        ++total;
        if (total == m)
          return true;
      }
    }
    else
      count = 0;
  }

  return false;
}

bool func(vector<int> arr, int n, int mid, int k, int m)
{
  int count = 0;

  int total = 0;
  for (int i = 0; i < n; ++i)
  {
    if (arr[i] <= mid)
      count++;
    else
    {
      total += count / k;
      count = 0;
    }
  }

  total += count / k;
  return total >= m;
}

int roseGarden(vector<int> arr, int k, int m)
{
  int n = arr.size();

  // not possible
  if (k * m > n)
    return -1;

  int mini = INT_MAX;
  int maxi = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    maxi = max(maxi, arr[i]);
    mini = min(mini, arr[i]);
  }

  int low = mini;
  int high = maxi;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    bool check = func(arr, n, mid, k, m);

    if (check)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return low;
}