#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution
{
public:
    int peopleAwareOfSecret(int n, int delay, int forget)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        const int mod = 1e9 + 7;
        long long curr = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i - delay >= 0)
            {
                curr = (curr + dp[i - delay] + mod) % mod;
            }
            if (i - forget >= 0)
            {
                curr = (curr - dp[i - forget] + mod) % mod;
            }
            dp[i] = curr;
        }
        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++)
        {
            ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};