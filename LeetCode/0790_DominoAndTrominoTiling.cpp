#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/domino-and-tromino-tiling/

class Solution
{
public:
    int numTilings(int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int mod = 1e9 + 7;
        vector<int> dp(n + 3, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % mod + (dp[i - 3] % mod);
            dp[i] %= mod;
        }
        return dp[n];
    }
};