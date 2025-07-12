#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/the-earliest-and-the-latest-rounds-where-the-player-compete

class Solution
{
public:
    int rMin = INT_MAX;
    int rMax = INT_MIN;
    vector<vector<vector<bool>>> dp;
    void solve(int round, int l, int r, int n)
    {
        if (dp[round][l][r])
        {
            return;
        }
        dp[round][l][r] = 1;
        if (l > r)
            return solve(round, r, l, n);
        if (l == r)
        {
            rMin = min(rMin, round);
            rMax = max(round, rMax);
            return;
        }
        int half = (n + 1) / 2;
        int iN = min(l, half);
        for (int i = 1; i <= iN; i++)
        {
            for (int j = min(half, r) - i; j >= l - i + 1; j--)
            {
                if (l + r - (i + j) <= n / 2)
                {
                    solve(round + 1, i, j, half);
                }
            }
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        dp.resize(7, vector<vector<bool>>(n + 2, vector<bool>(n + 2, false)));

        solve(1, firstPlayer, n + 1 - secondPlayer, n);
        return {rMin, rMax};
    }
};