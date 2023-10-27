// https://leetcode.com/problems/combination-sum/description/
#include <bits/stdc++.h>
using namespace std;

void f(vector<int> &candidates, int index, int target, vector<int> &temp, vector<vector<int>> &ans)
{

  if (target == 0)
  {
    ans.push_back(temp);
    return;
  }

  for (int i = index; i < candidates.size(); ++i)
  {
    if (i > index && candidates[i] == candidates[i - 1])
      continue; // can not get that
    if (candidates[i] > target)
      break;
    // pick current element
    temp.push_back(candidates[i]);
    f(candidates, i + 1, target - candidates[i], temp, ans);

    // not pick current element
    temp.pop_back();
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
  vector<vector<int>> ans;
  vector<int> temp;
  sort(candidates.begin(), candidates.end());
  f(candidates, 0, target, temp, ans);

  return ans;
}