#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/magic-squares-in-grid/description/

class Solution
{
public:
    bool isMagic(int x, int y, int m, int n, vector<vector<int>> &grid)
    {
        unordered_set<int> store;
        int prevSum = INT_MAX;
        for (int i = -1; i <= 1; i++)
        {
            int sum = 0;
            for (int j = -1; j <= 1; j++)
            {
                int u = x + i;
                int v = y + j;
                if (u >= 0 && u < m && v >= 0 && v < n)
                {
                    if (grid[u][v] >= 1 && grid[u][v] <= 9)
                    {
                        sum += grid[u][v];
                        store.insert(grid[u][v]);
                    }
                }
            }
            if (prevSum != INT_MAX && prevSum != sum)
            {
                return false;
            }
            prevSum = sum;
        }
        for (int i = -1; i <= 1; i++)
        {
            int sum = 0;
            for (int j = -1; j <= 1; j++)
            {
                int u = x + j;
                int v = y + i;
                sum += grid[u][v];
            }
            if (sum != prevSum)
            {
                return false;
            }
        }
        int sum = grid[x][y] + grid[x - 1][y - 1] + grid[x + 1][y + 1];
        int sum2 = grid[x][y] + grid[x - 1][y + 1] + grid[x + 1][y - 1];
        return store.size() == 9 && sum == prevSum && prevSum == sum2;
    }
    int numMagicSquaresInside(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                ans += isMagic(i, j, m, n, grid);
            }
        }
        return ans;
    }
};