#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/longest-strictly-increasing-or-decreasing-subarray/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        
        int decLength=1;
        int currLength=1;
        int incLength=1;
        int curr=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                currLength++;
            }
            else{
                decLength=max(decLength,currLength);
                currLength=1;
            }
            if(nums[i-1]>nums[i]){
                curr++;
            }
            else{
                
                incLength=max(incLength,curr);
                curr=1;
            }
        }
        incLength=max(incLength,curr);
        decLength=max(decLength,currLength);
        return max(incLength,decLength);
    }
};