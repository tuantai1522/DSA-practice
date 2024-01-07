// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
#include <bits/stdc++.h>
bool func(vector<int> &boards, int n, int k, int boardsLength)
{
  int countPainter = 1;
  long long int totalLength = boards[0];
  for (int i = 1; i < n; ++i)
  {
    if (totalLength + boards[i] <= boardsLength)
      totalLength += boards[i];
    else
    {
      ++countPainter;
      totalLength = boards[i];
    }
  }

  return countPainter > k;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
  int n = boards.size();
  int maxi = INT_MIN;
  int total = 0;

  for (int i = 0; i < n; ++i)
  {
    maxi = max(maxi, boards[i]);
    total += boards[i];
  }

  int low = maxi;
  int high = total;

  while (low <= high)
  {
    int mid = (low + high) / 2;

    bool check = func(boards, n, k, mid);

    if (check)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return low;
}