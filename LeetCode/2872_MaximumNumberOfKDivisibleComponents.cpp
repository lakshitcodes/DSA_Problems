#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-number-of-k-divisible-components/

class Solution {
public:
    int ans=0;
    vector<vector<int>> adj;
    vector<bool> visited;
    long long dfs(int node,vector<int> &values,int k){
        visited[node]=true;
        long long sum=values[node];
        for(auto &i : adj[node]){
            if(visited[i]){
                continue;
            }
            sum+=dfs(i,values,k);
            sum%=k;
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        adj.resize(n);
        visited.resize(n,false);

        for(auto &e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0,values,k);
        return ans;
    }
};