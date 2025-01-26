#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-frequency-after-subarray-operation/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long totalK=0;
        for(auto &i : nums){
            if(i==k){
                totalK++;
            }
        }

        int maxFreq=0;
        for(int i=1;i<=50;i++){
            if(i==k){
                continue;
            }
            int curr=0;
            int maxi=0;
            for(auto &ele : nums){
                if(ele==i){
                    curr++;
                }
                if(ele==k){
                    curr--;
                }
                maxi=max(maxi,curr);
                if(curr<0){
                    curr=0;
                }
            }
            maxFreq=max(maxFreq,maxi);
        }
        return totalK+maxFreq;
    }
};