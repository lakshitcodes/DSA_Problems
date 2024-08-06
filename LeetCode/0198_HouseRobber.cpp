#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/house-robber/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return dp[0];
    }
};