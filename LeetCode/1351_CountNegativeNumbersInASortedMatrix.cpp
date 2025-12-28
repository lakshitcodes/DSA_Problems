#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size(), n = grid[0].size(), r = m - 1, c = 0, cnt = 0;
        while (r >= 0 && c < n)
        {
            if (grid[r][c] < 0)
            {
                --r;
                cnt += n - c; // there are n - c negative numbers in current row.
            }
            else
            {
                ++c;
            }
        }
        return cnt;
    }
};