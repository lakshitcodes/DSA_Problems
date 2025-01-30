#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/

class Solution {
public:
    unordered_set<int> performBFS(int node,vector<bool> &visited,unordered_map<int,vector<int>> &adj){
        queue<int> q;
        q.push(node);
        unordered_set<int> ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            if(visited[front]){
                continue;
            }
            visited[front]=true;
            ans.insert(front);
            for(auto &i : adj[front]){
                if(!visited[i]){
                    q.push(i);
                }
            }
        }
        return ans;
    }
    int maxDepth(unordered_set<int> &elements,int n,unordered_map<int,vector<int>> &adj){
        int ans=0;
        for(auto &ele : elements){
            vector<bool> visited(n,false);
            int currDepth=0;
            queue<int> q;
            q.push(ele);
            while(!q.empty()){
                int size=q.size();
                currDepth++;
                for(int i=0;i<size;i++){
                    int front=q.front();
                    q.pop();
                    if(visited[front])  continue;
                    visited[front]=true;
                    for(auto &t : adj[front]){
                        if(!visited[t]){
                            q.push(t);
                        }
                    }
                }
            }
            ans=max(ans,currDepth);
        }
        return ans;
    }
    bool isBipartite(int n,unordered_map<int,vector<int>> &adj){
        vector<int> color(n,-1);
        for(int start=0;start<n;start++){
            if(color[start]==-1){
                color[start]=0;
                queue<int> q;
                q.push(start);
                while(!q.empty()){
                    int ele=q.front();
                    q.pop();
                    int newColor=1-color[ele];
                    for(auto &i : adj[ele]){
                        if(color[i]==-1){
                            color[i]=newColor;
                            q.push(i);
                        }
                        else if(color[i]==1-newColor){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        unordered_map<int,vector<int>> adj;
        for(auto &i : edges){
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }

        // If the graph is not bipartite, it is not possible to segregate it 
        if(!isBipartite(n,adj)){
            return -1;
        }


        // Iterating over all the nodes and finding the highest depth in each connected component
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                unordered_set<int> elements=performBFS(i,visited,adj);
                ans+=maxDepth(elements,n,adj);
            }
        }
        return ans;
    }
};