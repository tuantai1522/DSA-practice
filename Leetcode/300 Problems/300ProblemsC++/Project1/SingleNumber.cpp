//https://leetcode.com/problems/single-number/
#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums) {
	int ans = 0;
	for (int num : nums) {
		ans ^= num;
	}

	return ans;
}