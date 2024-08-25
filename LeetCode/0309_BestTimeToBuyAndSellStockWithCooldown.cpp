#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

class Solution
{
public:
    // Recursion + Memoisation
    int solve(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index >= prices.size())
        {
            return 0;
        }
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        if (buy)
        {
            int buyKaro = -prices[index] + solve(index + 1, 0, prices, dp);
            int skipKaro = solve(index + 1, 1, prices, dp);
            return dp[index][buy] = max(buyKaro, skipKaro);
        }
        else
        {
            int sellKaro = prices[index] + solve(index + 2, 1, prices, dp);
            int skipKaro = solve(index + 1, 0, prices, dp);
            return dp[index][buy] = max(sellKaro, skipKaro);
        }
    }

    // Tabulation
    int solveBU(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                }
                else
                {
                    dp[i][buy] = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int> &prices)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        // return solve(0,1,prices,dp);
        return solveBU(prices);
    }
};