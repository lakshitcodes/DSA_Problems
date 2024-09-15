#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/maximum-multiplication-score/

class Solution
{
public:
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = a.size();
        int n = b.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, INT_MIN));

        for (int j = 0; j <= n; j++)
        {
            dp[0][j] = 0;
        }

        for (int k = 1; k <= 4; k++)
        {
            for (int i = k; i <= n; i++)
            {
                dp[k][i] = max(dp[k][i - 1], dp[k - 1][i - 1] + (long long)a[k - 1] * (long long)b[i - 1]);
            }
        }
        return dp[4][n];
    }
};