#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-a-safe-walk-through-a-grid/description/

class Solution
{
public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<vector<int>> pq;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        pq.push({health - grid[0][0], 0, 0});
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;
        while (!pq.empty())
        {
            vector<int> currElement = pq.top();
            pq.pop();
            int currHealth = currElement[0];
            int currX = currElement[1];
            int currY = currElement[2];
            if (currX == m - 1 && currY == n - 1)
            {
                return true;
            }
            for (auto &[i, j] : directions)
            {
                int x = currX + i;
                int y = currY + j;
                if (x >= 0 && y >= 0 && x < m && y < n && !visited[x][y])
                {
                    if (currHealth - grid[x][y] > 0)
                    {
                        visited[x][y] = true;
                        pq.push({currHealth - grid[x][y], x, y});
                    }
                }
            }
        }
        return false;
    }
};