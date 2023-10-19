//https://leetcode.com/problems/3sum/description/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	int size = nums.size();
	vector<vector<int>>ans;

	sort(nums.begin(), nums.end());
	//bỏ 2 phần tử cuối vì đó là j và k
	for (int i = 0; i < size - 2; ++i) {
		// //move index i to the next new element
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}

		int j = i + 1;
		int k = size - 1;

		//nhỏ hơn 0 -> move j to right
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (sum < 0) {
				++j;
			}
			else if (sum > 0) {
				--k;
			}
			else {
				ans.push_back({ nums[i],nums[j],nums[k] });
				++j;
				--k;
				//move index j to the next new element
				while (j < k && nums[j] == nums[j - 1]) {
					++j;
				}
				//move index k to the next new element
				while (j < k && nums[k] == nums[k + 1]) {
					--k;
				}
			}
		}
	}

	return ans;
}