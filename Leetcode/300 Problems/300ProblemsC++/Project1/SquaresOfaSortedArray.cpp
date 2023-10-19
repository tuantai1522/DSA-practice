//https://leetcode.com/problems/squares-of-a-sorted-array/description/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;    
vector<int> sortedSquares(vector<int>& nums) {
	int n = nums.size();
	vector<int> ans;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		if (abs(nums[left]) <= abs(nums[right])) {
			ans.push_back(pow(nums[right--], 2));
		}
		else {
			ans.push_back(pow(nums[left++], 2));
		}
	}
	reverse(ans.begin(), ans.end());

	return ans;
}