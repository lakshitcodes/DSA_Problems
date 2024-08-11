#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/

class Solution
{
public:
    int timer = 1;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int articulationPoints = 0;

    void dfs(pair<int, int> node, pair<int, int> parent,
             vector<vector<int>> &grid, vector<vector<bool>> &visited,
             vector<vector<int>> &low, vector<vector<int>> &discovery)
    {
        visited[node.first][node.second] = true;
        int children = 0;
        low[node.first][node.second] = discovery[node.first][node.second] =
            timer++;

        for (auto &[x, y] : directions)
        {
            int u = x + node.first;
            int v = y + node.second;

            if (u >= 0 && u < grid.size() && v >= 0 && v < grid[0].size() &&
                grid[u][v] == 1)
            {
                if (!visited[u][v])
                {
                    children++;
                    dfs({u, v}, node, grid, visited, low, discovery);
                    low[node.first][node.second] =
                        min(low[node.first][node.second], low[u][v]);
                    if (parent != node &&
                        low[u][v] >= discovery[node.first][node.second])
                    {
                        articulationPoints++;
                    }
                }
                else if (make_pair(u, v) != parent)
                {
                    low[node.first][node.second] =
                        min(low[node.first][node.second], discovery[u][v]);
                }
            }
        }
        if (parent == node && children > 1)
        {
            articulationPoints++;
        }
    }

    int minDays(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> low(m, vector<int>(n, -1));
        vector<vector<int>> discovery(m, vector<int>(n, -1));

        int components = 0;
        int totalOnes = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                totalOnes += grid[i][j];
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    dfs({i, j}, {i, j}, grid, visited, low, discovery);
                    components++;
                }
            }
        }
        if (totalOnes == 1)
        {
            return 1;
        }
        if (components != 1)
        {
            return 0;
        }
        return articulationPoints > 0 ? 1 : 2;
    }
};
