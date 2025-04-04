#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/rotate-image/

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n=matrix.size();
    
            // Transpose
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
    
            // Reversing the cols
            for(int i=0;i<n;i++){
                for(int j=0;j<n/2;j++){
                    swap(matrix[i][j],matrix[i][n-j-1]);
                }
            }
        }
    };