#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution
{
public:
    // Recursive Call
    int solve(int index, int buy, vector<int> &prices)
    {
        if (index == prices.size())
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            profit = max(-prices[index] + solve(index + 1, 0, prices), 0 + solve(index + 1, 1, prices));
        }
        else
        {
            profit = max(prices[index] + solve(index + 1, 1, prices), 0 + solve(index + 1, 0, prices));
        }
        return profit;
    }
    // Recursive + Memoisation
    int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        int profit = 0;
        if (dp[index][buy] != -1)
        {
            return dp[index][buy];
        }
        if (buy)
        {
            profit = max(-prices[index] + solveMem(index + 1, 0, prices, dp), 0 + solveMem(index + 1, 1, prices, dp));
        }
        else
        {
            profit = max(prices[index] + solveMem(index + 1, 1, prices, dp), 0 + solveMem(index + 1, 0, prices, dp));
        }
        return dp[index][buy] = profit;
    }
    // Tabulation
    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + dp[index + 1][0], dp[index + 1][1]);
                }
                else
                {
                    profit = max(prices[index] + dp[index + 1][1], dp[index + 1][0]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    // Space Optimisation
    int solveSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[index] + next[0], next[1]);
                }
                else
                {
                    profit = max(prices[index] + next[1], next[0]);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return curr[1];
    }
    int maxProfit(vector<int> &prices)
    {
        // int n=prices.size();
        // vector<vector<int>> dp(n+1,vector<int> (2,-1));
        // return solveMem(0,1,prices,dp);
        return solveSO(prices);
    }
};