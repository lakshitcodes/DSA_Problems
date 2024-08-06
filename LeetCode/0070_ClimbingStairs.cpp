#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/climbing-stairs/

class Solution
{
public:
    int climbStairs(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        dp[n - 1] = 2;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[1];
    }
};