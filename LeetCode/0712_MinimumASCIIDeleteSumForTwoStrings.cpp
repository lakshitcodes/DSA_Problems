#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution
{
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == s1.size() && j == s2.size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (i == s1.size())
        {
            int ans = 0;
            for (; j < s2.size(); j++)
            {
                ans += s2[j];
            }
            return dp[i][j] = ans;
        }

        if (j == s2.size())
        {
            int ans = 0;
            for (; i < s1.size(); i++)
            {
                ans += s1[i];
            }
            return dp[i][j] = ans;
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, s1, s2, dp);
        }
        return dp[i][j] = min(s1[i] + solve(i + 1, j, s1, s2, dp), s2[j] + solve(i, j + 1, s1, s2, dp));
    }

    int minimumDeleteSum(string s1, string s2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));
        return solve(0, 0, s1, s2, dp);
    }
};