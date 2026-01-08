#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/max-dot-product-of-two-subsequences/

class Solution
{
public:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i == nums1.size() || j == nums2.size())
        {
            return -1e9;
        }
        if (dp[i][j] != INT_MIN)
        {
            return dp[i][j];
        }
        int take = nums1[i] * nums2[j];
        int ans = max({take + solve(i + 1, j + 1, nums1, nums2, dp),
                       take,
                       solve(i + 1, j, nums1, nums2, dp),
                       solve(i, j + 1, nums1, nums2, dp)});

        return dp[i][j] = ans;
    }
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, INT_MIN));
        return solve(0, 0, nums1, nums2, dp);
    }
};