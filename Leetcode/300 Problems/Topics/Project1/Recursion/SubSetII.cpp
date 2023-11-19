// https://practice.geeksforgeeks.org/problems/subset-sums2234/1
#include <bits/stdc++.h>
using namespace std;
void countTotal(vector<int> arr, int n, int index, vector<int> &temp, vector<vector<int>> &ans)
{
  ans.push_back(temp);

  for (int i = index; i < n; ++i)
  {
    // always pick the first element in the new size
    // check the second element to the end if currentElement equals to before element => remove
    if (i != index && arr[i] == arr[i - 1])
      continue;
    temp.push_back(arr[i]);
    countTotal(arr, n, i + 1, temp, ans);

    temp.pop_back();
  }
}
vector<vector<int>> subsetsWithDup(vector<int> &arr)
{
  sort(arr.begin(), arr.end());
  int n = arr.size();
  vector<int> temp;
  vector<vector<int>> ans;
  countTotal(arr, n, 0, temp, ans);
  return ans;
}