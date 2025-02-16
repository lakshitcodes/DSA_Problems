#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/    

class Solution {
    public:
        int lenOfVDiagonal(vector<vector<int>>& grid) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
            
            int n = grid.size(), m = grid[0].size();
            int dp[n][m][4];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                    dp[i][j][2] = 0;
                    dp[i][j][3] = 0;
                    if(grid[i][j] == 0 || grid[i][j] == 2){
                        int tempi = i, tempj = j;
                        int next = (grid[i][j])%4;
                        int ans = 0;
                        // down right
                        while(tempi < n && tempj < m && grid[tempi][tempj] == next){
                            ans++;
                            next = (grid[tempi][tempj] + 2)%4;
                            tempi++;
                            tempj++;
                        }
                        dp[i][j][0] = ans;
                        tempi = i, tempj = j;
                        next = (grid[i][j])%4;
                        ans = 0;
                        // up right
                        while(tempi >= 0 && tempj < m && grid[tempi][tempj] == next){
                            ans++;
                            next = (grid[tempi][tempj] + 2)%4;
                            tempi--;
                            tempj++;
                        }
                        dp[i][j][1] = ans;
                        tempi = i, tempj = j;
                        next = (grid[i][j] )%4;
                        ans = 0;
                        // down left
                        while(tempi < n && tempj >= 0 && grid[tempi][tempj] == next){
                            ans++;
                            next = (grid[tempi][tempj] + 2)%4;
                            tempi++;
                            tempj--;
                        }
                        dp[i][j][2] = ans;
                        tempi = i, tempj = j;
                        next = (grid[i][j])%4;
                        ans = 0;
                        // up left
                        while(tempi >= 0 && tempj >= 0 && grid[tempi][tempj] == next){
                            ans++;
                            next = (grid[tempi][tempj] + 2)%4;
                            tempi--;
                            tempj--;
                        }
                        dp[i][j][3] = ans;
                    }
                }
            }
            // dr 0 ur 1 dl 2 ul 3
            int ans = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j] == 1){
                        int next = 2;
                        int tempi = i+1, tempj = j+1;
                        int maxi = 0;
                        int curr = 0;
                        // down right -> ur, dl
                        while(tempi < n && tempj < m && grid[tempi][tempj] == next){
                            curr++;
                            if(tempi + 1 < n && tempj-1 >= 0 && grid[tempi+1][tempj-1] == ((next+2)%4)){
                                maxi = max(maxi, curr + dp[tempi+1][tempj-1][2]);
                            }
                            maxi = max(maxi, curr);
                            next = (next+2)%4;
                            tempi++; tempj++;
                        }
                        
                        // ur -> ul, dr
                        curr = 0; tempi = i-1; tempj = j+1; next = 2;
                        while(tempi >= 0 && tempj < m && grid[tempi][tempj] == next){
                            curr++;
                            if(tempi + 1 < n && tempj+1 < m && grid[tempi+1][tempj+1] == ((next+2)%4)){
                                maxi = max(maxi, curr + dp[tempi+1][tempj+1][0]);
                            }
                            maxi = max(maxi, curr);
                            next = (next+2)%4;
                            tempi--; tempj++;
                        }
                        // ul -> ur, dl
                        curr = 0; tempi = i-1; tempj = j-1; next = 2;
                        while(tempi >= 0 && tempj >= 0 && grid[tempi][tempj] == next){
                            curr++;
                            if(tempi - 1 >= 0 && tempj+1 < m && grid[tempi-1][tempj+1] == ((next+2)%4)){
                                maxi = max(maxi, curr + dp[tempi-1][tempj+1][1]);
                            }
                            maxi = max(maxi, curr);
                            next = (next+2)%4;
                            tempi--; tempj--;
                        }
                        // dl -> ul, dr
                        curr = 0; tempi = i+1; tempj = j-1; next = 2;
                        while(tempi < n && tempj >= 0 && grid[tempi][tempj] == next){
                            curr++;
                            if(tempi - 1 >= 0 && tempj-1 >= 0 && grid[tempi-1][tempj-1] == ((next+2)%4)){
                                maxi = max(maxi, curr + dp[tempi-1][tempj-1][3]);
                            }
                            maxi = max(maxi, curr);
                            next = (next+2)%4;
                            tempi++; tempj--;
                        }
                        ans = max(ans, maxi+1);
                        // cout<<ans<<" and ";
                    }
                }
            }
            return ans;
        }
    };