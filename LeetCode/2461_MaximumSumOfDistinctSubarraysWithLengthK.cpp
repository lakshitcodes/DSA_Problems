#include <bits/stdc++.h>
using namespace std;

//Question Link : https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);

        long long ans=0;
        long long currSum=0;
        map<int,int> s;
        int l=0,r=0;
        while(r<nums.size()){
            while(r<nums.size() && s.find(nums[r])==s.end() && r-l+1<=k){
                currSum+=nums[r];
                cout<<currSum<<" "<<l<<" "<<r<<endl;
                s[nums[r]]=r;
                r++;
            }
            if(r-l==k){
                ans=max(currSum,ans);
                currSum-=nums[l];
                s.erase(nums[l]);
                l++;
            }
            else if(r!=nums.size()){
                l=s[nums[r]]+1;
                s.clear();
                r=l;
                currSum=0;
            }
        }
        cout<<currSum<<" "<<l<<" "<<r<<endl;
        if(r-l==k){
            ans=max(ans,currSum);
        }
        return ans;
    }
};