#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-the-number-of-complete-components/

class Solution {
    public:
        class DSU{
            private:
            vector<int> rank,parent;
            public:
            DSU(int n){
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
            
        };
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_map<int,vector<int>> adj;
            DSU ds(n);
            for(auto &i : edges){
                ds.unite(i[0],i[1]);
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }
            vector<bool> visited(n,false);
            int ans=0;
            for(int i=0;i<n;i++){
                if(!visited[ds.findParent(i)]){
                    int edges=0;
                    int nodes=0;
                    queue<int> q;
                    q.push(i);
                    while(!q.empty()){
                        int front=q.front();
                        q.pop();
                        if(visited[front]){
                            continue;
                        }
                        nodes++;
                        visited[front]=true;
                        cout<<front<<" "<<adj[front].size()<<endl;
                        edges+=adj[front].size();
                        for(auto &e : adj[front]){
                            if(!visited[e]){
                                q.push(e);
                            }
                        }
                    }
                    if(edges==nodes*(nodes-1)){
                        ans++;
                    }
                }
            }
            return ans;
    
    
        }
    };