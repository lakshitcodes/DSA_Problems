#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution
{
public:
    int solve(int index, int n, int weight, int *val, int *wt)
    {
        if (index == n)
        {
            return 0;
        }
        if (weight < 0)
        {
            return -1e5;
        }
        int include = val[index] + solve(index, n, weight - wt[index], val, wt);
        int exclude = solve(index + 1, n, weight, val, wt);
        return max(include, exclude);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // return solve(0,N,W,val,wt);
        vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
        for (int i = N - 1; i >= 0; i--)
        {
            for (int t = 0; t <= W; t++)
            {
                if (t - wt[i] >= 0)
                {
                    dp[i][t] = max(dp[i][t], val[i] + dp[i][t - wt[i]]);
                }
                dp[i][t] = max(dp[i][t], dp[i + 1][t]);
            }
        }
        return dp[0][W];
    }
};