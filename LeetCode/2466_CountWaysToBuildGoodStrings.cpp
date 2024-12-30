#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-ways-to-build-good-strings/

class Solution {
public:
    #define mod 1000000007
    // Recursive
    int solve(int length,int low,int high,int zero,int one){
        if(length>high){
            return 0;
        }
        int ans=length>=low && length<=high;
        ans=(ans%mod) + (solve(length+zero,low,high,zero,one)%mod);
        ans=(ans%mod)+(solve(length+one,low,high,zero,one)%mod);
        return ans%mod;
    }
    // Memoisation
    int solveMemo(int length,int low,int high,int zero,int one,unordered_map<int,int> &dp){
        if(length>high){
            return 0;
        }
        if(dp.count(length)){
            return dp[length];
        }
        int ans=length>=low && length<=high;
        ans=(ans%mod) + (solveMemo(length+zero,low,high,zero,one,dp)%mod);
        ans=(ans%mod)+(solveMemo(length+one,low,high,zero,one,dp)%mod);
        return dp[length]=ans%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if(zero==0 && one==0){
            return 0;
        }
        // return solve(0,low,high,zero,one);

        unordered_map<int,int> dp;
        return solveMemo(0,low,high,zero,one,dp);
    }
};