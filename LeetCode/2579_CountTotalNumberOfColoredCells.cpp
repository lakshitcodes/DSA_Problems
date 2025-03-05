#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/count-total-number-of-colored-cells/

class Solution {
    public:
        long long coloredCells(int n) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            long long ans=2*n-1;
            for(int i=2*n-3;i>=1;i-=2){
                ans+=2*i;
            }
            return ans;
        }
    };