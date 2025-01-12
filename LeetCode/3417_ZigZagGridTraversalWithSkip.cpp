#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/zigzag-grid-traversal-with-skip/

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        vector<int> ans;
        bool valid=true;
        bool direction=true;
        for(int i=0;i<grid.size();i++){
            if(direction){
                for(int j=0;j<grid[0].size();j++){
                    if(valid){
                        ans.push_back(grid[i][j]);
                    }
                    valid=!valid;
                }
            }
            else{
                for(int j=grid[0].size()-1;j>=0;j--){
                    if(valid){
                        ans.push_back(grid[i][j]);
                    }
                    valid=!valid;
                }
            }
            direction=!direction;
        }
        return ans;
    }
};