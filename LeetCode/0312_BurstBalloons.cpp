#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/burst-balloons

class Solution
{
public:
    // Recursion
    int solve(int start, int end, vector<int> &nums)
    {
        if (start > end)
        {
            return 0;
        }
        int ans = INT_MIN;
        for (int i = start; i <= end; i++)
        {
            int current = nums[start - 1] * nums[i] * nums[end + 1];
            int left = solve(start, i - 1, nums);
            int right = solve(i + 1, end, nums);
            ans = max(ans, current + left + right);
        }
        return ans;
    }
    // Recursion + Memoisation
    int solveMemo(int start, int end, vector<int> &nums,
                  vector<vector<int>> &dp)
    {
        if (start > end)
        {
            return 0;
        }
        if (dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = INT_MIN;
        for (int i = start; i <= end; i++)
        {
            int current = nums[start - 1] * nums[i] * nums[end + 1];
            int left = solveMemo(start, i - 1, nums, dp);
            int right = solveMemo(i + 1, end, nums, dp);
            ans = max(ans, current + left + right);
        }
        return dp[start][end] = ans;
    }
    // Tabulation
    int solveTab(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int si = n - 2; si >= 1; si--)
        {
            for (int ei = 1; ei <= n - 2; ei++)
            {
                if (si > ei)
                {
                    continue;
                }
                int ans = INT_MIN;
                for (int i = si; i <= ei; i++)
                {
                    int current = nums[si - 1] * nums[i] * nums[ei + 1];
                    int left = dp[si][i - 1];
                    int right = dp[i + 1][ei];
                    ans = max(ans, current + left + right);
                }
                dp[si][ei] = ans;
            }
        }
        return dp[1][n - 2];
    }
    int maxCoins(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Instead of deleting from start like 1,5,3,8
        // We will try to build from the bottom that is what was the last
        // balloon bursted, this way we will be able to make the the things
        // interdependent.

        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        // return solve(1,nums.size()-2,nums);

        // Memoisation
        // vector<vector<int>> dp(nums.size() + 1,vector<int>(nums.size() + 1, -1));
        // return solveMemo(1, nums.size() - 2, nums, dp);

        // Tabulation
        return solveTab(nums);
    }
};