#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/set-matrix-zeroes/

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            unordered_set<int> rows,cols;
            int m=matrix.size();
            int n=matrix[0].size();
    
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==0){
                        rows.insert(i);
                        cols.insert(j);
                    }
                }
            }
    
            for(auto &i : rows){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
            for(auto &i : cols){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
    };