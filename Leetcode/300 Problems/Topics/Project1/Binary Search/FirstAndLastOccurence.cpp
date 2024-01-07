// https://www.codingninjas.com/studio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries

// Using lower_bound and upper_bound method

#include <bits/stdc++.h>

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int x)
{
  // 8
  // 0 1 2 3 4 5  6  7
  // 2 4 6 8 8 8 11 13
  // ans = {3, 5}

  pair<int, int> ans = {-1, -1};

  int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
  int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

  // không tìm thấy bất cứ x nào trong arr

  if (first == n || arr[first] != x)
    return ans;

  ans.first = first;
  ans.second = last - 1;
  return ans;
}

// Iterative
pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int x)
{
  // 8
  // 0 1 2 3 4 5  6  7
  // 2 4 6 8 8 8 11 13
  // ans = {3, 5}

  pair<int, int> ans = {-1, -1};
  int low = 0;
  int high = n - 1;
  // find first
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
      ans.first = mid;
      high = mid - 1;
    }
    else if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  low = 0;
  high = n - 1;
  // find last
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (arr[mid] == x)
    {
      ans.second = mid;
      low = mid + 1;
    }
    else if (arr[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return ans;
}
