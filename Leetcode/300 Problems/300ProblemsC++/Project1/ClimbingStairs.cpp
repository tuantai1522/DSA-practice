//https://leetcode.com/problems/climbing-stairs/
#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;
int climbStairs(int n) {
	vector<int>dp(n + 1);
	if (n == 1 || n == 2) return n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}