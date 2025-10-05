#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/pacific-atlantic-water-flow/

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = heights.size();
        int n = heights[0].size();
        vector<vector<pair<int, int>>> flow(m,
                                            vector<pair<int, int>>(n, {0, 0}));

        queue<pair<int, int>> pac, atl;
        for (int i = 0; i < n; i++)
        {
            flow[0][i].first++;
            pac.push({0, i});
            flow[m - 1][i].second++;
            atl.push({m - 1, i});
        }
        for (int i = 0; i < m; i++)
        {
            flow[i][0].first++;
            pac.push({i, 0});
            flow[i][n - 1].second++;
            atl.push({i, n - 1});
        }

        vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

        while (!pac.empty())
        {
            auto front = pac.front();
            pac.pop();
            int x = front.first;
            int y = front.second;

            for (auto &[dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    heights[nx][ny] >= heights[x][y] &&
                    flow[nx][ny].first == 0)
                {
                    flow[nx][ny].first++;
                    pac.push({nx, ny});
                }
            }
        }

        while (!atl.empty())
        {
            auto front = atl.front();
            atl.pop();
            int x = front.first;
            int y = front.second;

            for (auto &[dx, dy] : dir)
            {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    heights[nx][ny] >= heights[x][y] &&
                    flow[nx][ny].second == 0)
                {
                    flow[nx][ny].second++;
                    atl.push({nx, ny});
                }
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (flow[i][j].first && flow[i][j].second)
                {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};