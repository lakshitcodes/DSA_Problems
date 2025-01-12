#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/

class Solution {
public:
    void dfs(vector<pair<int,int>>* adj,vector<int> & vis,int i,int mx){
        if(vis[i]) return;
        vis[i]=1;
        for(auto it:adj[i]){
            if(it.second>mx) continue;
            if(!vis[it.first]) dfs(adj,vis,it.first,mx);
        }
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(auto it:edges){
            mn=min(mn,it[2]);
            mx=max(mx,it[2]);
        }
        vector<pair<int,int>>* adj=new vector<pair<int,int>> [n];
        for(auto it:edges){
            adj[it[1]].push_back({it[0],it[2]});
        }
        int i=mn;
        int e=mx;
        int ans=INT_MAX;
        while(i<=e){
            int m=(i+e)/2;
            bool ok=true;
            vector<int> vis(n,0);
            dfs(adj,vis,0,m);
            for(int i=1;i<n;i++){
                if(!vis[i]){
                    ok=false;
                    break;
                }
            }
            if(!ok) i=m+1;
            else{
                e=m-1;
                ans=min(ans,m);
            } 
        }
        return ans==INT_MAX?-1:ans;
    }
};