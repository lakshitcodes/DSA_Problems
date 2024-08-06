#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/unique-paths-ii/description/

class Solution
{
public:
#define ll long long
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        if (grid[m - 1][n - 1] == 1)
        {
            return 0;
        }
        if (m == 1)
        {
            int sum = accumulate(grid[0].begin(), grid[0].end(), 0);
            return sum == 0;
        }
        if (n == 1)
        {
            int sum = 0;
            for (int i = 0; i < m; i++)
            {
                sum += grid[i][0];
            }
            return sum == 0;
        }
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
        if (grid[m - 1][n - 2] == 0)
        {
            dp[m - 1][n - 2] = 1;
        }
        if (grid[m - 2][n - 1] == 0)
        {
            dp[m - 2][n - 1] = 1;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 0)
                {
                    dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};