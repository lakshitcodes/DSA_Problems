#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        const int mod = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] %= k;
            }
        }

        dp[m - 1][n - 1][grid[m - 1][n - 1] % k] = 1;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                for (int l = 0; l < k; l++)
                {
                    if (i + 1 < m)
                    {
                        dp[i][j][(grid[i][j] + l) % k] += dp[i + 1][j][l];
                    }
                    dp[i][j][(grid[i][j] + l) % k] %= mod;
                    if (j + 1 < n)
                    {
                        dp[i][j][(grid[i][j] + l) % k] += dp[i][j + 1][l];
                    }
                    dp[i][j][(grid[i][j] + l) % k] %= mod;
                }
            }
        }
        return dp[0][0][0];
    }
};