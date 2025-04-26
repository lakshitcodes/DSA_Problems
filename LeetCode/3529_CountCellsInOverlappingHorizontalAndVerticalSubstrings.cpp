#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/

class Solution
{
    vector<int> LPS(string &pattern)
    {
        int n = pattern.size();
        vector<int> lps(n);
        lps[0] = 0;
        int len = 0, i = 1;
        while (i < n)
        {
            if (pattern[i] == pattern[len])
            {
                lps[i] = len + 1;
                i++;
                len++;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        return lps;
    }

public:
    int countCells(vector<vector<char>> &grid, string pattern)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = grid.size(), m = grid[0].size(), k = pattern.size();
        int N = n * m;
        string row = "", col = "";
        vector<int> lps = LPS(pattern);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                row += grid[i][j];
            }
        }
        for (int j = 0; j < m; ++j)
        {
            for (int i = 0; i < n; ++i)
            {
                col += grid[i][j];
            }
        }
        vector<int> roe(N), coe(N);
        int i = 0, j = 0;
        while (i < N)
        {
            if (row[i] == pattern[j])
            {
                i++;
                j++;
                if (j == k)
                {
                    roe[i - k]++;
                    if (i < N)
                        roe[i]--;
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        i = 0, j = 0;
        while (i < N)
        {
            if (col[i] == pattern[j])
            {
                i++;
                j++;
                if (j == k)
                {
                    coe[i - k]++;
                    if (i < N)
                        coe[i]--;
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
        for (int l = 1; l < N; ++l)
        {
            coe[l] += coe[l - 1];
            roe[l] += roe[l - 1];
        }
        int ans = 0;
        for (int r = 0; r < n; ++r)
        {
            for (int c = 0; c < m; ++c)
            {
                if (roe[r * m + c] && coe[c * n + r])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};