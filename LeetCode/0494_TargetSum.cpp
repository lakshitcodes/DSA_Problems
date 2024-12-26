#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/target-sum/

class Solution {
public:
    // Recursion
    int solve(int index,int currVal,vector<int> &nums,int target){
        if(index==nums.size()){
            return currVal==target;
        }
        return solve(index+1,currVal+nums[index],nums,target)+solve(index+1,currVal-nums[index],nums,target);
    }
    // Recursion + Memoisation
    int solveMemo(int index,int currVal,vector<int> &nums,int target,vector<unordered_map<int,int>>&dp){
        if(index==nums.size()){
            return currVal==target;
        }
        if(dp[index].count(currVal)){
            return dp[index][currVal];
        }
        return dp[index][currVal]=solveMemo(index+1,currVal+nums[index],nums,target,dp)+solveMemo(index+1,currVal-nums[index],nums,target,dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // return solve(0,0,nums,target);

        vector<unordered_map<int,int>> dp(nums.size());
        return solveMemo(0,0,nums,target,dp);
    }
};