// https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries
#include <bits/stdc++.h>

// Memorization
int minimumElementsHelper(int index, vector<int> &num, int x,
                          vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (x % num[0] == 0)
            return x / num[0];

        return 1e9;
    }

    if (dp[index][x] != -1)
        return dp[index][x];

    int take = INT_MAX;
    if (num[index] <= x)
        take = 1 + minimumElementsHelper(index, num, x - num[index], dp);

    int notTake = 0 + minimumElementsHelper(index - 1, num, x, dp);

    dp[index][x] = min(take, notTake);
    return dp[index][x];
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, -1));

    int ans = minimumElementsHelper(n - 1, num, x, dp);
    if (ans == 1e9)
        return -1;
    return ans;
}

// Tabulation
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for (int i = 0; i <= x; ++i)
    {
        if (i % num[0] == 0)
            dp[0][i] = i / num[0];
        else
            dp[0][i] = 1e9;
    }

    for (int index = 1; index < n; ++index)
    {
        for (int target = 0; target <= x; ++target)
        {
            int take = INT_MAX;
            if (num[index] <= target)
                take = 1 + dp[index][target - num[index]];

            int notTake = 0 + dp[index - 1][target];

            dp[index][target] = min(take, notTake);
        }
    }
    int ans = dp[n - 1][x];

    if (ans == 1e9)
        return -1;

    return ans;
}

// Space optimization
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev(x + 1, 0);

    for (int i = 0; i <= x; ++i)
    {
        if (i % num[0] == 0)
            prev[i] = i / num[0];
        else
            prev[i] = 1e9;
    }

    for (int index = 1; index < n; ++index)
    {
        vector<int> cur(x + 1, 0);
        for (int target = 0; target <= x; ++target)
        {
            int take = INT_MAX;
            if (num[index] <= target)
                take = 1 + cur[target - num[index]];

            int notTake = 0 + prev[target];

            cur[target] = min(take, notTake);
        }

        prev = cur;
    }
    int ans = prev[x];

    if (ans == 1e9)
        return -1;

    return ans;
}
