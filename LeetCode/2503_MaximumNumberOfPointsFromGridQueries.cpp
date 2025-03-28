#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-number--of-points-from-grid-queries/

class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int m=grid.size();
            int n=grid[0].size();
            vector<int> ans(queries.size(),0);
            vector<pair<int,int>> query;
            for(int i=0;i<queries.size();i++){
                query.push_back({queries[i],i});
            }
            sort(query.begin(),query.end());
            vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
            vector<vector<bool>> visited(m,vector<bool>(n,false));
    
            priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
            pq.push({grid[0][0],0,0});
            visited[0][0]=true;
            // value, x,y
            int points=0;
            for(auto &[qVal,qInd] : query){
    
                while(!pq.empty() && pq.top()[0]<qVal){
                    auto front=pq.top();
                    pq.pop();
                    int val=front[0],x=front[1],y=front[2];
                    points++;
                    for(auto &[dx,dy] : dir){
                        int nX=x+dx;
                        int nY=y+dy;
                        if(nX>=0 && nX<m && nY>=0 && nY<n && !visited[nX][nY]){
                            pq.push({grid[nX][nY],nX,nY});
                            visited[nX][nY]=true;
                        }
                    }
                }
                ans[qInd]=points;
            }
            return ans;
        }
    };