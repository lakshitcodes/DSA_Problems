#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/house-robber-ii/

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        vector<long long int> dp(n + 1, LLONG_MAX);
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (long long int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        long long int first = dp[1];
        dp.assign(n, LLONG_MAX);
        nums.pop_back();
        n = nums.size();
        dp[n] = 0;
        dp[n - 1] = nums[n - 1];
        for (long long int i = n - 2; i >= 0; i--)
        {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }
        return max(dp[0], first);
    }
};