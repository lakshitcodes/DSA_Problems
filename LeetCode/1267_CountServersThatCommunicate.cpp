#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-servers-that-communicate/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int totalServers = 0;
        int m=grid.size();
        int n=grid[0].size();
        vector<int> rows(m,0);
        vector<int> cols(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                rows[i]+=grid[i][j];
                cols[j]+=grid[i][j];
                totalServers+=grid[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rows[i]==1 && cols[j]==1 && grid[i][j]){
                    totalServers--;
                }
            }
        }
        return totalServers;
    }
};