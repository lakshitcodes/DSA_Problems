#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/find-missing-and-repeated-values/

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int n=grid.size()*grid.size();
            long long sum=n*(n+1)/2;
            long long sq=(long long)n*(long long)(n+1)*(2*(long long)n+1LL)/6LL;
            long long gSum=0;
            long long sqSum=0;
            for(auto &i : grid){
                for(int j : i){
                    gSum+=j;
                    sqSum+=j*j;
                }
            }
            sum-=gSum;
            sq-=sqSum;
            sq/=sum;
            return {(int)(sq-sum)/2,(int)(sq+sum)/2};
        }
    };