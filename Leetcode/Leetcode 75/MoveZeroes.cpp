//https://leetcode.com/problems/move-zeroes/description/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;
void moveZeroes(vector<int>& nums) {
  //move all non-0 elements at top

  int lastNonZero = 0;
  for(int i = 0; i < nums.size(); ++i){
    if(nums[i] != 0){
      nums[lastNonZero++] = nums[i];
    }
  }

    //And the other is zero
    for(int i = lastNonZero; i < nums.size(); ++i){
      nums[i] = 0;
    }
  
}