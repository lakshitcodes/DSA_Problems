#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int solveMem(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp){
        //BASE CASE
        if(index>=n){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        //1 Day Pass
        int option1=cost[0]+solveMem(n,days,cost,index+1,dp);
        //7Day Pass
        int i;
        for(i=index;i<n && days[i]<days[index]+7;i++);
        int option2=cost[1]+solveMem(n,days,cost,i,dp);
        for(i=index;i<n && days[i]<days[index]+30;i++);
        int option3=cost[2]+solveMem(n,days,cost,i,dp);
        dp[index]=min(option1,min(option2,option3));
        return dp[index];
    }
    //Tabulation
    int solveTab(int n,vector<int> days,vector<int> cost){
    vector<int> dp(n+1,INT_MAX);
    dp[n]=0;
    for(int k=n-1;k>=0;k--){
        //1 Day Pass
        int option1=cost[0]+dp[k+1];
        //7Day Pass
        int i;
        for(i=k;i<n && days[i]<days[k]+7;i++);
        int option2=cost[1]+dp[i];
        //30 Day Pass
        for(i=k;i<n && days[i]<days[k]+30;i++);
        int option3=cost[2]+dp[i];
        dp[k]=min(option1,min(option2,option3));
    }
    return dp[0];
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        return solveTab(n,days,costs);
    }
};