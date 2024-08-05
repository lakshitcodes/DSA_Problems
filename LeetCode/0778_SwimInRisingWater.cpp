#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/swim-in-rising-water/description/

class Solution
{
public:
    class comparator
    {
    public:
        bool operator()(const vector<int> &a, const vector<int> &b)
        {
            return a[2] > b[2];
        }
    };
    int swimInWater(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        pq.push({0, 0, grid[0][0]});
        int n = grid.size();
        while (!pq.empty())
        {
            auto front = pq.top();
            pq.pop();
            int x = front[0], y = front[1], dist = front[2];
            if (x == n - 1 && y == n - 1)
            {
                return dist;
            }
            int val = grid[x][y];
            grid[x][y] = INT_MAX;
            for (auto &[i, j] : directions)
            {
                int u = i + x;
                int v = y + j;
                if (u >= 0 && v >= 0 && u < n && v < n &&
                    grid[u][v] != INT_MAX)
                {
                    pq.push({u, v, max(dist, grid[u][v])});
                }
            }
        }
        return -1;
    }
};