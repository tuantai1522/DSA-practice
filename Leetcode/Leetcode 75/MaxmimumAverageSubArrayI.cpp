//https://leetcode.com/problems/maximum-average-subarray-i/description/?envType=study-plan-v2&envId=leetcode-75
#include<bits/stdc++.h>
using namespace std;    
double findMaxAverage(vector<int>& nums, int k) {
  int size = nums.size();
  double sum = 0;
  if(size == 1 && k == 1) return nums[0];

  for(int i = 0; i < k; ++i){
    sum += nums[i];
  }

  int first = 0;
  double ans = sum / k;

  for(int i = k; i < size; ++i){
    sum = (sum + nums[i] - nums[first++]);
    ans = max(ans, sum / k);
  }
  return ans;
}
int main(){

}