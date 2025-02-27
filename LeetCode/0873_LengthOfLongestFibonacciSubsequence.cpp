#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_map<int,int> indexes;
            for(int i=0;i<arr.size();i++){
                indexes[arr[i]]=i;
            }
            int n=arr.size();
            vector<vector<int>> dp(n+1,vector<int>(n+1,0));
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int val=arr[j]+arr[i];
                    if(indexes.count(val)){
                        int k=indexes[val];
                        dp[j][k]=1+dp[i][j];
                    }
                }
            }
            int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ans=max(ans,dp[i][j]);
                }
            }
            return ans>0 ? ans+2 : 0;
        }
    };