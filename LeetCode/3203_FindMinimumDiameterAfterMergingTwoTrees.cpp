#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/

class Solution {
public:
    // BFS
    // Farthest Node , distance
    pair<int,int> findFarthestNode(int n,int i,unordered_map<int,vector<int>> &adj){
        vector<bool> visited(n,false);
        int dist=0;
        int node=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int qSize = q.size();
            for(int i=0;i<qSize;i++){
                int front=q.front();
                node=front;
                q.pop();
                visited[front]=true;
                for(auto &i : adj[front]){
                    if(!visited[i]){
                        q.push(i);
                    }
                }
            }
            dist++;
        }
        return {node,dist-1};
    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        // Build Adjacency Lists
        unordered_map<int,vector<int>> adj1,adj2;
        for(auto &i : edges1){
            adj1[i[0]].push_back(i[1]);
            adj1[i[1]].push_back(i[0]);
        }
        for(auto &i : edges2){
            adj2[i[0]].push_back(i[1]);
            adj2[i[1]].push_back(i[0]);
        }

        //The intuition is to find the diameter of both the trees first
        //The maximum depth is diameter by 2 
        // To find the diameter, perform two BFS runs , find the farthest node from any node 
        // And in second run find the farthest node from that node , this will be the diameter
        // Using BFS to find the diameter of the trees

        //Number of nodes in the trees
        int n=edges1.size()+1,m=edges2.size()+1;

        //First Run to find the node farthest from node 0 in tree 1
        auto firstForTree1 = findFarthestNode(n,0,adj1);

        //First Run to find the node farthest from node 0 in tree 2
        auto firstForTree2 = findFarthestNode(m,0,adj2);


        //Second run to find the diameter of tree1
        auto diameter1 = findFarthestNode(n,firstForTree1.first,adj1);

        //Second run to find the diameter of tree1
        auto diameter2 = findFarthestNode(m,firstForTree2.first,adj2);

        // Returning the answer
        return max({diameter1.second,diameter2.second,(diameter1.second+1)/2 + (diameter2.second+1)/2 +1});
    }
};