#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/ones-and-zeroes

class Solution
{
public:
    int solve(int idx, int m, int n, vector<string> &strs, vector<vector<vector<int>>> &dp)
    {
        if (idx == strs.size())
        {
            return 0;
        }
        if (m <= 0 && n <= 0)
        {
            return 0;
        }
        if (dp[idx][m][n] != -1)
        {
            return dp[idx][m][n];
        }
        int origM = m, origN = n;
        int notPick = solve(idx + 1, m, n, strs, dp);
        for (auto &i : strs[idx])
        {
            if (i == '0')
            {
                m--;
            }
            else
            {
                n--;
            }
        }
        int pick = 0;
        if (m >= 0 && n >= 0)
        {
            pick = 1 + solve(idx + 1, m, n, strs, dp);
        }
        return dp[idx][origM][origN] = max(pick, notPick);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<vector<vector<int>>> dp(601, vector<vector<int>>(101, vector<int>(101, -1)));
        return solve(0, m, n, strs, dp);
    }
};