#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/map-of-highest-peak/

class Solution {
public:
    inline bool isValid(int i,int j,int m,int n){
        return i<m && i>=0 && j<n && j>=0;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> coordinates;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    dist[i][j]=0;
                    coordinates.push({i,j});
                }
            }
        }
        vector<pair<int,int>> directions = {{0,1},{0,-1},{-1,0},{1,0}};
        while(!coordinates.empty()){
            auto [x,y] = coordinates.front();
            coordinates.pop();
            for(auto &[i,j] : directions){
                int newX = x+i;
                int newY = y+j;
                if(isValid(newX,newY,m,n)){
                    if(dist[newX][newY]>1+dist[x][y]){
                        dist[newX][newY]=1+dist[x][y];
                        coordinates.push({newX,newY});
                    }
                }
            }
        }
        return dist;
    }
};