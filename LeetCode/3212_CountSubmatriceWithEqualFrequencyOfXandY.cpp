#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/

class Solution
{
public:
    int numberOfSubmatrices(vector<vector<char>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int, int>>> store(m, vector<pair<int, int>>(n, {0, 0}));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'X')
                {
                    store[i][j].first++;
                }
                if (grid[i][j] == 'Y')
                {
                    store[i][j].second++;
                }

                if (j > 0)
                {
                    store[i][j].first += store[i][j - 1].first;
                    store[i][j].second += store[i][j - 1].second;
                }
                if (i > 0)
                {
                    store[i][j].first += store[i - 1][j].first;
                    store[i][j].second += store[i - 1][j].second;
                }
                if (i > 0 && j > 0)
                {
                    store[i][j].first -= store[i - 1][j - 1].first;
                    store[i][j].second -= store[i - 1][j - 1].second;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x = store[i][j].first, y = store[i][j].second;
                if (x == y && x > 0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};