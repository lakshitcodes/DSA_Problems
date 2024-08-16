#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/longest-palindromic-subsequence

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        string t = s;
        reverse(t.begin(), t.end());
        int n = t.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};