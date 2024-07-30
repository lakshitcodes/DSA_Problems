#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/number-of-enclaves/description/

// Using BFS
class Solution
{
public:
    inline bool isValid(int i, int j, int m, int n)
    {
        return i < m && i >= 0 && j < n && j >= 0;
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                q.push({i, 0});
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[i][n - 1] == 1)
            {
                q.push({i, n - 1});
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
            {
                q.push({0, i});
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (grid[m - 1][i] == 1)
            {
                q.push({m - 1, i});
            }
        }
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            grid[x][y] = 0;
            for (auto &[i, j] : directions)
            {
                int newX = x + i;
                int newY = y + j;
                if (isValid(newX, newY, m, n))
                {
                    if (grid[newX][newY] == 1)
                    {
                        q.push({newX, newY});
                        grid[newX][newY] = 0;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += grid[i][j];
            }
        }
        return ans;
    }
};

// Using DFS
class Solution
{
public:
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        dfs(grid, i - 1, j, n, m);
        dfs(grid, i, j - 1, n, m);
        dfs(grid, i + 1, j, n, m);
        dfs(grid, i, j + 1, n, m);
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(grid, i, 0, n, m);
            if (grid[i][m - 1] == 1)
                dfs(grid, i, m - 1, n, m);
        }
        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 1)
                dfs(grid, 0, i, n, m);
            if (grid[n - 1][i] == 1)
                dfs(grid, n - 1, i, n, m);
        }
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (grid[i][j] == 1)
                    ans++;
            }
        }
        return ans;
    }
};