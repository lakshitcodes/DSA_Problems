#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int ans=0;
        for(int i=0;i<=24;i++){
            long long currSet = 1<<i;
            int count=0;
            for(auto &c : candidates){
                if(currSet&c){
                    count++;
                }
            }
            ans=max(ans,count);
        }
        return ans;
    }
};