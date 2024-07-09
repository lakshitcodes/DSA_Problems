#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution
{
public:
    const int MOD = 1000000007;
    vector<vector<int>> dp;

    int solve(int *arr, int curr, int index, int n, int sum)
    {
        if (curr > sum)
        {
            return 0;
        }
        if (curr == sum)
        {
            return 1;
        }
        if (index == n)
        {
            return 0;
        }
        if (dp[index][curr] != -1)
        {
            return dp[index][curr];
        }
        int include = solve(arr, curr + arr[index], index + 1, n, sum);
        int exclude = solve(arr, curr, index + 1, n, sum);
        return dp[index][curr] = (include + exclude) % MOD;
    }

    int perfectSum(int arr[], int n, int sum)
    {
        dp = vector<vector<int>>(n + 1, vector<int>(sum + 1, -1));
        return solve(arr, 0, 0, n, sum);
    }
};
