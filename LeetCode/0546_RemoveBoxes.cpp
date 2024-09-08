#include <bits/stdc++.h>
using namespace std;

// Question Link : https://leetcode.com/problems/remove_boxes

class Solution
{
public:
    // Recursion
    int solve(int l, int r, int k, vector<int> &boxes)
    {
        if (l > r)
        {
            return 0;
        }
        int result = (k + 1) * (k + 1) + solve(l + 1, r, 0, boxes);
        for (int i = l + 1; i <= r; i++)
        {
            if (boxes[i] == boxes[l])
            {
                result = max(result, solve(l + 1, i - 1, 0, boxes) +
                                         solve(i, r, k + 1, boxes));
            }
        }
        return result;
    }
    // Memoisation
    int solveMemo(int l, int r, int k, vector<int> &boxes,
                  vector<vector<vector<int>>> &dp)
    {
        if (l > r)
        {
            return 0;
        }
        if (dp[l][r][k] != -1)
        {
            return dp[l][r][k];
        }
        int result = (k + 1) * (k + 1) + solveMemo(l + 1, r, 0, boxes, dp);
        for (int i = l + 1; i <= r; i++)
        {
            if (boxes[i] == boxes[l])
            {
                result = max(result, solveMemo(i, r, k + 1, boxes, dp) +
                                         solveMemo(l + 1, i - 1, 0, boxes, dp));
            }
        }
        return dp[l][r][k] = result;
    }
    // Tabulation
    int solveTab(vector<int> &boxes)
    {
        int n = boxes.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
        for (int len = 1; len <= n; len++)
        {
            for (int l = 0; l <= n - len; l++)
            {
                int r = l + len - 1;
                for (int k = 0; k <= l; k++)
                {
                    int result = (k + 1) * (k + 1) + dp[l + 1][r][0];
                    for (int i = l + 1; i <= r; i++)
                    {
                        if (boxes[i] == boxes[l])
                        {
                            result = max(result, dp[i][r][k + 1] + dp[l + 1][i - 1][0]);
                        }
                    }
                    dp[l][r][k] = result;
                }
            }
        }
        return dp[0][n - 1][0];
    }
    int removeBoxes(vector<int> &boxes)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n = boxes.size();
        // Recursive Call
        //  return solve(0,n-1,0,boxes);

        // Memoisation Call
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        // return solveMemo(0, n - 1, 0, boxes, dp);

        // Tabulation Call
        return solveTab(boxes);
    }
};