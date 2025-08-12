#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int mod = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int num = 1; pow(num, x) <= n; num++)
        {
            int val = (int)round(pow(num, x));
            for (int i = n; i >= val; i--)
            {
                dp[i] = (dp[i] + dp[i - val]) % mod;
            }
        }
        return dp[n];
    }
};
