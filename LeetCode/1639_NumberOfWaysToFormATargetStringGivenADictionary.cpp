#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

class Solution {
public:
    #define mod 1000000007
    // Recursion (TLE ofc)
    int solve(int index,int k,vector<string>& words,string target){
        if(index==target.length()){
            return 1;
        }
        if(k==words[0].length()){
            return 0;
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=k;j<words[i].length();j++){
                if(words[i][j]==target[index]){
                    ans+=solve(index+1,j+1,words,target)%mod;
                }
            }
        }
        return ans%mod;
    }
    // Memoisation (TLE at 70/90)
    int solveMemo(int index,int k,vector<string>& words,string target,vector<vector<int>> &dp){
        if(index==target.length()){
            return 1;
        }
        if(k==words[0].length()){
            return 0;
        }
        if(dp[k][index]!=-1){
            return dp[k][index];
        }
        int ans=0;
        for(int i=0;i<words.size();i++){
            for(int j=k;j<words[i].length();j++){
                if(words[i][j]==target[index]){
                    ans=(ans%mod)+(solveMemo(index+1,j+1,words,target,dp)%mod);
                }
            }
        }
        return dp[k][index]=ans%mod;
    }
    // Storing count of each alphabet (TLE at 81/90)
    long long solveOpt(int index,int k,vector<string>& words,string target,vector<vector<int>> &pre,vector<vector<int>> &dp){
        if(index==target.length()){
            return 1;
        }
        if(k==words[0].length()){
            return 0;
        }
        if(dp[k][index]!=-1){
            return dp[k][index];
        }
        int ans=0;
        for(int j=k;j<words[0].length();j++){
            if(pre[j][target[index]-'a'])
                ans=(ans%mod)+((long long)pre[j][target[index]-'a']*solveOpt(index+1,j+1,words,target,pre,dp)%mod);
        }
        return dp[k][index]=ans%mod;
    }
    // Trying take not take instead of looping
    long long solveFinal(int index,int k,vector<string>& words,string& target,vector<vector<int>> &pre,vector<vector<int>> &dp){
        if(index==target.length()){
            return 1;
        }
        if(k==words[0].length()){
            return 0;
        }
        if(dp[k][index]!=-1){
            return dp[k][index];
        }
        int ans=0;
        ans+=solveFinal(index,k+1,words,target,pre,dp)%mod;
        ans=(ans%mod)+((long long)pre[k][target[index]-'a']*solveFinal(index+1,k+1,words,target,pre,dp)%mod);
        return dp[k][index]=ans%mod;
    }
    int numWays(vector<string>& words, string target) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        // Recursive
        // return solve(0,0,words,target)%mod;

        // Memoisation
        // vector<vector<int>> dp(words[0].length()+1,vector<int>(target.length()+1,-1));
        // return solveMemo(0,0,words,target,dp);

        // Storing count of each alphabet in each column
        vector<vector<int>> dp(words[0].length()+1,vector<int>(target.length()+1,-1));
        vector<vector<int>> pre(words[0].length()+1,vector<int>(26,0));

        for(auto word : words){
            for(int i=0;i<word.length();i++){
                pre[i][word[i]-'a']++;
            }
        }

        // return solveOpt(0,0,words,target,pre,dp);

        // Using take not take approach
        return solveFinal(0,0,words,target,pre,dp);
    }
};