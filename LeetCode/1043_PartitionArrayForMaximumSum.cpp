#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/partition-array-for-maximum-sum/description/

class Solution
{
public:
    // Recursion
    int solve(int index, int k, vector<int> &arr)
    {
        if (index >= arr.size())
        {
            return 0;
        }
        int maxElement = INT_MIN;
        int ans = INT_MIN;
        for (int i = index; i < index + k && i < arr.size(); i++)
        {
            maxElement = max(maxElement, arr[i]);
            ans = max(ans, (i - index + 1) * maxElement + solve(i + 1, k, arr));
        }
        return ans;
    }
    // Memoisation
    int solveTD(int index, int k, vector<int> &arr, vector<int> &dp)
    {
        if (index >= arr.size())
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int maxElement = INT_MIN;
        int ans = INT_MIN;
        for (int i = index; i < index + k && i < arr.size(); i++)
        {
            maxElement = max(maxElement, arr[i]);
            ans = max(ans, (i - index + 1) * maxElement +
                               solveTD(i + 1, k, arr, dp));
        }
        return dp[index] = ans;
    }
    // Tabulation
    int solveTab(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            int maxElement = nums[index];
            int ans = INT_MIN;
            for (int i = index; i < index + k && i < n; i++)
            {
                maxElement = max(maxElement, nums[i]);
                ans = max(ans, (i - index + 1) * maxElement + dp[i + 1]);
            }
            dp[index] = ans;
        }
        return dp[0];
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Recursive Call
        // return solve(0,k,arr);

        // Memoisation
        // vector<int> dp(arr.size(),-1);
        // return solveTD(0,k,arr,dp);

        // Tabulation
        return solveTab(arr, k);
    }
};