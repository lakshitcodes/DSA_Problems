#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/chocolates-pickup/1

class Solution
{
    int N, M;

public:
    int pickup(int row, int col1, int col2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (row < 0 || col1 < 0 || col2 < 0 || row >= N || col1 >= M || col2 >= M)
        {
            return -1e8;
        }
        if (row == N - 1)
        {
            if (col1 == col2)
            {
                return grid[row][col1];
            }
            else
            {
                return grid[row][col1] + grid[row][col2];
            }
        }
        if (dp[row][col1][col2] != -1)
        {
            return dp[row][col1][col2];
        }
        int maxi = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                maxi = max(maxi, pickup(row + 1, col1 + i, col2 + j, grid, dp));
            }
        }
        if (col1 == col2)
        {
            maxi += grid[row][col1];
        }
        else
        {
            maxi += grid[row][col1] + grid[row][col2];
        }
        return dp[row][col1][col2] = maxi;
    }
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        N = n;
        M = m;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return pickup(0, 0, m - 1, grid, dp);
    }
};