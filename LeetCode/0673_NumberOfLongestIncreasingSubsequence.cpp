#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-longest-increasing-subsequence/

class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = nums.size();
        int maxLen = 1;
        vector<int> dp(n, 1), count(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (nums[i] > nums[j] && dp[j] + 1 == dp[i])
                {
                    count[i] += count[j];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxLen)
            {
                ans += count[i];
            }
        }
        return ans;
    }
};