// https://www.codingninjas.com/studio/problems/occurrence-of-x-in-a-sorted-array_630456?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
#include <bits/stdc++.h>
int count(vector<int> &arr, int n, int x)
{
  int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
  int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

  if (first == n || arr[first] != x)
    return 0;

  return last - first;
}
