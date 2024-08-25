#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

class Solution
{
public:
    // Recursive Call
    int solve(int index, int buy, int limit, vector<int> &prices)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (limit == 0)
        {
            return 0;
        }
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[index] + solve(index + 1, 0, limit, prices);
            int skipkaro = 0 + solve(index + 1, 1, limit, prices);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[index] + solve(index + 1, 1, limit - 1, prices);
            int skipkaro = solve(index + 1, 0, limit, prices);
            profit = max(sellkaro, skipkaro);
        }
        return profit;
    }
    // Recursion + Memoisation
    int solveMem(int index, int buy, int limit, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
        {
            return 0;
        }
        if (limit == 0)
        {
            return 0;
        }
        if (dp[index][buy][limit] != -1)
        {
            return dp[index][buy][limit];
        }
        int profit = 0;
        if (buy)
        {
            int buykaro = -prices[index] + solveMem(index + 1, 0, limit, prices, dp);
            int skipkaro = 0 + solveMem(index + 1, 1, limit, prices, dp);
            profit = max(buykaro, skipkaro);
        }
        else
        {
            int sellkaro = prices[index] + solveMem(index + 1, 1, limit - 1, prices, dp);
            int skipkaro = solveMem(index + 1, 0, limit, prices, dp);
            profit = max(sellkaro, skipkaro);
        }
        return dp[index][buy][limit] = profit;
    }
    // Tabulation
    int solveTab(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[index] + dp[index + 1][0][limit], dp[index + 1][1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + dp[index + 1][1][limit - 1], dp[index + 1][0][limit]);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
    // Space Optimisation
    int solveSO(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                    {
                        profit = max(-prices[index] + next[0][limit], next[1][limit]);
                    }
                    else
                    {
                        profit = max(prices[index] + next[1][limit - 1], next[0][limit]);
                    }
                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return curr[1][k];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return solveTab(prices, k);
    }
};