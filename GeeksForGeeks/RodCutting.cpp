#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/rod-cutting0840/1

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        return dp[n];
    }
};