#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/most-profitable-path-in-a-tree/

class Solution {
    public:
        vector<int> bobPath;
        inline bool isLeaf(int idx,unordered_map<int,vector<int>> &adj){
            return adj[idx].size()==1;
        }
        bool dfs(int node,vector<bool> &visited,unordered_map<int,vector<int>> &adj){
            if(visited[node]){
                return false;
            }
            visited[node]=true;
            bobPath.push_back(node);
            if(node==0){
                return true;
            }
            for(auto &i : adj[node]){
                if(!visited[i]){
                    if(dfs(i,visited,adj)){
                        return true;
                    }
                }
            }
            bobPath.pop_back();
            return false;
        }
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=amount.size();
    
            // Building Adjacency List
            unordered_map<int,vector<int>> adj;
            for(auto &i : edges){
                int u=i[0],v=i[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            // Finding the path from bob to 0
            vector<bool> visited(n,false);
            dfs(bob,visited,adj);
            
            // Marking the nodes which are used at which step in bob Path
            vector<int> markBob(n,-1);
            for(int i=0;i<bobPath.size();i++){
                markBob[bobPath[i]]=i;
            }
    
            // Running BFS and calculating max distance
            int ans=INT_MIN;
            queue<vector<int>> pq;    // current node, current score, curr steps
            visited.assign(n,false);
            pq.push({0,amount[0],0});
            while(!pq.empty()){
                vector<int> front=pq.front();
                pq.pop();
                int node=front[0],score=front[1],steps=front[2];
                if(isLeaf(node,adj) && node!=0){
                    ans=max(ans,score);
                    continue;
                }
                visited[node]=true;
                for(auto &i : adj[node]){
                    if(!visited[i]){
                        if(markBob[i]==-1 || markBob[i]>steps+1){
                            pq.push({i,score+amount[i],steps+1});
                        }else if(markBob[i]==steps+1){
                            pq.push({i,score + (amount[i]/2),steps+1});
                        }
                        else{
                            pq.push({i,score,steps+1});
                        }
                    }
                }
            }
    
            return ans;
        }
    };