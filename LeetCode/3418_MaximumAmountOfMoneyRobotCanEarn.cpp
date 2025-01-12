#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = coins.size();
        int n = coins[0].size();
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
    
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(0, coins[0][0]);
        dp[0][0][2] = max(0, coins[0][0]);
    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (i > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k] + coins[i][j]);
                        if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + max(0, coins[i][j]));
                    }
                    if (j > 0) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k] + coins[i][j]);
                        if (k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + max(0, coins[i][j]));
                    }
                }
            }
        }
        return max({dp[m-1][n-1][0], dp[m-1][n-1][1], dp[m-1][n-1][2]});
    }
};