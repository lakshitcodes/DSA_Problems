#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-sub-islands/description/

class Solution
{
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size();
    }
    bool solve(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> &grid1)
    {
        if (grid2[i][j] == 0 || grid2[i][j] == -1)
        {
            return true;
        }
        if (grid1[i][j] == 0)
            return false;
        grid2[i][j] = -1;
        bool isIsland = true;
        for (auto &[x, y] : directions)
        {
            int nx = i + x;
            int ny = j + y;
            if (isValid(nx, ny, grid2))
            {
                if (!solve(nx, ny, grid2, grid1))
                {
                    isIsland = false;
                }
            }
        }
        return isIsland;
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int ans = 0;
        for (int i = 0; i < grid1.size(); i++)
        {
            for (int j = 0; j < grid1[0].size(); j++)
            {
                if (grid2[i][j] == 1)
                {
                    ans += solve(i, j, grid2, grid1);
                }
            }
        }
        return ans;
    }
};