#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/

class Solution {
    public:
        class DSU{
            private:
            int n;
            vector<int> parent,rank;
            public:
            DSU(int tot){
                n=tot;
                rank.assign(n,1);
                parent.resize(n);
                for(int i=0;i<n;i++){
                    parent[i]=i;
                }
            }
            int findParent(int i){
                if(parent[i]==i){
                    return i;
                }
                return parent[i]=findParent(parent[i]);
            }
            void unite(int x,int y){
                int pX=findParent(x);
                int pY=findParent(y);
                if(pX==pY){
                    return;
                }
                if(rank[pX]>rank[pY]){
                    parent[pY]=pX;
                }
                else if(rank[pY]>rank[pX]){
                    parent[pX]=pY;
                }
                else{
                    parent[pX]=pY;
                    rank[pY]++;
                }
            }
            bool isConnected(int x,int y){
                return findParent(x)==findParent(y);
            }
        };
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            DSU ds(n);
            vector<long long> cost(n,(1<<20)-1);
            // Building the components
            for(auto &i : edges){
                int x=i[0];
                int y=i[1];
                int w=i[2];
                ds.unite(x,y);
            }
    
            // In a connected component, the AND of all the values will be the smallest
            for(auto &i : edges){
                int x=i[0];
                int y=i[1];
                int w=i[2];
                if(ds.isConnected(x,y)){
                    cost[ds.findParent(x)]&=w;
                }
            }
            vector<int> ans;
            // Checking for the queries
            for(auto &i : query){
                if(ds.isConnected(i[0],i[1])){
                    ans.push_back(cost[ds.findParent(i[0])]);
                }
                else{
                    ans.push_back(-1);
                }
            }
            return ans;
    
        }
    };