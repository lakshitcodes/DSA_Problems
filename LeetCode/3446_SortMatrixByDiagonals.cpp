#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/sort-matrix-by-diagonals/

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int> curr;
            
            int row=n-1-i;
            int col=0;
            while(row<n && col<n){
                curr.push_back(grid[row][col]);
                row++;col++;
            }
            sort(curr.rbegin(),curr.rend());
            row=n-1-i;
            col=0;
            int idx=0;
            while(row<n && col<n){
                grid[row][col]=curr[idx++];
                row++;col++;
            }
        }
        for(int i=1;i<n;i++){
            vector<int> curr;
            int row=0;
            int col=i;
            while(row<n && col<n){
                curr.push_back(grid[row][col]);
                row++;col++;
            }
            sort(curr.begin(),curr.end());
            row=0;
            col=i;
            int idx=0;
            while(row<n && col<n){
                grid[row][col]=curr[idx++];
                row++;col++;
            }
        }
        return grid;
    }
};