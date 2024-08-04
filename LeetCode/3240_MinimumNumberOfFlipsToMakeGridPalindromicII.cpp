#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-ii/description/

class Solution
{
public:
    int minFlips(vector<vector<int>> &grid)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = grid.size();
        int m = grid[0].size();
        int totalones = 0;
        int ans = 0;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < m / 2; j++)
            {
                int ones = 0;
                if (grid[i][j] == 1)
                    ones++;
                if (grid[i][m - j - 1] == 1)
                    ones++;
                if (grid[n - i - 1][j] == 1)
                    ones++;
                if (grid[n - i - 1][m - j - 1] == 1)
                    ones++;
                if (ones == 4 || ones == 0)
                {
                    totalones += ones;
                    continue;
                }
                else if (ones >= 2)
                {
                    ans += (4 - ones);
                    totalones += 4;
                }
                else
                {
                    ans += ones;
                }
            }
        }
        if (n % 2 == 0 && m % 2 == 0)
            return ans;
        int palinOnes = 0;
        int onechange = 0;
        if (m % 2 == 1)
        {
            for (int i = 0; i < n / 2; i++)
            {
                if (grid[i][m / 2] == 1 && grid[n - i - 1][m / 2] == 1)
                    palinOnes++;
                if (grid[i][m / 2] != grid[n - i - 1][m / 2])
                {
                    ans++;
                    onechange++;
                }
            }
        }
        if (n % 2 == 1)
        {
            for (int i = 0; i < m / 2; i++)
            {
                if (grid[n / 2][i] == 1 && grid[n / 2][m - i - 1] == 1)
                    palinOnes++;
                if (grid[n / 2][i] != grid[n / 2][m - i - 1])
                {
                    ans++;
                    onechange++;
                }
            }
        }
        if (palinOnes % 2 == 1)
        {
            if (onechange == 0)
                ans += 2;
        }
        if (n % 2 == 1 && m % 2 == 1 && grid[n / 2][m / 2] == 1)
            ans++;
        return ans;
    }
};