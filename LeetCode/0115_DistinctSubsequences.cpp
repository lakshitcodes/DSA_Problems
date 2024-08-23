#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/distinct-subsequences/description/

class Solution
{
public:
    // Recursion + Memoisation
    int solve(string s, string t, int i, int j, vector<vector<int>> &dp)
    {
        if (j == t.length())
        {
            return 1;
        }
        if (i == s.length())
            return 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int include = 0;
        if (s[i] == t[j])
        {
            include = solve(s, t, i + 1, j + 1, dp);
        }
        int exclude = solve(s, t, i + 1, j, dp);
        return dp[i][j] = include + exclude;
    }
    // Tabulation
    int solveBU(string s, string t)
    {
        int n = s.length();
        int m = t.length();

        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][m] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                dp[i][j] += dp[i + 1][j];
                if (s[i] == t[j])
                {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,-1));
        // return solve(s,t,0,0,dp);
        return solveBU(s, t);
    }
};