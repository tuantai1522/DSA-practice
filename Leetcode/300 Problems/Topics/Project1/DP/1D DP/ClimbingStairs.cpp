// www.codingninjas.com/studio/problems/count-ways-to-reach-nth-stairs_798650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTabValue=PROBLEM
// Recursion
int climbStairs(int n)
{
	if (n <= 1)
		return 1;

	return climbStairs(n - 1) + climbStairs(n - 2);
}

// Memorization
int climbStairsHelper(int n, vector<int> &dp)
{
	if (n <= 1)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	dp[n] = (climbStairsHelper(n - 1, dp) + climbStairsHelper(n - 2, dp)) % 1000000007;
	return dp[n];
}
int climbStairs(int n)
{
	vector<int> dp(n + 1, -1);
	return climbStairsHelper(n, dp);
}

// Tabulation
int climbStairs(int n)
{
	vector<int> dp(n + 1, -1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
	}
	return dp[n];
}

// Space optimization
int climbStairs(int n)
{
	if (n <= 1)
		return 1;

	int prev = 1;
	int prev2 = 1;
	int cur = -1;

	for (int i = 2; i <= n; ++i)
	{
		cur = (prev + prev2) % 1000000007;
		prev2 = prev;
		prev = cur;
	}
	return cur;
}