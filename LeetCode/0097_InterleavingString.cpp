#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/interleaving-string/

class Solution {
    public:
        bool solve(string s1,string s2,string s3,int i,int j,vector<vector<int>> &dp){
            if(i==s1.length() && j==s2.length() && i+j==s3.length()) return true;
            if(i+j>s3.length()){
                return false;
            }
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            bool a=false;
            if(s1[i]==s3[i+j]){
                a=solve(s1,s2,s3,i+1,j,dp);
            }
            bool b=false;
            if(s2[j]==s3[i+j]){
                b=solve(s1,s2,s3,i,j+1,dp);
            }
            return dp[i][j]=a||b;
        }
        bool isInterleave(string s1, string s2, string s3) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1,-1));
            return solve(s1,s2,s3,0,0,dp);
        }
    };