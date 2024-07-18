#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/cherry-pickup/

// Recursive Solution
class Solution
{
public:
    int collect(vector<vector<int>> &grid, int r1, int c1, int r2, int c2)
    {
        if (r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1)
        {
            return grid[r1][c1];
        }
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int a = collect(grid, r1 + 1, c1, r2 + 1, c2);
        int b = collect(grid, r1 + 1, c1, r2, c2 + 1);
        int c = collect(grid, r1, c1 + 1, r2 + 1, c2);
        int d = collect(grid, r1, c1 + 1, r2, c2 + 1);

        cherries += max({a, b, c, d});
        return cherries;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        return max(collect(grid, 0, 0, 0, 0), 0);
    }
};

// Memoised Solution
// 4D vector
class Solution
{
public:
    int collect(vector<vector<int>> &grid, int r1, int c1, int r2, int c2, vector<vector<vector<vector<int>>>> &dp)
    {
        if (r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        if (dp[r1][c1][r2][c2] != -1)
        {
            return dp[r1][c1][r2][c2];
        }
        if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1)
        {
            return grid[r1][c1];
        }
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int a = collect(grid, r1 + 1, c1, r2 + 1, c2, dp);
        int b = collect(grid, r1 + 1, c1, r2, c2 + 1, dp);
        int c = collect(grid, r1, c1 + 1, r2 + 1, c2, dp);
        int d = collect(grid, r1, c1 + 1, r2, c2 + 1, dp);

        cherries += max({a, b, c, d});
        return dp[r1][c1][r2][c2] = cherries;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<vector<vector<vector<int>>>> dp(grid.size(), vector<vector<vector<int>>>(grid[0].size(), vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1))));
        return max(collect(grid, 0, 0, 0, 0, dp), 0);
    }
};

// 3D Vector
class Solution
{
public:
    int collect(vector<vector<int>> &grid, int r1, int c1, int r2, vector<vector<vector<int>>> &dp)
    {
        int c2 = r1 + c1 - r2;
        if (r1 >= grid.size() || r2 >= grid.size() || c1 >= grid[0].size() || c2 >= grid[0].size() || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        if (dp[r1][c1][r2] != -1)
        {
            return dp[r1][c1][r2];
        }
        if (r1 == grid.size() - 1 && c1 == grid[0].size() - 1)
        {
            return grid[r1][c1];
        }
        int cherries = 0;
        if (r1 == r2 && c1 == c2)
        {
            cherries += grid[r1][c1];
        }
        else
        {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        int a = collect(grid, r1 + 1, c1, r2 + 1, dp);
        int b = collect(grid, r1 + 1, c1, r2, dp);
        int c = collect(grid, r1, c1 + 1, r2 + 1, dp);
        int d = collect(grid, r1, c1 + 1, r2, dp);

        cherries += max({a, b, c, d});
        return dp[r1][c1][r2] = cherries;
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid.size(), -1)));
        return max(collect(grid, 0, 0, 0, dp), 0);
    }
};