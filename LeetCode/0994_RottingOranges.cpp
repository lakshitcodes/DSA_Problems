#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/rotting-oranges

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int freshOranges = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    freshOranges++;
                }
                else if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int time = 0;
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        while (freshOranges && !q.empty())
        {
            int qSize = q.size();
            for (int j = 0; j < qSize; j++)
            {
                auto coordinates = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int newX = coordinates.first + dx[i];
                    int newY = coordinates.second + dy[i];
                    if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                        newY < grid[0].size() && grid[newX][newY] == 1)
                    {
                        freshOranges--;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
            time++;
        }
        return freshOranges == 0 ? time : -1;
    }
};