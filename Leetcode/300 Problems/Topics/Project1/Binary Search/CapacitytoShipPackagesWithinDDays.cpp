// 1 2 3 4 5 6 7 8 9 10
// d = 5

// mid = 10 => {1, 2, 3, 4}; {5}; {6}; {7}; {8}; {9}; {10} => 7
// mid = 12 => {1, 2, 3, 4}; {5, 6}; {7}; {8}; {9}; {10} => 6
// mid = 15 => {1, 2, 3, 4, 5}; {6, 7}; {8}; {9}; {10} => 5
// mid = 21 => {1, 2, 3, 4, 5, 6}; {7, 8}; {9}; {10} => 4
#include <bits/stdc++.h>
int func(vector<int> weights, int n, int capa, int d)
{
  int days = 1;

  int total = 0;
  for (int i = 0; i < n; ++i)
  {
    total += weights[i];

    if (total > capa)
    {
      ++days;
      total = weights[i]; // remove all the packages before and only take current package
    }
  }

  return days <= d;
}
int leastWeightCapacity(vector<int> &weights, int d)
{
  int n = weights.size();

  int total = 0;
  int maxi = INT_MIN;
  for (int i = 0; i < n; ++i)
  {
    total += weights[i];
    maxi = max(maxi, weights[i]);
  }

  int low = maxi;
  int high = total;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    bool check = func(weights, n, mid, d);
    if (check)
      high = mid - 1;
    else
      low = mid + 1;
  }

  return low;
}