#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    bool isPossible(vector<int> &nums,int maxOp,int mid){
        int req=0;
        for(int num : nums)
            req += (num - 1) / mid;
        return req<=maxOp;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1,r=nums[n-1];
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isPossible(nums,maxOperations,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};