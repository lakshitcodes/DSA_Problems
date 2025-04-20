#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-x-value-of-array-i/

class Solution {
    public:
        vector<long long> resultArray(vector<int>& nums, int k) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n = nums.size();
            vector<long long> result(k, 0);
            vector<vector<long long>> dp(n, vector<long long>(k, 0));
    
            dp[0][nums[0] % k] = 1;
            
            for (int i = 1; i < n; i++) {
                dp[i][nums[i] % k]++;
                
                for (int r = 0; r < k; r++) {
                    if (dp[i-1][r] > 0) {
                        int newRem = ((long long)r * (long long)nums[i]) % k;
                        dp[i][newRem] += dp[i-1][r];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                for (int r = 0; r < k; r++) {
                    result[r] += dp[i][r];
                }
            }
            
            return result;
        }
    };