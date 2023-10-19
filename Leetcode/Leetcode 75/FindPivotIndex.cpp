//https://leetcode.com/problems/find-pivot-index/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;  
int pivotIndex(vector<int>& nums) {
  int size = nums.size();
  int sum = 0;
  
  for(int i = 0; i < size; ++i){
    sum += nums[i];
  }

  //first index
  if(sum - nums[0] == 0) return 0;

  //other index
  for(int i = 1; i < size; ++i){
    nums[i] += nums[i - 1];

    cout << "nums[" << i << "]" << " = " << nums[i] << endl;

    if(sum - nums[i] == nums[i - 1]){
      return i;
    }
  }


  return -1;
}