#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int ans(string &s , int l,int r,vector<vector<int>> &dp){
        if(l>=r){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        if(s[l]==s[r]){
            return dp[l][r]=ans(s,l+1,r-1,dp);
        }
        else{
            return dp[l][r]=1+min(ans(s,l+1,r,dp),ans(s,l,r-1,dp));
        }
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        return ans(s,0,s.length()-1,dp);
    }
};