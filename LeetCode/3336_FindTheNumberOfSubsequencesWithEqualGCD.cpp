#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/

class Solution {
public:
    #define mod 1000000007
    long long solve(int ind,int gcdA,int gcdB,vector<int> &nums,vector<vector<vector<int>>> &dp){
        if(ind==nums.size()){
            if(gcdA==-1 || gcdB==-1){
                return 0;
            }
            return gcdA==gcdB;
        }
        if(dp[ind][gcdA+1][gcdB+1]!=-1){
            return dp[ind][gcdA+1][gcdB+1];
        }
        int ans=0;
        int curr = nums[ind];

        ans+=solve(ind+1,gcdA,gcdB,nums,dp);
        if(gcdA==-1){
            ans+=solve(ind+1,curr,gcdB,nums,dp);
            ans%=mod;
        }
        else{
            int gcd = __gcd(gcdA,curr);
            ans+=solve(ind+1,gcd,gcdB,nums,dp);
            ans%=mod;
        }

        if(gcdB==-1){
            ans+=solve(ind+1,gcdA,curr,nums,dp);
            ans%=mod;
        }
        else{
            int gcd = __gcd(gcdB,curr);
            ans+=solve(ind+1,gcdA,gcd,nums,dp);
            ans%=mod;
        }

        return dp[ind][gcdA+1][gcdB+1] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>>(202,vector<int>(202,-1)));
        long long ans= solve(0,-1,-1,nums,dp);
        ans%=mod;
        return ans;
    }
};