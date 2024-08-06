#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution
{
public:
    // Top Down Approach
    int solveMem(int n, vector<int> &arr, int target, int index, vector<vector<int>> &dp)
    {
        if (index >= n)
        {
            return 0;
        }
        if (target == 0)
        {
            return 1;
        }
        if (target < 0)
        {
            return 0;
        }
        if (dp[target][index] != -1)
        {
            return dp[target][index];
        }
        int incl = solveMem(n, arr, target - arr[index], index + 1, dp);
        int excl = solveMem(n, arr, target, index + 1, dp);
        return dp[target][index] = incl or excl;
    }
    // Tabulation
    int solveTab(int n, vector<int> arr, int sum)
    {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= sum; target++)
            {
                int incl = 0;
                if (target - arr[index] >= 0)
                    incl = dp[index + 1][target - arr[index]];
                int excl = dp[index + 1][target];
                dp[index][target] = incl or excl;
            }
        }
        return dp[0][sum];
    }
    // Space Optimisation
    int solveSO(int n, vector<int> arr, int sum)
    {
        vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);
        curr[0] = 1;
        next[0] = 1;
        for (int index = n - 1; index >= 0; index--)
        {
            for (int target = 0; target <= sum; target++)
            {
                int incl = 0;
                if (target - arr[index] >= 0)
                    incl = next[target - arr[index]];
                int excl = next[target];
                curr[target] = incl or excl;
            }
            next = curr;
        }
        return curr[sum];
    }
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 0)
        {
            return solveSO(N, nums, sum / 2);
        }
        else
        {
            return 0;
        }
    }
};