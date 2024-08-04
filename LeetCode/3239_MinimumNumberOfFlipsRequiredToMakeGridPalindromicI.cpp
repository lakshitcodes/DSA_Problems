#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

class Solution
{
public:
    int flipRows(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid[0].size();
        for (int row = 0; row < grid.size(); row++)
        {
            int i = 0, j = n - 1;
            while (i < j)
            {
                if (grid[row][i] != grid[row][j])
                {
                    ans++;
                }
                i++;
                j--;
            }
        }
        return ans;
    }
    int flipColumn(vector<vector<int>> &grid)
    {
        int ans = 0;
        int n = grid.size();
        for (int col = 0; col < grid[0].size(); col++)
        {
            int i = 0, j = n - 1;
            while (i < j)
            {
                if (grid[i][col] != grid[j][col])
                {
                    ans++;
                }
                i++;
                j--;
            }
        }
        return ans;
    }

    int minFlips(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        return min(flipRows(grid), flipColumn(grid));
    }
};