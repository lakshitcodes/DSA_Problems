#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/geeks-training/1

class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i][0] = arr[i][0] + max(dp[i + 1][1], dp[i + 1][2]);
            dp[i][1] = arr[i][1] + max(dp[i + 1][0], dp[i + 1][2]);
            dp[i][2] = arr[i][2] + max(dp[i + 1][1], dp[i + 1][0]);
        }
        return *max_element(dp[0].begin(), dp[0].end());
    }
};