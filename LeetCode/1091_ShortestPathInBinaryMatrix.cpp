#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

class Solution
{
public:
    inline bool isValid(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        return i < m && i >= 0 && j < n && j >= 0 && grid[i][j] == 0;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size();
        int n = grid.size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1])
        {
            return -1;
        }
        vector<pair<int, int>> directions = {{1, 1}, {1, 0}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {-1, 0}, {0, -1}};
        queue<vector<int>> pq;
        pq.push({0, 0, 1});
        // x y dist
        while (!pq.empty())
        {
            auto frontElement = pq.front();
            int x = frontElement[0];
            int y = frontElement[1];
            int dist = frontElement[2];
            pq.pop();

            if (x == m - 1 && y == n - 1)
            {
                return dist;
            }
            else
            {
                for (auto &[i, j] : directions)
                {
                    int newX = x + i;
                    int newY = y + j;
                    if (isValid(newX, newY, m, n, grid))
                    {
                        grid[newX][newY] = 1;
                        pq.push({newX, newY, dist + 1});
                    }
                }
            }
        }
        return -1;
    }
};