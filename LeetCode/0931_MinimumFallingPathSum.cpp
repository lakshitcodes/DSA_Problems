#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-falling-path-sum/

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> curr(n, INT_MAX), next(n, 0);
        for (int row = m - 1; row >= 0; row--)
        {
            for (int col = n - 1; col >= 0; col--)
            {
                int right = INT_MAX, left = INT_MAX, down = INT_MAX;
                if (col > 0)
                {
                    left = next[col - 1];
                }
                if (col < n - 1)
                {
                    right = next[col + 1];
                }
                down = next[col];
                curr[col] = grid[row][col] + min({left, right, down});
            }
            next = curr;
            fill(curr.begin(), curr.end(), INT_MAX);
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, next[i]);
        }
        return ans;
    }
};