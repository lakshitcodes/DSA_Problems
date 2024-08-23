#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/edit-distance/

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
        {
            dp[i][n] = m - i;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[m][i] = n - i;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (word1[i] == word2[j])
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
                }
            }
        }
        return dp[0][0];
    }
};