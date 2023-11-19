//https://leetcode.com/problems/combination-sum-ii/description/
#include <bits/stdc++.h> 
using namespace std;
void f(vector<int>& candidates, int index, int target, vector<int>& temp, set<vector<int>>& my_set){
  if(target < 0 || index >= candidates.size() ) return;


  if (target == 0){
    my_set.insert(temp);
    return;
  }else{
    //pick current element
    temp.push_back(candidates[index]);
    f(candidates, index + 1, target - candidates[index], temp, my_set);
    
    //not pick current element
    temp.pop_back();
  }
  f(candidates, index + 1, target, temp, my_set);
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    set<vector<int>> my_set;
    vector<int> temp;
    f(candidates, 0, target, temp, ans);

    vector<int> ans(my_set.begin(), my_set.end());
    return ans;
}