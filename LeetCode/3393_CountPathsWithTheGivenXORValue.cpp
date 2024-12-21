#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-paths-with-the-given-xor-value/

class Solution {
public:
#define MOD 1000000007
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<unordered_map<int, int>>> dp(
            m, vector<unordered_map<int, int>>(n));

        dp[0][0][grid[0][0]] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto& [xor_val, count] : dp[i][j]) {
                    if (j + 1 < n) {
                        int new_xor = xor_val ^ grid[i][j + 1];
                        dp[i][j + 1][new_xor] =
                            (dp[i][j + 1][new_xor] + count) % MOD;
                    }
                    if (i + 1 < m) {
                        int new_xor = xor_val ^ grid[i + 1][j];
                        dp[i + 1][j][new_xor] =
                            (dp[i + 1][j][new_xor] + count) % MOD;
                    }
                }
            }
        }
        return dp[m - 1][n - 1][k];
    }
};