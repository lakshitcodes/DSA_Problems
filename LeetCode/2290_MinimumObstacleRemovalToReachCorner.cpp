#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        visited[0][0]=true;
        pq.push({0,0,0});
        vector<int> dir={-1,0,1,0,-1};
        while(!pq.empty()){
            vector<int> front=pq.top();
            pq.pop();
            int cost=front[0];
            int x=front[1];
            int y=front[2];
            if(x==m-1 && y==n-1){
                return cost;
            }
            for(int i=0;i<4;i++){
                int dx=x+dir[i];
                int dy=y+dir[i+1];
                if(dx>=0 && dy>=0 && dx<m && dy<n && visited[dx][dy]==false){
                    visited[dx][dy]=true;
                    pq.push({cost+grid[dx][dy],dx,dy});
                }
            }
        }
        return -1;
    }
};