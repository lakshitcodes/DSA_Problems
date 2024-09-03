#include <bits/stdc++.h>
using namespace std;

// Question Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

class Solution
{
public:
    // Recursion
    int solveREC(int i, int j, int arr[])
    {
        if (i + 1 == j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int left = solveREC(i, k, arr);
            int right = solveREC(k, j, arr);
            int self = arr[i] * arr[j] * arr[k];
            ans = min(ans, left + right + self);
        }
        return ans;
    }
    // Memoisation
    int solveTD(int i, int j, int arr[], vector<vector<int>> &dp)
    {
        if (i + 1 == j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int left = solveTD(i, k, arr, dp);
            int right = solveTD(k, j, arr, dp);
            int self = arr[i] * arr[j] * arr[k];
            ans = min(ans, left + right + self);
        }
        return dp[i][j] = ans;
    }
    // Tabulation
    int solveBU(int N, int arr[])
    {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
        for (int slide = 2; slide <= N - 1; slide++)
        {
            for (int i = 0; i <= N - slide - 1; i++)
            {
                int j = i + slide;
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, arr[i] * arr[j] * arr[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][N - 1];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // return solveREC(1,N-1,arr);

        // vector<vector<int>> dp(N,vector<int>(N,-1));
        // return solveTD(0,N-1,arr,dp);/

        return solveBU(N, arr);
    }
};