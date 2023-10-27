// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
void countTotal(vector<int> arr, int n, int index, int sum, vector<int> &ans)
{
  if (index >= n)
  {
    ans.push_back(sum);
    return;
  }
  countTotal(arr, n, index + 1, sum + arr[index], ans);

  countTotal(arr, n, index + 1, sum, ans);
}
vector<int> subsetSums(vector<int> arr, int N)
{
  vector<int> ans;
  countTotal(arr, N, 0, 0, ans);
  return ans;
}