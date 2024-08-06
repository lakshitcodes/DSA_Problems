#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1

class Solution
{
public:
    bool solve(int index, vector<int> &arr, int sum, vector<vector<int>> &dp)
    {
        if (index == arr.size())
        {
            return sum == 0;
        }
        if (sum == 0)
        {
            return dp[index][sum] = true;
        }
        if (sum < 0)
        {
            return false;
        }
        if (dp[index][sum] != -1)
        {
            return dp[index][sum];
        }
        bool include = solve(index + 1, arr, sum - arr[index], dp);
        bool exclude = solve(index + 1, arr, sum, dp);
        return dp[index][sum] = include || exclude;
    }
    bool isSubsetSum(vector<int> arr, int sum)
    {
        int total = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(0, arr, sum, dp);
    }
};