#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-matrix-sum/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans = 0 ;
        int count = 0;
        int largestMin = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans+=abs(matrix[i][j]);
                largestMin=min(largestMin,abs(matrix[i][j]));
                if(matrix[i][j]<0){
                    count++;
                }
            }
        }
        if(count%2){
            ans-=2*largestMin;
        }
        return ans;
    }
};