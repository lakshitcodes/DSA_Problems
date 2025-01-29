#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    class DSU{
        vector<int> parent;
        vector<int> rank;
        public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);

            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }

        int findParent(int i){
            if(parent[i]==i){
                return i;
            }
            int rr = findParent(parent[i]);
            parent[i]=rr;
            return rr;
        }
        void unite(int v1,int v2){
            int r1=findParent(v1);
            int r2=findParent(v2);

            if(rank[v1]<rank[v2]){
                parent[r1]=r2;
            }
            else if(rank[v2]<rank[v1]){
                parent[r2]=r1;
            }
            else{
                parent[r2]=r1;
                rank[r1]++;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=edges.size();
        DSU ds(n+1);

        for(auto &i : edges){
            int u=i[0];
            int v=i[1];
            int p1 = ds.findParent(u);
            int p2=ds.findParent(v);
            if(p1==p2){
                return i;
            }
            ds.unite(u,v);
        }

        return {-1,-1};
    }
};