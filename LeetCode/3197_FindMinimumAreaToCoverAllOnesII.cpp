#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/find-minimum-area-to-cover-all-ones-ii/

class Solution
{
public:
    int minimumSum(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int res = INT_MAX;
        for (int rot = 0; rot < 4; rot++)
        {
            int n = grid.size();
            int m = grid[0].size();

            for (int i = 1; i < n; i++)
            {
                int a1 = minimumArea(vector<vector<int>>(grid.begin(), grid.begin() + i));
                for (int j = 1; j < m; j++)
                {
                    vector<vector<int>> part2(n - i, vector<int>(j));
                    vector<vector<int>> part3(n - i, vector<int>(m - j));

                    for (int r = 0; r < n - i; r++)
                    {
                        copy(grid[i + r].begin(), grid[i + r].begin() + j, part2[r].begin());
                        copy(grid[i + r].begin() + j, grid[i + r].end(), part3[r].begin());
                    }
                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, a1 + a2 + a3);
                }
                for (int i2 = i + 1; i2 < n; i2++)
                {
                    vector<vector<int>> part2(grid.begin() + i, grid.begin() + i2);
                    vector<vector<int>> part3(grid.begin() + i2, grid.end());
                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, a1 + a2 + a3);
                }
            }
            grid = rotate(grid);
        }
        return res;
    }
    vector<vector<int>> rotate(const vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rotated(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                rotated[j][n - i - 1] = grid[i][j];
            }
        }
        return rotated;
    }
    int minimumArea(const vector<vector<int>> &grid)
    {
        int firstRow = INT_MAX, firstCol = INT_MAX, lastRow = INT_MIN, lastCol = INT_MIN;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    firstRow = min(firstRow, i);
                    firstCol = min(firstCol, j);
                    lastRow = max(lastRow, i);
                    lastCol = max(lastCol, j);
                }
            }
        }
        if (firstRow == INT_MAX)
        {
            return 0;
        }
        int length = lastRow - firstRow + 1;
        int breadth = lastCol - firstCol + 1;
        return length * breadth;
    }
};