#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/

class Solution
{
public:
    // Recursion
    int solve(int start, int end, int si, int ei, vector<int> &cuts)
    {
        if (si > ei)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int i = si; i <= ei; i++)
        {
            int left = solve(start, cuts[i], si, i - 1, cuts);
            int right = solve(cuts[i], end, i + 1, ei, cuts);
            ans = min(ans, left + right + (end - start));
        }
        return ans;
    }
    // Recursion + Memoisation
    int solveMemo(int si, int ei, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (si > ei)
        {
            return 0;
        }
        if (dp[si][ei] != -1)
        {
            return dp[si][ei];
        }
        int ans = INT_MAX;
        for (int i = si; i <= ei; i++)
        {
            int left = solveMemo(si, i - 1, cuts, dp);
            int right = solveMemo(i + 1, ei, cuts, dp);
            ans = min(ans, left + right + (cuts[ei + 1] - cuts[si - 1]));
        }
        return dp[si][ei] = ans;
    }
    // Tabulation
    int solveTab(vector<int> &cuts, int n)
    {
        int len = cuts.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int si = len - 2; si >= 1; si--)
        {
            for (int ei = 1; ei <= len - 2; ei++)
            {
                if (si > ei)
                {
                    continue;
                }
                int ans = INT_MAX;
                for (int i = si; i <= ei; i++)
                {
                    ans = min(ans, dp[si][i - 1] + dp[i + 1][ei] + (cuts[ei + 1] - cuts[si - 1]));
                }
                dp[si][ei] = ans;
            }
        }
        return dp[1][len - 2];
    }
    int minCost(int n, vector<int> &cuts)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        // return solve(0,n,0,cuts.size()-1,cuts);

        // vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        // return solveMemo(1,cuts.size()-2,cuts,dp);

        return solveTab(cuts, n);
    }
};