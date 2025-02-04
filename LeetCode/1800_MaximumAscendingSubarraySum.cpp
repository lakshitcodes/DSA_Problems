#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-ascending-subarray-sum/

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        int currSum=nums[0];
        int maxSum=currSum;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currSum+=nums[i];
                maxSum=max(maxSum,currSum);
            }
            else{
                maxSum=max(maxSum,currSum);
                currSum=nums[i];
            }
        }
        return maxSum;
    }
};