#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/minimal-cost/1

class Solution
{
public:
    int minimizeCost(vector<int> &arr, int &k)
    {
        if (arr.size() <= 1)
        {
            return 0;
        }
        int n = arr.size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;
        dp[n - 2] = abs(arr[n - 1] - arr[n - 2]);
        for (int i = n - 3; i >= 0; i--)
        {
            for (int j = 1; j <= k; j++)
            {
                if (i + j < n)
                {
                    dp[i] = min(dp[i + j] + abs(arr[i] - arr[i + j]), dp[i]);
                }
            }
        }
        return dp[0];
    }
};