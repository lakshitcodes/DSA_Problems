#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/coin-change-ii/

class Solution
{
public:
    int solve(int index, int amount, vector<int> &coins,
              vector<vector<int>> &dp)
    {
        if (index == coins.size())
        {
            return amount == 0;
        }
        if (amount < 0)
        {
            return 0;
        }
        if (dp[index][amount] != -1)
        {
            return dp[index][amount];
        }
        if (amount == 0)
        {
            return 1;
        }
        int ans = solve(index, amount - coins[index], coins, dp);
        ans += solve(index + 1, amount, coins, dp);
        return dp[index][amount] = ans;
    }
    int solveBU(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int t = 0; t <= amount; t++)
        {
            dp[0][t] = (t % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int t = 0; t <= amount; t++)
            {
                if (t - coins[ind] >= 0)
                {
                    dp[ind][t] += dp[ind][t - coins[ind]];
                }
                dp[ind][t] += dp[ind - 1][t];
            }
        }
        return dp[n - 1][amount];
    }
    int change(int amount, vector<int> &coins)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        // vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        // return solve(0, amount, coins, dp);
        return solveBU(amount, coins);
    }
};