#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution
{
public:
    // Recursion
    int solve(int index, int prev, vector<int> &nums)
    {
        if (index == nums.size())
        {
            return 0;
        }
        int include = 0;
        if (nums[index] > prev)
        {
            include = 1 + solve(index + 1, nums[index], nums);
        }
        int exclude = solve(index + 1, prev, nums);
        return max(include, exclude);
    }

    // Top Down (Memoisation)
    int solveTD(int index, int prev, vector<int> &nums,
                vector<vector<int>> &dp)
    {
        if (index == nums.size())
        {
            return 0;
        }
        if (dp[index][prev + 1] != -1)
        {
            return dp[index][prev + 1];
        }
        int include = 0;
        if (prev == -1 || nums[index] > nums[prev])
        {
            include = 1 + solveTD(index + 1, index, nums, dp);
        }
        int exclude = solveTD(index + 1, prev, nums, dp);
        return dp[index][prev + 1] = max(include, exclude);
    }
    // Tabulation
    int solveTB(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int prev = ind - 1; prev >= -1; prev--)
            {
                if (prev == -1 || arr[ind] > arr[prev])
                {
                    dp[ind][prev + 1] =
                        max(dp[ind][prev + 1], 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev + 1] =
                    max(dp[ind][prev + 1], dp[ind + 1][prev + 1]);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // return solve(0,INT_MIN,nums);

        // vector<vector<int>>
        // dp(nums.size()+1,vector<int>(nums.size()+1,-1)); return
        // solveTD(0,-1,nums,dp);

        return solveTB(nums);
    }
};