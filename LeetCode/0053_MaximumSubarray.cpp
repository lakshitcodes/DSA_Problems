#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-subarray/

class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(NULL);
    
            int currSum=0;
            int maxSum=nums[0];
            for(auto &i : nums){
                currSum+=i;
                maxSum=max(currSum,maxSum);
                if(currSum<0){
                    currSum=0;
                }
            }
            return maxSum;
        }
    };