#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<pair<int,int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    queue<pair<int,int>> pq;
                    pq.push({i,j});
                    int curr=0;
                    while(!pq.empty()){
                        int x=pq.front().first,y=pq.front().second;
                        pq.pop();

                        curr+=grid[x][y];
                        grid[x][y]=0;
                        for(auto &[dx,dy] : dir){
                            int X=x+dx;
                            int Y=y+dy;
                            if(X>=0 && Y>=0 && X<m && Y<n && grid[X][Y]!=0){
                                pq.push({X,Y});
                            }
                        }
                    }
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};