#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/path-with-minimum-effort/

// Binary Search + BFS
// Gives TLE
class Solution
{
public:
    int m, n;
    bool isPossible(vector<vector<int>> &grid, int k)
    {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({0, 0});
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front.first == m - 1 && front.second == n - 1)
            {
                return true;
            }
            visited[front.first][front.second] = true;
            for (auto &[i, j] : directions)
            {
                int x = front.first + i;
                int y = front.second + j;
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && abs(grid[x][y] - grid[front.first][front.second]) <= k)
                {
                    q.push({x, y});
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int r = 0;
        int l = 0;
        m = heights.size();
        n = heights[0].size();
        for (auto i : heights)
        {
            r = max(r, *max_element(i.begin(), i.end()));
        }
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(heights, mid))
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};

// Dijkstra
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
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int m = heights.size();
        int n = heights[0].size();
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            vector<int> front = pq.top();
            pq.pop();
            int x = front[0], y = front[1], dist = front[2];
            if (x == m - 1 && y == n - 1)
            {
                return dist;
            }
            int val = heights[x][y];
            heights[x][y] = INT_MAX;
            for (auto &[i, j] : directions)
            {
                int newX = x + i;
                int newY = y + j;

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && heights[newX][newY] != INT_MAX)
                {
                    pq.push({newX, newY, max(dist, abs(val - heights[newX][newY]))});
                }
            }
        }
        return -1;
    }
};