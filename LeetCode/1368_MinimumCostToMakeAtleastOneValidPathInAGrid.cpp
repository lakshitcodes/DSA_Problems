#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

class Solution {
public:
    inline bool isValid(int x,int y,int m,int n){
        return x>=0 && y>=0 && x<m && y<n;
    }
    int minCost(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=grid.size();
        int n=grid[0].size();

        // Visited Matrix
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq; // cost,x,y
        pq.push({0,0,0});       // Start Element
        while(!pq.empty()){
            vector<int> front = pq.top();
            pq.pop();
            int cost=front[0];
            int x=front[1];
            int y=front[2];
            if(x==m-1 && y==n-1){
                return cost;
            }
            if(visited[x][y]){
                continue;
            }
            visited[x][y]=true;
            cost++;

            if(isValid(x,y+1,m,n) && !visited[x][y+1]){
                if(grid[x][y]==1){
                    pq.push({cost-1,x,y+1});
                }
                else{
                    pq.push({cost,x,y+1});
                }
            }
            if(isValid(x,y-1,m,n) && !visited[x][y-1]){
                if(grid[x][y]==2){
                    pq.push({cost-1,x,y-1});
                }
                else{
                    pq.push({cost,x,y-1});
                }
            }
            if(isValid(x+1,y,m,n) && !visited[x+1][y]){
                if(grid[x][y]==3){
                    pq.push({cost-1,x+1,y});
                }
                else{
                    pq.push({cost,x+1,y});
                }
            }
            if(isValid(x-1,y,m,n) && !visited[x-1][y]){
                if(grid[x][y]==4){
                    pq.push({cost-1,x-1,y});
                }
                else{
                    pq.push({cost,x-1,y});
                }
            }
        }
        return -1;
    }
};