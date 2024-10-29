#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/

class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(j-1>=0 && grid[j][i]<grid[j-1][i+1]){
                    dp[j][i]=max(dp[j][i],1+dp[j-1][i+1]);
                }
                if(j+1<m && grid[j][i]<grid[j+1][i+1]){
                    dp[j][i]=max(dp[j][i],1+dp[j+1][i+1]);
                }
                if(j>=0 && grid[j][i]<grid[j][i+1]){
                    dp[j][i]=max(dp[j][i],1+dp[j][i+1]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
};