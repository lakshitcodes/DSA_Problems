#include <bits/stdc++.h>
using namespace std;

// Question Link :  https://leetcode.com/problems/unique-paths/description/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (m == 1)
        {
            return 1;
        }
        if (n == 1)
        {
            return 1;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 2] = 1;
        dp[m - 2][n - 1] = 1;
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};