#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/trapping-rain-water-ii/

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heights) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=heights.size();
        int n=heights[0].size();

        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        // height,row,col
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;

        // Adding boundary cells
        for(int i = 0; i < n; i++) {
            pq.push({heights[0][i], 0, i}),
            pq.push({heights[m-1][i], m-1, i});
            visited[0][i] = true, visited[m-1][i] = true;
        }

        for(int i = 0; i < m; i++) {
            pq.push({heights[i][0], i, 0}),
            pq.push({heights[i][n-1], i, n-1});
            visited[i][0] = true, visited[i][n-1] = true;
        }
        int ans=0;
        while(!pq.empty()){
            vector<int> temp=pq.top();
            pq.pop();
            int height=temp[0];
            int row=temp[1];
            int col=temp[2];
            for(auto dir : directions){
                int r=row+dir[0];
                int c=col+dir[1];
                if(r>=0 && r<m && c>=0 && c<n && !visited[r][c]){
                    visited[r][c]=true;
                    if(heights[r][c]<height){
                        ans+=height-heights[r][c];
                    }
                    pq.push({max(height,heights[r][c]),r,c});
                }
            }
        }
        return ans;
    }
};