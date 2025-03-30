#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/

class Solution {
    public:
        long long dp[1001];
        
        long long recursion(int start, int n, vector<long long> &prefSum, vector<long long> &suffCosts, int k) {
            if(start == n) return 0;
            
            if(dp[start] != -1) {
                return dp[start];
            }
            
            long long ans = LLONG_MAX;
            for(int end = start; end < n; end++) {
                long long sumTillPos = prefSum[end];
                long long suffCost = suffCosts[start];
                long long subarrayCost = suffCosts[start] - (end + 1 < n ? suffCosts[end + 1] : 0);
                long long cost = prefSum[end] * subarrayCost + k * suffCost;
                
                ans = min(ans, cost + recursion(end + 1, n, prefSum, suffCosts, k));
            }
            
            return dp[start] = ans;
        } 
        
        long long minimumCost(vector<int> &nums, vector<int> &cost, int k) {
            int n = nums.size();
            
            vector<long long> prefSum(n), suffCosts(n);
            
            prefSum[0] = nums[0];
            for(int i = 1; i < n; i++) {
                prefSum[i] = prefSum[i - 1] + nums[i];
            }
            
            suffCosts[n - 1] = cost[n - 1];
            for(int i = n - 2; i >= 0; i--) {
                suffCosts[i] = suffCosts[i + 1] + cost[i];
            }
            
            memset(dp, -1, sizeof(dp));
            return recursion(0, n, prefSum, suffCosts, k);
        }
    };