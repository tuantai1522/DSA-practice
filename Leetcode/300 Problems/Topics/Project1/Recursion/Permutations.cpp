// https://leetcode.com/problems/permutations/description/
#include <bits/stdc++.h>
using namespace std;
void Permutations(vector<int> &nums, int n, vector<int> &temp, vector<int> &visited, vector<vector<int>> &ans)
{
  if (temp.size() >= n)
  {
    ans.push_back(temp);
    return;
  }

  for (int i = 0; i < n; ++i)
  {
    // not visited
    if (visited[i] == 0)
    {
      temp.push_back(nums[i]);
      visited[i] = 1; // mark as visited
      Permutations(nums, n, temp, visited, ans);

      temp.pop_back();
      visited[i] = 0; // mark as not visited
    }
  }
}
vector<vector<int>> permute(vector<int> &nums)
{
  vector<vector<int>> ans;
  int n = nums.size();
  vector<int> temp;
  vector<int> visited(n, 0);
  Permutations(nums, n, temp, visited, ans);

  return ans;
}